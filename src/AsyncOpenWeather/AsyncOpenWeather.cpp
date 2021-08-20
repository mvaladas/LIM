/**
 * @file AsyncOpenWeather.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief Definition of  AsyncOpenWeather
 * @version 0.1
 * @date 20-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "AsyncOpenWeather.h"
#include <AsyncHTTPRequest_Generic.h>
#include <ArduinoJson.h>
#include <math.h>

/**
 * @brief Callback from AsynHTTPRequest once the HTTP call has been handled.
 * 
 * @param optParm Pointer to the current weather structure
 * @param request AsyncHTTPRequest reference
 * @param readyState Ready State
 */
void readyStateChangeCB(void *optParm, AsyncHTTPRequest *request, int readyState)
{
    auto currentWeather = (WeatherData *)optParm;

    // TODO recalculate this
    const size_t capacity = 2 * JSON_ARRAY_SIZE(1) + JSON_ARRAY_SIZE(2) + 6 * JSON_OBJECT_SIZE(1) + 3 * JSON_OBJECT_SIZE(2) + 2 * JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + 5 * JSON_OBJECT_SIZE(8) + 570;

    if (readyState == readyStateDone)
    {
        // Serial.println("\n**************************************");
        // Serial.println(request->responseText());
        // Serial.println("**************************************");

        // request->setDebug(false);

        DynamicJsonDocument doc(capacity);
        deserializeJson(doc, request->responseText());
        currentWeather->description = doc["weather"][0]["description"].as<String>();
        //currentWeather->weather = doc["weather"][0]["main"].as<String>();
        currentWeather->id = doc["weather"][0]["id"].as<double>();
        currentWeather->feels_like = roundf(doc["main"]["temp"].as<float>());
    }
}

/**
 * @brief Construct a new Async Open Weather:: Async Open Weather object
 * 
 * @param apiKey OpenWeatherMap API Key
 * @param city City to fetch weather of
 */
AsyncOpenWeather::AsyncOpenWeather(String apiKey, String city) : apiKey(apiKey), city(city)
{
    request.onReadyStateChange(readyStateChangeCB, &this->currentWeather);
    url = "/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";
}

/**
 * @brief Updates the current weather data by using the OpenWeatherMap API
 * 
 */
void AsyncOpenWeather::Update()
{
    static bool requestOpenResult;

    if (request.readyState() == readyStateUnsent || request.readyState() == readyStateDone)
    {
        String fullUrl = String("http://api.openweathermap.org/" + url).c_str();
        Serial.println(fullUrl);
        requestOpenResult = request.open("GET", fullUrl.c_str());

        if (requestOpenResult)
        {
            // Only send() if open() returns true, or crash
            request.send();
        }
        else
        {
            Serial.println("Can't send bad request");
        }
    }
    else
    {
        Serial.println("Can't send request");
    }
}

/**
 * @brief Returns a reference to the current weather data
 * 
 * @return WeatherData* current weather
 */
WeatherData *AsyncOpenWeather::getCurrentWeather()
{
    return &currentWeather;
}