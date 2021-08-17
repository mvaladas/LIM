/**
 * @file Application.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @version 0.1
 * @date 16-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Application.h"
#include <Adafruit_NeoMatrix.h>

/**
    * @brief Construct a new Application object
    * 
    * @param matrix reference to an Adafruit_NeoMatrix
    * */
Application::Application(Adafruit_NeoMatrix *matrix) : matrix(matrix)
{
}

/** @brief Destroy the Application object */
Application::~Application()
{
}

/**
     * @brief Set the X,Y offset of the application. (0,0) being the top, left pixel.
     * 
     * @param x offset in X
     * @param y offset in Y
     */
void Application::setOffset(int8_t x, int8_t y)
{
    this->offset_x = x;
    this->offset_y = y;
}

/**
     * @brief Adds the passed parameters to the X,Y offset of the application
     * 
     * @param x value to add to the X offset
     * @param y value to add to the Y offset
     */
void Application::addOffset(int8_t x, int8_t y)
{
    this->offset_x += x;
    this->offset_y += y;
}

/**
 * @brief Returns values for the X,Y Offset
 * 
 * @param x return pointer to the value of the X offset
 * @param y return pointer to the value of the Y offset
 */
void Application::getOffset(int8_t* x, int8_t* y)
{
    *x = offset_x;
    *y = offset_x;
}

/**
     * @brief Set how far apart each call to doUpdate should be.
     * 
     * @param updateInterval interval in milliseconds
     */
void Application::setUpdateInterval(unsigned long updateInterval)
{
    this->updateInterval = updateInterval;
}

/**
     * @brief Initialization of Application. Should only be called once.
     * 
     */
void Application::Begin()
{
    this->doBegin();
}

/**
 * @brief Updates the application.
 * 
 * @details Updates makes sure that the doUpdate() function is called once every updateInterval, while draw() is called every time.
 */
void Application::Update()
{
    // Check if enough time has passed to call doUpdate
    if ((millis() - this->previousUpdate) >= this->updateInterval)
    {
        this->doUpdate();
        this->previousUpdate = millis();
    }

    // draw is always called
    this->draw();
}
