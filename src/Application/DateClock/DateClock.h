/**
 * @file DateClock.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief DateClock class
 * @version 0.1
 * @date 18-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_DATECLOCK
#define _H_DATECLOCK

#include <stdint.h>
#include <time.h>
#include "Application/Application.h"

/**
 * @brief DateClock Application. Shows a clock with the current's month day.
 */
class DateClock : public Application
{
private:

    void drawCalendar();
    void drawClock();

    virtual void doUpdate();
    virtual void doBegin();
    virtual void draw();

public:
    using Application::Application;
    virtual ~DateClock();
};

#endif