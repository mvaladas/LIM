/**
 * @file OpenWeather.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 17-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "OpenWeather.h"
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
 * @param matrix Drawing matrix where to draw the app
 * @param apiKey OpenWeather Map API Key
 * @param city City to fetch weather data
 */
OpenWeather::OpenWeather(LimMatrix *matrix, String apiKey, String city) : Application(matrix)
{
    // There is only need to update the weather once every 5 minutes.
    // TODO: Make configurable
    this->updateInterval = 5 * 60 * 1000;
    this->asyncOW = new AsyncOpenWeather(apiKey, city);
}

/**
 * @brief Destroy the Open Weather:: Open Weather object
 * 
 */
OpenWeather::~OpenWeather()
{
    if (this->asyncOW != nullptr)
        delete this->asyncOW;
}

/**
 * @brief Updates the weather data.
 * 
 */
void OpenWeather::doUpdate()
{
    this->asyncOW->Update();
}

/**
 * @brief Initialize the App
 * 
 */
void OpenWeather::doBegin()
{
    // Update once at startup.
    this->doUpdate();
}

/**
 * @brief Draw the weather icon on the matrix
 * 
 */
void OpenWeather::drawSprite()
{

    uint16_t currentid = asyncOW->getCurrentWeather()->id;

    // See https://openweathermap.org/weather-conditions
    switch (currentid)
    {
    case 200 ... 299: //Group 2xx: Thunderstorm
        matrix->drawSprite(&thunderstorm_data[0][0], THUNDERSTORM_FPS, THUNDERSTORM_FRAME_COUNT, this->offset_x, this->offset_y, THUNDERSTORM_FRAME_WIDTH, THUNDERSTORM_FRAME_HEIGHT);
        break;
    case 300 ... 399: //Group 3xx: Drizzle
        matrix->drawSprite(&drizzle_data[0][0], DRIZZLE_FPS, DRIZZLE_FRAME_COUNT, this->offset_x, this->offset_y, DRIZZLE_FRAME_WIDTH, DRIZZLE_FRAME_HEIGHT);
        break;
    case 500 ... 599: //Group 5xx: Rain
        matrix->drawSprite(&rain_data[0][0], RAIN_FPS, RAIN_FRAME_COUNT, this->offset_x, this->offset_y, RAIN_FRAME_WIDTH, RAIN_FRAME_HEIGHT);
        break;
    case 600 ... 699: //Group 6xx: Snow
        matrix->drawSprite(&snow_data[0][0], SNOW_FPS, SNOW_FRAME_COUNT, this->offset_x, this->offset_y, SNOW_FRAME_WIDTH, SNOW_FRAME_HEIGHT);
        break;
    case 700 ... 799: //Group 7xx: Atmosphere
        matrix->drawSprite(&mist_data[0][0], MIST_FPS, MIST_FRAME_COUNT, this->offset_x, this->offset_y, MIST_FRAME_WIDTH, MIST_FRAME_HEIGHT);
        break;
    case 800: // 800: Clear
        matrix->drawSprite(&clear_data[0][0], CLEAR_FPS, CLEAR_FRAME_COUNT, this->offset_x, this->offset_y, CLEAR_FRAME_WIDTH, CLEAR_FRAME_HEIGHT);
        break;
    case 801 ... 899: //Group 8xx: Clouds
        matrix->drawSprite(&cloudy_data[0][0], CLOUDY_FPS, CLOUDY_FRAME_COUNT, this->offset_x, this->offset_y, CLOUDY_FRAME_WIDTH, CLOUDY_FRAME_HEIGHT);
        break;
    default:
        break;
    }
}

/**
 * @brief Draw the Application on the matrix
 * 
 */
void OpenWeather::draw()
{

    // Find the center of the text and draw it
    matrix->setCursor(this->offset_x + 10, 7 - this->offset_y);
    matrix->setFont(&TomThumb);
    matrix->setTextWrap(false);
    matrix->setTextColor(matrix->Color(255, 255, 255));
    int16_t x, y;
    uint16_t w, h;
    String str(this->asyncOW->getCurrentWeather()->feels_like);
    matrix->getTextBounds(str, this->offset_x + 10, this->offset_y + 7, &x, &y, &w, &h);
    //TODO: investigate why getTextBounds is returning one more character in bounds.
    // That's why we subtract 4 to the width.
    uint16_t xPos = floor(8 + (23 - (w - 4)) / 2);
    matrix->setCursor(this->offset_x + xPos, 7 - this->offset_y);
    matrix->print(str);
    // Draw a single pixel for the degree symbol
    matrix->drawPixel(this->offset_x + xPos + w - 4, this->offset_y + y, matrix->Color(255, 255, 255));

    // Draw the bitmap
    drawSprite();
}