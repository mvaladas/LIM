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

#define keyLeft = D0;
#define keyOk = D4;
#define keyRight = D8;
#endif

#include "Utils.h"

#include "LimMatrix/LimMatrix.h"
#include <WiFiManager.h>
#include "NTPUpdater.h"
#include <Arduino.h>
#include <Wire.h>
#include <time.h>
#include <TZ.h>
#include <DFMiniMp3.h>
#include <SoftwareSerial.h>

#include <BME280_t.h>
#include "Adafruit_HTU21DF.h"
#include <Adafruit_BMP280.h>

#include "Application/DateClock/DateClock.h"
#include "Application/OpenWeather/OWMCurrentTemp.h"
#include "Application/OpenWeather/OWMMinMaxTemp.h"
#include "Application/Matrix/MatrixApp.h"
#include "Application/IndoorTemp.h"
#include "AppContainer.h"
#include "AsyncOpenWeather/AsyncOpenWeather.h"
#include "TransitionEffect/VerticalEffect.h"
#include "ButtonManager.h"

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
ButtonManager btmgn;

// instantiate temp sensor
BME280<> BMESensor;
Adafruit_BMP280 BMPSensor; // use I2C interface
Adafruit_HTU21DF htu = Adafruit_HTU21DF();

//DFPlayer
// forward declare the notify class, just the name
class Mp3Notify;
SoftwareSerial mySoftwareSerial(D7, D5); // RX, TX
typedef DFMiniMp3<SoftwareSerial, Mp3Notify> DfMp3;
DfMp3 dfmp3(mySoftwareSerial);

class Mp3Notify
{
public:
  static void PrintlnSourceAction(DfMp3_PlaySources source, const char *action)
  {
    if (source & DfMp3_PlaySources_Sd)
    {
      Serial.print("SD Card, ");
    }
    if (source & DfMp3_PlaySources_Usb)
    {
      Serial.print("USB Disk, ");
    }
    if (source & DfMp3_PlaySources_Flash)
    {
      Serial.print("Flash, ");
    }
    Serial.println(action);
  }
  static void OnError(DfMp3 &mp3, uint16_t errorCode)
  {
    // see DfMp3_Error for code meaning
    Serial.println();
    Serial.print("Com Error ");
    Serial.println(errorCode);
  }
  static void OnPlayFinished(DfMp3 &mp3, DfMp3_PlaySources source, uint16_t track)
  {
    Serial.print("Play finished for #");
    Serial.println(track);
  }
  static void OnPlaySourceOnline(DfMp3 &mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "online");
  }
  static void OnPlaySourceInserted(DfMp3 &mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "inserted");
  }
  static void OnPlaySourceRemoved(DfMp3 &mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "removed");
  }
};

/**
 * @brief Create the Apps and load them in the Lim Manager.
 * 
 */
void createApps()
{
  // These never get deleted because there is no shutdown in the microprocessor.
  DateClock *clock = new DateClock(&matrix);
  // IndoorTemp *temp = new IndoorTemp(&matrix);

  AsyncOpenWeather *asyncOWM = new AsyncOpenWeather(OWM_APIKEY, "Darmstadt, DE");
  OWMCurrentTemp *owmTemp = new OWMCurrentTemp(asyncOWM, &matrix);
  OWMMinMaxTemp *owmMinMax = new OWMMinMaxTemp(asyncOWM, &matrix);
  AppContainer *owm = new AppContainer();
  owm->AddApplication(owmTemp);
  owm->AddApplication(owmMinMax);
  owm->setCycleDuration(10000);
  owm->setEffect(new VerticalEffect());
  MatrixApp *matrixapp = new MatrixApp(&matrix);

  limManager.setEffect(new HorizontalEffect());
  limManager.setCycleDuration(20000);
  limManager.AddApplication(clock);
  // limManager.AddApplication(temp);
  limManager.AddApplication(owm);
  limManager.AddApplication(matrixapp);
  // limManager.AddApplication(owmTemp);
}

/**
 * @brief Base setup function. Runs once at HW initialization.
 * 
 */
void setup()
{
  delay(2000);

  // Initialize Serial
  Serial.setDebugOutput(true);
  //Serial.setRxBufferSize(1024);
	Serial.begin(115200);
  //Serial.begin(9600);
  //Serial.println(EspClass::getSdkVersion());
  // Serial.end();

  //Checking periphery
  // Wire.begin(I2C_SDA, I2C_SCL);
  // delay(1000);
	// if (BMESensor.begin())
	// {
  //   Serial.println("BME");
	// }
	// else if (htu.begin())
	// {
	// 	Serial.println("HTU");
	// }
	// else if (BMPSensor.begin(BMP280_ADDRESS_ALT) || BMPSensor.begin(BMP280_ADDRESS))
	// {
	// 	Serial.println("BMP");
	// } else 
  // {
  //   Serial.println("NONE!");
  // }

  // Init DFPlayer
  dfmp3.begin();
  dfmp3.setVolume(100);
  //dfmp3.playMp3FolderTrack(1);

  // Configure touch buttons input mode
  pinMode(keyLeft, INPUT_PULLUP);
  pinMode(keyRight, INPUT_PULLUP);
  pinMode(keyOk, INPUT_PULLUP);
  btmgn.addButton(keyLeft, false);
  btmgn.addButton(keyRight, false);

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
  configTime(TZ_Europe_Berlin, MY_NTP_SERVER);

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

  btmgn.checkButtons();

  if (btmgn.buttonStatus(keyRight) == ButtonStatus::PRESSED)
  {
    if (!limManager.isTransitioning())
    {
      dfmp3.playMp3FolderTrack(5);
      limManager.AppTransition(TransitionDirection::TRANSITION_FORWARD);
    }
  }

  if (btmgn.buttonStatus(keyLeft) == ButtonStatus::PRESSED)
  {
    if (!limManager.isTransitioning())
    {
      dfmp3.playMp3FolderTrack(5);
      limManager.AppTransition(TransitionDirection::TRANSITION_BACKWARDS);
    }
  }

  // Update the LED matrix.
  matrix.clear();
  limManager.Update();
  matrix.show();
}
