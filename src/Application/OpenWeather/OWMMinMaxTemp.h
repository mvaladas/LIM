/**
 * @file OWMMinMaxTemp.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief Declaration of OWMMinMaxTemp class
 * @version 0.1
 * @date 23-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_OWMMINMAXTEMP
#define _H_OWMMINMAXTEMP

#include "Application/Application.h"
#include "AsyncOpenWeather/AsyncOpenWeather.h"
#include "LimMatrix/LimMatrix.h"

class OWMMinMaxTemp : public Application
{
private:
    /** Reference to Async Open Weather instance */
    AsyncOpenWeather *asyncOW;
    
    /** Current sprite frame */
    uint16_t currentFrameIdx;

    /** When was the last frame drawn */
    unsigned long lastFrameTime;

    virtual void doUpdate();
    virtual void doBegin();
    virtual void draw();
    virtual void drawSprite();

public:
    OWMMinMaxTemp(AsyncOpenWeather *asyncOW, LimMatrix *matrix);
};

#endif