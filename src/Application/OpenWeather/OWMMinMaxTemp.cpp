/**
 * @file OWMMinMaxTemp.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief definition of OWMMInMaxTemp
 * @version 0.1
 * @date 23-08-212021
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "OWMMinMaxTemp.h"
#include "AsyncOpenWeather/AsyncOpenWeather.h"
#include "Fonts/TomThumbMod.h"

#include "Sprites/Weather/LowTemp.h"
#include "Sprites/Weather/HighTemp.h"
#include "Sprites/Weather/DayNightTemp.h"

/**
 * @brief Construct a new OWMMinMaxTemp::OWMMinMaxTemp object
 *
 * @param asyncOw reference to an AsyncOpenWeather instance
 * @param matrix Drawing matrix where to draw the app
 * @param apiKey OpenWeather Map API Key
 * @param city City to fetch weather data
 */
OWMMinMaxTemp::OWMMinMaxTemp(AsyncOpenWeather *asyncOW, LimMatrix *matrix) : Application(matrix), asyncOW(asyncOW)
{
}

/**
 * @brief Updates the weather data.
 *
 */
void OWMMinMaxTemp::doUpdate()
{
    this->asyncOW->Update();
}

/**
 * @brief Initialize the App
 *
 */
void OWMMinMaxTemp::doBegin()
{
    this->lastFrameTime = 0;
    this->currentFrameIdx = 0;
    // Update once at startup.
    this->doUpdate();
}

/**
 * @brief Draw the weather icon on the matrix
 *
 */
void OWMMinMaxTemp::drawSprite()
{
}

/**
 * @brief Draw the Application on the matrix
 *
 */
void OWMMinMaxTemp::draw()
{
    auto currentWeather = this->asyncOW->getCurrentForecast();
    unsigned long currentMillis = millis();

    matrix->setTextWrap(false);
    matrix->setFont(&TomThumb);
    matrix->setTextColor(matrix->Color(255, 255, 255));

    const Sprite *sprite = &DayNightTemp;

    if ((currentMillis - this->lastFrameTime) >= sprite->frameduration[currentFrameIdx])
    {
        if (++(this->currentFrameIdx) >= sprite->frameCount)
        {
            this->currentFrameIdx = 0;
        }
        this->lastFrameTime = currentMillis;
    }
    matrix->drawRGB24Bitmap(this->offset_x, this->offset_y, sprite->frames + (currentFrameIdx * sprite->width * sprite->height), sprite->width, sprite->height);

    matrix->setCursor(this->offset_x + 6, 7 + this->offset_y);
    matrix->printf("%i", currentWeather->temp_max);
    // Draw a single pixel for the degree symbol
    int8_t pixelOffset = (currentWeather->temp_max >= 0 && currentWeather->temp_max < 10 ? 4 : 8);
    matrix->drawPixel(this->offset_x + 6 + pixelOffset, this->offset_y + 2, matrix->Color(255, 255, 255));

    // matrix->drawSprite(&lowtemp_data[0][0], LOWTEMP_FPS, LOWTEMP_FRAME_COUNT,
    // 32-7-8 + this->offset_x, this->offset_y, LOWTEMP_FRAME_WIDTH, LOWTEMP_FRAME_HEIGHT);

    matrix->setTextColor(matrix->Color(255, 255, 255));
    matrix->setCursor(this->offset_x + (32 - 9), 7 + this->offset_y);
    matrix->printf("%i", currentWeather->temp_min);
    // Draw a single pixel for the degree symbol
    pixelOffset = (currentWeather->temp_min >= 0 && currentWeather->temp_min < 10 ? 4 : 8);
    matrix->drawPixel(this->offset_x + (32 - 9) + pixelOffset, this->offset_y + 2, matrix->Color(255, 255, 255));
}