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
#endif

#include "Utils.h"

#include <LimMatrix/LimMatrix.h>
#include <WiFiManager.h>
#include "NTPUpdater.h"

#include "Application/DateClock/DateClock.h"
#include "Application/OpenWeather/OWMCurrentTemp.h"
#include "Application/OpenWeather/OWMMinMaxTemp.h"
#include "Application/Matrix/MatrixApp.h"
#include "AppContainer.h"
#include "AsyncOpenWeather/AsyncOpenWeather.h"
#include "TransitionEffect/VerticalEffect.h"

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
AppContainer limManager;

/**
 * @brief Create the Apps and load them in the Lim Manager.
 * 
 */
void createApps()
{
  // These never get deleted because there is no shutdown in the microprocessor.
  DateClock *clock = new DateClock(&matrix);

  AsyncOpenWeather *asyncOWM = new AsyncOpenWeather(OWM_APIKEY, "Darmstadt, DE");
  OWMCurrentTemp *owmTemp = new OWMCurrentTemp(asyncOWM, &matrix);
  OWMMinMaxTemp *owmMinMax = new OWMMinMaxTemp(asyncOWM, &matrix);
  AppContainer *owm = new AppContainer();
  //owm->AddApplication(owmTemp);
  owm->AddApplication(owmMinMax);
  owm->setCycleDuration(10000);
  owm->setEffect(new VerticalEffect());
  MatrixApp *matrixapp = new MatrixApp(&matrix);

  limManager.setEffect(new HorizontalEffect());
  limManager.setCycleDuration(20000);
  limManager.AddApplication(clock);
  limManager.AddApplication(owm);
  limManager.AddApplication(matrixapp);
}

/**
 * @brief Base setup function. Runs once at HW initialization.
 * 
 */
void setup()
{

  // Initialize Serial
  //Serial.begin(9600);
  //Serial.println(EspClass::getSdkVersion());
    Serial.end();

// Initialize Matrix
#ifdef LIM_FASTLED
  FastLED.addLeds<NEOPIXEL, LED_PIN>(matrixleds, 32 * 8);
#endif

  matrix.begin();
  matrix.setBrightness(255 * 0.30);
  matrix.clear();

  // Boot display
  // TODO: better/prettier boot display.
  matrix.print(F("boot"));
  matrix.show();

  // Start Wifi
  wifiManager.autoConnect("Clocky");

  // Start NTP Updater
  NTPSetup();

  // Initialize LIM
  createApps();
  limManager.Begin();
}

/**
 * @brief Main SW loop.
 * 
 */
void loop()
{
  matrix.clear();
  limManager.Update();
  matrix.show();
}
