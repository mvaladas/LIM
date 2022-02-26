/**
 * @file OWMCurrentTemp.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief
 * @version 0.1
 * @date 17-08-212021
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "OWMCurrentTemp.h"
#include "AsyncOpenWeather/AsyncOpenWeather.h"
#include "Fonts/TomThumbMod.h"

#include "Sprites/Weather/Clear.h"
#include "Sprites/Weather/Cloudy.h"
#include "Sprites/Weather/Drizzle.h"
#include "Sprites/Weather/Mist.h"
#include "Sprites/Weather/Rain.h"
#include "Sprites/Weather/Snow.h"
#include "Sprites/Weather/Thunderstorm.h"
#include "LimMatrix/LimMatrix.h"

/**
 * @brief Construct a new Open Weather:: Open Weather object
 *
 * @param asyncOw reference to an AsyncOpenWeather instance
 * @param matrix Drawing matrix where to draw the app
 * @param apiKey OpenWeather Map API Key
 * @param city City to fetch weather data
 */
OWMCurrentTemp::OWMCurrentTemp(AsyncOpenWeather *asyncOW, LimMatrix *matrix) : Application(matrix), asyncOW(asyncOW)
{
}

/**
 * @brief Updates the weather data.
 *
 */
void OWMCurrentTemp::doUpdate()
{
    this->asyncOW->Update();
}

/**
 * @brief Initialize the App
 *
 */
void OWMCurrentTemp::doBegin()
{
    // Update once at startup.
    this->doUpdate();
    this->currentFrameIdx = 0;
}

/**
 * @brief Draw the weather icon on the matrix
 *
 */
void OWMCurrentTemp::drawSprite()
{

    uint16_t weatherId = asyncOW->getCurrentWeather()->id;
    unsigned long currentMillis = millis();

    // reset frame if a new icon is to be shown
    if (this->currentid != weatherId)
    {
        Serial.println("3");
        this->currentFrameIdx = 0;
        this->lastFrameTime = 0;
    }

    this->currentid = weatherId;

    Sprite* sprite;
    // See https://openweathermap.org/weather-conditions
    switch (currentid)
    {
    case 200 ... 299: // Group 2xx: Thunderstorm
        sprite = &Thunderstorm;
        break;
    case 300 ... 399: // Group 3xx: Drizzle
        sprite = &Drizzle;
        break;
    case 500 ... 599: // Group 5xx: Rain
        sprite = &Rain;
        break;
    case 600 ... 699: // Group 6xx: Snow
        sprite = &Snow;
        break;
    case 700 ... 799: // Group 7xx: Atmosphere
        sprite = &Mist;
        break;
    case 800: // 800: Clear
        sprite = &Clear;
        break;
    case 801 ... 899: // Group 8xx: Clouds
        sprite = &Cloudy;
        break;
    default:
        return;
    }

    if ((currentMillis - this->lastFrameTime) >= sprite->frameduration[currentFrameIdx])
    {
        if (++(this->currentFrameIdx) >= sprite->frameCount)
        {
            this->currentFrameIdx = 0;
        }
        this->lastFrameTime = currentMillis;
    }
    matrix->drawRGB24Bitmap(this->offset_x, this->offset_y, sprite->frames + (currentFrameIdx * sprite->width * sprite->height), sprite->width, sprite->height);
}

/**
 * @brief Draw the Application on the matrix
 *
 */
void OWMCurrentTemp::draw()
{
    // Find the center of the text and draw it
    matrix->setCursor(this->offset_x + 10, 7 + this->offset_y);
    matrix->setFont(&TomThumb);
    matrix->setTextWrap(false);
    matrix->setTextColor(matrix->Color(255, 255, 255));
    int16_t x, y;
    uint16_t w, h;
    String str(this->asyncOW->getCurrentWeather()->temp);
    matrix->getTextBounds(str, this->offset_x + 10, this->offset_y + 7, &x, &y, &w, &h);
    // TODO: investigate why getTextBounds is returning one more character in bounds.
    //  That's why we subtract 4 to the width.
    uint16_t xPos = floor(8 + (23 - (w - 4)) / 2);
    matrix->setCursor(this->offset_x + xPos, 7 + this->offset_y);
    matrix->print(str);
    // Draw a single pixel for the degree symbol
    matrix->drawPixel(this->offset_x + xPos + w - 4, this->offset_y + 2, matrix->Color(255, 255, 255));

    // Draw the bitmap
    drawSprite();
}