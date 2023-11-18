/**
 * @file main.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief Main class that runs the SW loop of the ESP8266
 * @version 0.1
 * @date 18-08-212021
 *
 * @copyright Copyright (c) 2021
 *
 */

// Include Constants file if present, or load default values
#if __has_include("Constants.h")
#include "Constants.h"
#else
#define LED_PIN 4                   // Which pin is attached to the NeoPixels
#define WIFI_HOSTNAME "LIM-Hotspot" // Hotspot name for WifiManager
#define OWM_APIKEY "DEADBEEF"       // OSM API Key

/* Configuration of NTP */
#define MY_NTP_SERVER "europe.pool.ntp.org"

#define keyLeft D0
#define keyOk D4
#define keyRight D8
#endif

#include "Utils.h"

#include <stack>

#include "LimMatrix/LimMatrix.h"
#include <Arduino.h>
#include <AsyncHTTPRequest_Generic.h>
#include <DFMiniMp3.h>
#include <SoftwareSerial.h>
#include <TZ.h>
#include <WiFiManager.h>
#include <Wire.h>

#include "AppContainer.h"
#include "Application/DateClock/DateClock.h"
#include "Application/IndoorTemp.h"
#include "Application/Matrix/MatrixApp.h"
#include "Application/OpenWeather/OWMCurrentTemp.h"
#include "Application/OpenWeather/OWMMinMaxTemp.h"
#include "AsyncOpenWeather/AsyncOpenWeather.h"
#include "Service/ButtonManager.h"
#include "Service/SoundManager.h"
#include "Sprites/LIMLogo.h"
#include "TransitionEffect/VerticalEffect.h"

#define I2C_SDA D3
#define I2C_SCL D1

#define DEBUG true
#define Serial                                                                 \
  if (DEBUG)                                                                   \
  Serial

#ifdef LIM_FASTLED

// #define FASTLED_INTERRUPT_RETRY_COUNT 1
// #define FASTLED_ALLOW_INTERRUPTS 0

CRGB matrixleds[32 * 8];
LimMatrix matrix = LimMatrix(matrixleds, 32, 8, 1, 1,
                             NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
                                 NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG);
#elif LIM_NEOPIXELS
LimMatrix matrix = LimMatrix(32, 8, LED_PIN,
                             NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
                                 NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                             NEO_GRB + NEO_KHZ800);
#endif

// Globals
WiFiManager wifiManager;
std::stack<AppContainer> appStack;
ButtonManager btnmgn;

/**
 * @brief Create the Apps and load them in the Lim Manager.
 *
 */
void createApps() {
  Serial.println("Create Apps");
  // These never get deleted because there is no shutdown in the microprocessor.
  DateClock *clock = new DateClock(&matrix);
  // IndoorTemp *temp = new IndoorTemp(&matrix);

  AsyncOpenWeather *asyncOWM =
      new AsyncOpenWeather(OWM_APIKEY, "Darmstadt, DE");
  OWMCurrentTemp *owmTemp = new OWMCurrentTemp(asyncOWM, &matrix);
  OWMMinMaxTemp *owmMinMax = new OWMMinMaxTemp(asyncOWM, &matrix);
  AppContainer *owm = new AppContainer();
  owm->AddApplication(owmTemp);
  owm->AddApplication(owmMinMax);
  owm->setCycleDuration(10000);
  owm->setEffect(new VerticalEffect());
  MatrixApp *matrixapp = new MatrixApp(&matrix);

  AppContainer limManager = AppContainer();
  limManager.setEffect(new HorizontalEffect());
  limManager.setCycleDuration(20000);
  limManager.AddApplication(clock);
  // limManager.AddApplication(temp);
  limManager.AddApplication(owm);
  limManager.AddApplication(matrixapp);
  // limManager.AddApplication(owmTemp);

  limManager.Begin();
  appStack.push(limManager);
}

/**
 * @brief Base setup function. Runs once at HW initialization.
 *
 */
void setup() {
  // Initialize Serial
  Serial.setDebugOutput(true);
  Serial.setRxBufferSize(1024);
  Serial.begin(115200);
  // Serial.begin(9600);
  // Serial.println(EspClass::getSdkVersion());
  // Serial.end();

  // Configure touch buttons input mode
  Wire.begin(I2C_SDA, I2C_SCL);
  pinMode(keyLeft, INPUT_PULLUP);
  pinMode(keyRight, INPUT_PULLUP);
  pinMode(keyOk, INPUT_PULLUP);
  btnmgn.registerButton(keyLeft, false);
  btnmgn.registerButton(keyRight, false);

  // Initialize Matrix
#ifdef LIM_FASTLED
  FastLED.addLeds<NEOPIXEL, LED_PIN>(matrixleds, 32 * 8);
#endif

  matrix.begin();
  matrix.setBrightness(80); // Max 255
  matrix.clear();
  matrix.show(); // Clearing the screen is needed to show the logo after.

  // Boot display
  matrix.drawRGB24Bitmap(0, 0, LIMLogo.frames, 32, 8);
  // TODO: better/prettier boot display.
  matrix.show();

  // Init DFPlayer
  SoundManager::getInstance().Begin();
  SoundManager::getInstance().setVolume(75);
  SoundManager::getInstance().playMp3FolderTrack(1);

  // Start Wifi
  wifiManager.autoConnect("Clocky");
  // Config NTP Update parameters for the time library
  configTime(TZ_Europe_Berlin, MY_NTP_SERVER1, MY_NTP_SERVER2, MY_NTP_SERVER3);

  // Initialize LIM
  createApps();
}

/**
 * @brief Main SW loop.
 *
 */
void loop() {
  // Check for button presses
  btnmgn.checkButtons(&appStack.top());

  // Update the LED matrix.
  matrix.clear();
  // Update the app container at the top of the stack.
  appStack.top().Update();
  matrix.show();
}
