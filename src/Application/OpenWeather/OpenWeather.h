/**
 * @file OpenWeather.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 17-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_OPENWEATHER
#define _H_OPENWEATHER

#include "Application/Application.h"

class OpenWeather: public Application
{
private:
    virtual void doUpdate();
    virtual void doBegin();
    virtual void draw();

public:
    OpenWeather(Adafruit_NeoMatrix* matrix);
    virtual ~OpenWeather();
};




#endif