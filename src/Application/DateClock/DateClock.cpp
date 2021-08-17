#include "DateClock.h"
#include "Application/Application.h"
#include "utils.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <TimeLib.h>
#include <Fonts/Org_01.h>
#include <Fonts/Picopixel.h>
#include <Fonts/Tiny3x3a2pt7b.h>
#include "Fonts/TomThumbMod.h"

DateClock::DateClock(Adafruit_NeoMatrix *matrix) : Application(matrix)
{
}

DateClock::~DateClock()
{
  if (ntpUDP != nullptr)
  {
    delete ntpUDP;
  }
  if (timeClient != nullptr)
  {
    delete timeClient;
  }
}

void DateClock::doBegin()
{
  if (ntpUDP != nullptr)
  {
    delete ntpUDP;
  }
  if (timeClient != nullptr)
  {
    delete timeClient;
  }
  ntpUDP = new WiFiUDP();
  timeClient = new NTPClient(*ntpUDP, "europe.pool.ntp.org", 2 * 3600, 60000);
  timeClient->begin();
}
void DateClock::doUpdate()
{
  timeClient->update();
}

void DateClock::draw()
{
  this->drawCalendar();
  this->drawClock();
}

void DateClock::drawCalendar()
{
  int16_t x, y;
  uint16_t w, h;

  // Draw calendar icon
  matrix->fillRect(this->offset_x + 0, this->offset_y + 0, 9, 2, matrix->Color(255, 0, 0));
  matrix->fillRect(this->offset_x + 0, this->offset_y + 2, 9, 6, matrix->Color(255, 255, 255));

  auto daystr = String(day(timeClient->getEpochTime()));

  matrix->setFont(&Tiny3x3a2pt7b);
  matrix->setTextColor(matrix->Color(0, 0, 0));
  matrix->getTextBounds(daystr, 0, 5, &x, &y, &w, &h);
  matrix->setCursor(this->offset_x + 4 - (floor(w / 2)), this->offset_y + 5);
  matrix->print(daystr);
}

void DateClock::drawClock()
{
  unsigned long rawTime = timeClient->getEpochTime();
  unsigned long hours = hour(rawTime);
  String hoursStr = hours < 10 ? "0" + String(hours) : String(hours);

  unsigned long minutes = (rawTime % 3600) / 60;
  String minuteStr = minutes < 10 ? "0" + String(minutes) : String(minutes);

  String clockStr = hoursStr + ":" + minuteStr;

  matrix->setFont(&TomThumb);
  matrix->setTextWrap(false);
  matrix->setTextColor(matrix->Color(255, 255, 255));

  // Hours
  //matrix->getTextBounds(clockStr, 0, 5, &x, &y, &w, &h);
  matrix->setCursor(this->offset_x + 12, this->offset_y + 7);
  matrix->print(clockStr);
}
