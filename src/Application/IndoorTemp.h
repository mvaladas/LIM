/**
 * @file IndoorTemp.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 17-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_INDOORTEMP
#define _H_INDOORTEMP

#include "Application/Application.h"
#include "LimMatrix/LimMatrix.h"
#include "ClosedCube_HDC1080.h"

/**
 * @brief Open Weather Map Application.
 * 
 */
class IndoorTemp: public Application
{

private:   
    
    ClosedCube_HDC1080 hdc1080;

    float temperature;
    float humidity;

    virtual void doUpdate();
    virtual void doBegin();
    virtual void draw();
    virtual void drawSprite();

public:
    IndoorTemp(LimMatrix* matrix);
};


#endif