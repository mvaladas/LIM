/**
 * @file LimMatrix.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief Declaration of LimMatrix
 * @version 0.1
 * @date 19-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_LIMMATRIX
#define _H_LIMMATRIX

#include <FastLED_NeoMatrix.h>

/**
 * @brief Matrix class inheriting from FastLED Matrix. Contains specific implementation relevant for LIM.
 * 
 */
class LimMatrix : public FastLED_NeoMatrix
{

public:
    //Inherith constructors
    using FastLED_NeoMatrix::FastLED_NeoMatrix;

    void drawRGB24Bitmap(int16_t x, int16_t y, const uint32_t bitmap[],
                         int16_t w, int16_t h);

    void drawSprite(const uint32_t *progmem_data, uint16_t fps, uint16_t frame_count,
                    uint16_t offsetX, uint16_t offsetY, uint16_t width, uint16_t height);
};

#endif