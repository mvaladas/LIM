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
void LimMatrix::drawRGB24Bitmap(int16_t x, int16_t y, const uint32_t *bitmap,
                                int16_t w, int16_t h)
{
    startWrite();
    for (int16_t j = 0; j < h; j++, y++)
    {
        for (int16_t i = 0; i < w; i++)
        {
            uint32_t word = pgm_read_dword(&bitmap[j * w + i]);

            this->drawPixel(x + i, y, Color24to16(word));
            //this->drawPixel(x + i, y, word);
        }
    }
    endWrite();
}

/**
 * @brief Draw an animated sprite. Frame animation calculated automatically based on millis()
 * 
 * @param progmem_data PROGMEM pointer to data
 * @param fps FPS of sprite animation
 * @param frame_count Frame count of sprite
 * @param offsetX X offset to display sprite
 * @param offsetY y offset to display sprite
 * @param width spirte width
 * @param height sprite height
 */
void LimMatrix::drawSprite(const uint32_t *progmem_data, uint16_t fps, uint16_t frame_count,
                           uint16_t offsetX, uint16_t offsetY, uint16_t width, uint16_t height)
{
    uint16_t currentFrameIdx = (int16_t)(millis() * fps / 1000.0) % frame_count;
    this->drawRGB24Bitmap(offsetX, offsetY, progmem_data + currentFrameIdx * width * height, width, height);
}