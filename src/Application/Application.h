/**
 * @file Application.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @version 0.1
 * @date 16-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_APPLICATION
#define _H_APPLICATION

#include <stdint.h>
#include <Adafruit_NeoMatrix.h>

/**
 * @brief Abstract class for any application.
 * 
 * @details All application should inherit from the Application abstract class.
 * It takes care of functionality generic to all applications like positioning and update intervals.
 * 
 * Application loops should go in the following order:
 * First a call to Begin() to initialize the applicaion. Calls doBegin
 * Then a call to Update(). calls do Update.
 * 
 * Update calls doUpdate and draw.
 * 
 * 
 */
class Application
{
protected:
    /** The display offset in the X axis */
    int8_t offset_x = 0;
    /** The display offset in the Y axis */
    int8_t offset_y = 0;

    /** Time, in milliseconds, when the last update occured. */
    unsigned long previousUpdate = 0;
    /** Interval, in milliseconds, for each app update */
    unsigned long updateInterval = 1000;

    /** Reference to the matrix that will draw the application */
    Adafruit_NeoMatrix *matrix;

    /** Abstract function to execute the acutal application update operations on specific class*/
    virtual void doUpdate() = 0;
    /** Abstract function to execute the acutal application begin operations on specific class*/
    virtual void doBegin() = 0;
    /** Abstract function to execute the acutal draw operations on specific class*/
    virtual void draw() = 0;

public:

    explicit Application(Adafruit_NeoMatrix *matrix);
    ~Application();

    void Update();
    void Begin();

    void getOffset(int8_t* x, int8_t* y);
    void setOffset(int8_t x, int8_t y);
    void addOffset(int8_t x, int8_t y);

    void setUpdateInterval(unsigned long updateInterval);
};

#endif
