/**
 * @file OWMCurrentTemp.h
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
class OWMCurrentTemp: public Application
{

private:
    /** Reference to Async Open Weather instance */
    AsyncOpenWeather* asyncOW;
    
    /** Current weather Id, as per OWM */
    uint16_t currentid;

    /** Current sprite frame */
    uint16_t currentFrameIdx;

    /** When was the last frame drawn */
    unsigned long lastFrameTime;
    
    virtual void doUpdate();
    virtual void doBegin();
    virtual void draw();
    virtual void drawSprite();

public:
    OWMCurrentTemp(AsyncOpenWeather* asyncOW, LimMatrix* matrix);
};


#endif