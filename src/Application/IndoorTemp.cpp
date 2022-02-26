/**
 * @file IndoorTemp.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 17-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "IndoorTemp.h"
#include "Adafruit_HTU21DF.h"
#include "Fonts/TomThumbMod.h"
//#include "Sprites/Temp.h"

/**
 * @brief Construct a new Indoor Temp Object
 * 
 * @param matrix Drawing matrix where to draw the app
 */
IndoorTemp::IndoorTemp(LimMatrix *matrix) : Application(matrix)
{
}

/**
 * @brief Updates the weather data.
 * 
 */
void IndoorTemp::doUpdate()
{
}

/**
 * @brief Initialize the App
 * 
 */
void IndoorTemp::doBegin()
{
    // Update once at startup.
    this->doUpdate();
}

/**
 * @brief Draw the weather icon on the matrix
 * 
 */
void IndoorTemp::drawSprite()
{
    //matrix->drawSprite(&temp_data[0][0], TEMP_FPS, TEMP_FRAME_COUNT, this->offset_x, this->offset_y, TEMP_FRAME_WIDTH, TEMP_FRAME_HEIGHT);
}

/**
 * @brief Draw the Application on the matrix
 * 
 */
void IndoorTemp::draw()
{
    // Find the center of the text and draw it
    matrix->setCursor(this->offset_x + 10, 7 + this->offset_y);
    matrix->setFont(&TomThumb);
    matrix->setTextWrap(false);
    matrix->setTextColor(matrix->Color(255, 255, 255));
    int16_t x, y;
    uint16_t w, h;
    // Serial.println(htu.readTemperature());
    String str("htu.readTemperature()");
    matrix->getTextBounds(str, this->offset_x + 10, this->offset_y + 7, &x, &y, &w, &h);
    //TODO: investigate why getTextBounds is returning one more character in bounds.
    // That's why we subtract 4 to the width.
    uint16_t xPos = floor(8 + (23 - (w - 4)) / 2);
    matrix->setCursor(this->offset_x + xPos, 7 + this->offset_y);
    matrix->print(str);
    // Draw a single pixel for the degree symbol
    matrix->drawPixel(this->offset_x + xPos + w - 4, this->offset_y + 2, matrix->Color(255, 255, 255));

    // Draw the bitmap
    drawSprite();
}