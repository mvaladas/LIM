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
#include <AsyncHTTPRequest_Generic.hpp>
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
    Serial.println("readyStateChangeCB - Start");
    AsyncOpenWeather *asyncObj = (AsyncOpenWeather *)optParm;

Serial.println("readyStateChangeCB - 1");
    // TODO recalculate this
    const size_t capacity = 2 * JSON_ARRAY_SIZE(1) + JSON_ARRAY_SIZE(2) + 6 * JSON_OBJECT_SIZE(1) + 3 * JSON_OBJECT_SIZE(2) + 2 * JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + 5 * JSON_OBJECT_SIZE(8) + 570;

    if (readyState == readyStateDone)
    {
        Serial.println("readyStateChangeCB - 2");
        String response = request->responseText();
        // Serial.println("\n**************************************");
        // Serial.println(response);
        // Serial.println("**************************************");

        // request->setDebug(false);
        DynamicJsonDocument doc(capacity);
        DeserializationError err = deserializeJson(doc, response);
        Serial.println("readyStateChangeCB - 3");
        if (err == DeserializationError::Ok)
        {
            if (asyncObj->getCurrentUpdate() == OWM_CURRENT)
            {
                WeatherData *data = asyncObj->getCurrentWeather();
                data->description = doc["weather"][0]["description"].as<String>();
                // currentWeather->weather = doc["weather"][0]["main"].as<String>();
                data->id = doc["weather"][0]["id"].as<double>();
                data->temp = roundf(doc["main"]["temp"].as<float>());
                data->temp_min = roundf(doc["main"]["temp_min"].as<float>());
                data->temp_max = roundf(doc["main"]["temp_max"].as<float>());

                // Do the second request after this one:
                asyncObj->UpdateForeCast();
            }
            else if (asyncObj->getCurrentUpdate() == OWM_FORECAST)
            {
                Forecast *data = asyncObj->getCurrentForecast();
                data->temp_min = roundf(doc["list"][0]["temp"]["min"].as<float>());
                data->temp_max = roundf(doc["list"][0]["temp"]["max"].as<float>());
            }
        }
    }
    Serial.println("readyStateChangeCB - End");
}

/**
 * @brief Construct a new Async Open Weather:: Async Open Weather object
 * 
 * @param apiKey OpenWeatherMap API Key
 * @param city City to fetch weather of
 */
AsyncOpenWeather::AsyncOpenWeather(String apiKey, String city) : apiKey(apiKey), city(city)
{
    request.onReadyStateChange(readyStateChangeCB, this);
    url = "/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";
}

/**
 * @brief Updates the current weather data by using the OpenWeatherMap API
 * 
 */
void AsyncOpenWeather::Update()
{
    static bool requestOpenResult;
    unsigned long currentMillis = millis();
    if (lastUpdateTime == 0 || currentMillis - lastUpdateTime > updateInterval)
    {
        Serial.println("Update - 1");
        if (request.readyState() == readyStateUnsent || request.readyState() == readyStateDone)
        {
            String fullUrl = String("http://api.openweathermap.org/" + url).c_str();
            // Serial.println(fullUrl);
            requestOpenResult = request.open("GET", fullUrl.c_str());

            if (requestOpenResult)
            {
                this->currentUpdate = OWM_CURRENT;
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
        lastUpdateTime = currentMillis;
    }
}

void AsyncOpenWeather::UpdateForeCast()
{
    Serial.println("UpdateForeCast - Start");
    static bool requestOpenResult;
    unsigned long currentMillis = millis();
        if (request.readyState() == readyStateUnsent || request.readyState() == readyStateDone)
        {
            String fullUrl = String("http://api.openweathermap.org/data/2.5/forecast/daily?q=" + city + "&cnt=1&appid=" + apiKey + "&units=metric")
                                 .c_str();
            // Serial.println(fullUrl);
            requestOpenResult = request.open("GET", fullUrl.c_str());

            if (requestOpenResult)
            {
                this->currentUpdate = OWM_FORECAST;
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
        lastUpdateTime = currentMillis;
        Serial.println("UpdateForeCast - END");
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

/**
 * @brief Returns a reference to the current forecast data
 * 
 * @return Forecast* current forecast
 */
Forecast *AsyncOpenWeather::getCurrentForecast()
{
    return &forecast;
}

OWMUpdateType AsyncOpenWeather::getCurrentUpdate()
{
    return this->currentUpdate;
}