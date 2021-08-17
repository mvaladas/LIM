#ifndef _H_DATECLOCK
#define _H_DATECLOCK

#include <stdint.h>
#include <Adafruit_NeoMatrix.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "Application/Application.h"

class DateClock : public Application
{
private:
     WiFiUDP* ntpUDP;
     NTPClient* timeClient;

    void drawCalendar();
    void drawClock();

    virtual void doUpdate();
    virtual void doBegin();
    virtual void draw();

public:
    DateClock(Adafruit_NeoMatrix* matrix);
    ~DateClock();
};

#endif 