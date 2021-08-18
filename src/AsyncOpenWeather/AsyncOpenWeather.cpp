#include "AsyncOpenWeather.h"
#include <AsyncHTTPRequest_Generic.h>
#include <ArduinoJson.h>

void readyStateChangeCB(void *optParm, AsyncHTTPRequest *request, int readyState)
{
    auto currentWeather = (WeatherData *)optParm;

    // TODO recalculate this
    const size_t capacity = 2 * JSON_ARRAY_SIZE(1) + JSON_ARRAY_SIZE(2) + 6 * JSON_OBJECT_SIZE(1) + 3 * JSON_OBJECT_SIZE(2) + 2 * JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + 5 * JSON_OBJECT_SIZE(8) + 570;

    if (readyState == readyStateDone)
    {
        //     Serial.println("\n**************************************");
        //     Serial.println(request->responseText());
        //     Serial.println("**************************************");

        //     request->setDebug(false);
        // }

        DynamicJsonDocument doc(capacity);
        deserializeJson(doc, request->responseText());

        currentWeather->description = doc["weather"][0]["description"].as<String>();
        currentWeather->weather = doc["weather"][0]["main"].as<String>();
        currentWeather->feels_like = doc["main"]["feels_like"].as<float>();
        // w->id = doc["list"][1]["weather"]["id"].as<int>();
        // w->current_Temp = doc["list"][1]["main"]["temp"].as<float>();
        // w->min_temp = doc["list"][1]["main"]["temp_min"].as<float>();
        // w->max_temp = doc["list"][1]["main"]["temp_max"].as<float>();
        // w->humidity = doc["list"][1]["main"]["temp_max"].as<float>();
        // if (w->id < 700)
        //     w->rain = doc["list"][1]["rain"]["3h"].as<float>();
        // else
        //     w->rain = 0;
    }
}

AsyncOpenWeather::AsyncOpenWeather(String apiKey, String city) : apiKey(apiKey), city(city)
{
    request.onReadyStateChange(readyStateChangeCB, &this->currentWeather);
    url = "/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";
}

AsyncOpenWeather::~AsyncOpenWeather()
{
}

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