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

struct WeatherData {
  String description;
  String weather;
  float feels_like;
};

class AsyncOpenWeather
{
private:
  String apiKey;
  String city;
  String url;
  AsyncHTTPRequest request;

  WeatherData currentWeather;

public:
  AsyncOpenWeather(String apiKey, String city);
  ~AsyncOpenWeather();

  void Update();
};

#endif