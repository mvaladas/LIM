/**
 * @file OpenWeatherApp.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 23-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_OPENWEATHERAPP
#define _H_OPENWEATHERAPP

#include "Application/Application.h"
#include "Application/OpenWeather/OWMCurrentTemp.h"
#include "Application/OpenWeather/OWMMinMaxTemp.h"
#include "AsyncOpenWeather/AsyncOpenWeather.h"
#include "TransitionEffect/TransitionEffect.h"

/**
 * @brief OpenWeather App. Shows Current Temperate and Daily Min/Max.
 * 
 */
class OpenWeatherApp : public Application
{
private:
    /** Reference to Async Open Weather instance */
    AsyncOpenWeather* asyncOW;
    /** Reference to current temp app */
    OWMCurrentTemp* currentTempApp;
    /** Reference to minmax app */
    OWMMinMaxTemp* minMaxApp;

    TransitionEffect* currentEffect;

    Application* currentlyShown;
    
    unsigned long interval = 5000;

    void doUpdate() override;
    void doBegin() override;
    void draw() override;
    void setFocus(boolean focus) override;


public:
    OpenWeatherApp(AsyncOpenWeather *asyncOW, LimMatrix *matrix);
    ~OpenWeatherApp();
};


#endif