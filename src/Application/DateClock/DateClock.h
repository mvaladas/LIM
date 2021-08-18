/**
 * @file DateClock.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief DateClock class declaration
 * @version 0.1
 * @date 18-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_DATECLOCK
#define _H_DATECLOCK

#include <stdint.h>
#include <Adafruit_NeoMatrix.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "Application/Application.h"

/**
 * @brief DateClock Application. Shows a clock with the current's month day. Time is fetch via NTP Server.
 */
class DateClock : public Application
{
private:
    /** Reference to the WifFiUDP used by the NTPClient */
    WiFiUDP *ntpUDP;
    /** NTP client that fetches the time from an NTP server */
    NTPClient *timeClient;

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