/**
 * @file LimMatrix.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief definition of LimMatrix
 * @version 0.1
 * @date 19-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "LimMatrix.h"

/**************************************************************************/
/*!
   @brief   Draw a PROGMEM-resident 24-bit image (RGB 8/8/8) at the specified
   (x,y) position.
    @param    x   Top left corner x coordinate
    @param    y   Top left corner y coordinate
    @param    bitmap  byte array with 24-bit color bitmap
    @param    w   Width of bitmap in pixels
    @param    h   Height of bitmap in pixels
*/
/**************************************************************************/
void LimMatrix::drawRGB24Bitmap(int16_t x, int16_t y, const uint32_t bitmap[],
                              int16_t w, int16_t h)
{
    startWrite();
    for (int16_t j = 0; j < h; j++, y++)
    {
        for (int16_t i = 0; i < w; i++)
        {
            uint32_t word = pgm_read_dword(&bitmap[j * w + i]);
            uint32_t color = (word & 0xFF000000) >> 24;
            color |= (word & 0x000000FF) << 24; // REd
            color |= (word & 0x0000FF00) << 8; // Green
            color |= (word & 0x00FF0000) >> 8; // bLue
            
            // Serial.print("X = ");
            // Serial.print(x + 1);
            // Serial.print(" Y = ");
            // Serial.print(y);
            // Serial.printf(" WORD = 0x%X\n", word);
            // Serial.printf(" COLOR = 0x%X\n", color);
            
            this->drawPixel(x + i, y, Color24to16(color >> 8));
            this->drawPixel(x + i + 8, y, color >> 8);
        }
    }
    endWrite();
}