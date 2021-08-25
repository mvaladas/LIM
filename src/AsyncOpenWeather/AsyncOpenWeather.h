/**
 * @file AsyncOpenWeather.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief Asyncronous Open Weather Map API Calls
 * @version 0.1
 * @date 18-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_ASYNCOPENWEATHER
#define _H_ASYNCOPENWEATHER

#include <Arduino.h>
#include <AsyncHTTPRequest_Generic.h>

/**
 * @brief Type of update response received
 * 
 */
enum OWMUpdateType {
  OWM_CURRENT,
  OWM_FORECAST
};

/**
 * @brief Structure that contains current weather data from OpenWeatherMap
 * 
 */
struct WeatherData
{
  String description;
  String weather;
  uint16_t id;
  int8_t feels_like;
  int8_t temp;
  int8_t temp_min;
  int8_t temp_max;
};

/**
 * @brief Structure that contains weather data for the daily forecast
 * 
 */
struct Forecast
{
  int8_t temp_min;
  int8_t temp_max;
};

/**
 * @brief OpenWeatherMap Asynchronous Update class.
 * Retrives weather data from OWM asyncronously by means of the AsyncHTTPRequest library.
 * 
 */
class AsyncOpenWeather
{
private:
  /** OpenWeatherMap API Key */
  String apiKey;
  /** City to fetch data from */
  String city;
  /** Internal container for the API call URL */
  String url;
  /* Instance of AsyncHTTPRequest to handle asynchronous HTTP calls */
  AsyncHTTPRequest request;

  /** How long between querying the OWM API */
  unsigned long updateInterval = 5 * 60 * 1000;
  /** Last Update Time */
  unsigned long lastUpdateTime = 0;

  /** Current weather data as updated from OWM */
  WeatherData currentWeather;

  /** Forcast weather data as updated from OWM */
  Forecast forecast;

  OWMUpdateType currentUpdate = OWM_CURRENT;

public:
  AsyncOpenWeather(String apiKey, String city);

  WeatherData *getCurrentWeather();
  Forecast *getCurrentForecast();
  OWMUpdateType getCurrentUpdate();
  void Update();
  void UpdateForeCast();
};

#endif