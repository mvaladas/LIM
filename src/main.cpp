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
  #define LED_PIN 4 // Which pin is attached to the NeoPixels
  #define WIFI_HOSTNAME "LIM-Hotspot" // Hotspot name for WifiManager
  #define OWM_APIKEY "DEADBEEF" // OSM API Key 
#endif
#include "Utils.h"

#include <Adafruit_NeoMatrix.h>
#include <WiFiManager.h>

#include "Application/DateClock/DateClock.h"
#include "LimManager.h"
#include "AsyncOpenWeather/AsyncOpenWeather.h"

// Globals
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, LED_PIN,
                                               NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
                                                   NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                                               NEO_GRB + NEO_KHZ800);
WiFiManager wifiManager;
LimManager limManager;

/**
 * @brief Create the Apps and load them in the Lim Manager.
 * 
 */
void createApps()
{
  // These never get deleted because there is no shutdown in the microprocessor.
  DateClock* clock = new DateClock(&matrix);
  limManager.AddApplication(clock);
}

/**
 * @brief Base setup function. Runs once at HW initialization.
 * 
 */
void setup()
{
  // Initialize Serial
  Serial.begin(9600);

  // Initialize Matrix
  matrix.begin();
  matrix.setBrightness(255 * 0.25);
  matrix.clear();

  // Boot display
  // TODO: better/prettier boot display.
  matrix.print(F("boot"));
  matrix.show();

  // Start Wifi
  wifiManager.autoConnect("Clocky");

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