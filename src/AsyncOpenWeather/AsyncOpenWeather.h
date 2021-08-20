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
 * @brief Structure that contains current weather data from OpenWeatherMap
 * 
 */
struct WeatherData
{
  String description;
  String weather;
  uint16_t id;
  uint8_t feels_like;
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

  /** Current weather data as updated from OWM */
  WeatherData currentWeather;

public:
  AsyncOpenWeather(String apiKey, String city);
  ~AsyncOpenWeather();

  WeatherData *getCurrentWeather();
  void Update();
};

#endif