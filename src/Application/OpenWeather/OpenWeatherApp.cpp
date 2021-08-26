/**
 * @file OpenWeatherApp.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 23-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "OpenWeatherApp.h"
#include "Application/Application.h"
#include "Application/OpenWeather/OWMCurrentTemp.h"
#include "Application/OpenWeather/OWMMinMaxTemp.h"
#include "AsyncOpenWeather/AsyncOpenWeather.h"

OpenWeatherApp::OpenWeatherApp(AsyncOpenWeather *asyncOW, LimMatrix *matrix) : Application(matrix), asyncOW(asyncOW)
{
}

OpenWeatherApp::~OpenWeatherApp()
{
    if (currentTempApp != nullptr)
        delete currentTempApp;
    if (minMaxApp != nullptr)
        delete minMaxApp;
}

void OpenWeatherApp::doBegin()
{
    if (currentTempApp != nullptr)
        delete currentTempApp;
    if (minMaxApp != nullptr)
        delete minMaxApp;

    currentTempApp = new OWMCurrentTemp(asyncOW, matrix);
    minMaxApp = new OWMMinMaxTemp(asyncOW, matrix);

    currentlyShown = currentTempApp;

    // Update if necessary;
    asyncOW->Update();
}

void OpenWeatherApp::doUpdate()
{
    // currentTempApp->Update();
    // minMaxApp->Update();
    this->asyncOW->Update();
}

void OpenWeatherApp::draw() {

}

void OpenWeatherApp::setFocus(boolean focus)
{
    this->forceFocus = true;
}