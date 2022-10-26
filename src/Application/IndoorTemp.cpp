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
#include "Fonts/TomThumbMod.h"
#include "ClosedCube_HDC1080.h"

/**
 * @brief Construct a new Indoor Temp Object
 * 
 * @param matrix Drawing matrix where to draw the app
 */
IndoorTemp::IndoorTemp(LimMatrix *matrix) : Application(matrix)
{
    //this->updateInterval = 10000; // 10 sec update
}

/**
 * @brief Updates the weather data.
 * 
 */
void IndoorTemp::doUpdate()
{
    this->temperature = hdc1080.readTemperature();
    this->humidity = hdc1080.readHumidity();
      Serial.print("T= ");
  Serial.println(hdc1080.readTemperature());
  Serial.print("H= ");
  Serial.println(hdc1080.readHumidity());
}

/**
 * @brief Initialize the App
 * 
 */
void IndoorTemp::doBegin()
{
    hdc1080.begin(0x40);
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
    String str(this->temperature);
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