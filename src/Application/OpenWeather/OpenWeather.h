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
#include "AsyncOpenWeather/AsyncOpenWeather.h"
#include "LimMatrix/LimMatrix.h"

/**
 * @brief Open Weather Map Application.
 * 
 */
class OpenWeather: public Application
{

private:
    /** Reference to Async Open Weather instance */
    AsyncOpenWeather* asyncOW;
    
    virtual void doUpdate();
    virtual void doBegin();
    virtual void draw();

public:
    OpenWeather(LimMatrix* matrix, String apiKey, String city);
    virtual ~OpenWeather();

    virtual void drawBitmap();
};


#endif