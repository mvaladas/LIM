/**
 * @file DateClock.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief DateClock class definition
 * @version 0.1
 * @date 18-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "DateClock.h"
#include "Application/Application.h"
#include "utils.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <TimeLib.h>
#include <Fonts/Tiny3x3a2pt7b.h>
#include "Fonts/TomThumbMod.h"

/**
 * @brief Destroy the Date Clock:: Date Clock object
 * 
 */
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

/**
 * @brief Initialize the application
 * 
 */
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

/**
 * @brief Updates the current time
 * 
 */
void DateClock::doUpdate()
{
  timeClient->update();
}

/** 
 * @brief draw all elements of the application on the matrix 
 * 
 * */
void DateClock::draw()
{
  this->drawCalendar();
  this->drawClock();
}

/**
 * @brief draw the calendar on the matrix
 * 
 */
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
  matrix->setCursor(this->offset_x + 4 - (floor(w / 2)), 5 - this->offset_y);
  matrix->print(daystr);
}

/**
 * @brief draw the clock on the matrix
 * 
 */
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
  matrix->setCursor(this->offset_x + 12, 7 - this->offset_y);
  matrix->print(clockStr);
}
