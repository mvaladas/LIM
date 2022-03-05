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

#ifdef LIM_FASTLED
#include <FastLED_NeoMatrix.h>
#elif LIM_NEOPIXELS
#include <Adafruit_NeoMatrix.h>
#endif

/**
 * @brief Matrix class inheriting from FastLED Matrix. Contains specific implementation relevant for LIM.
 *
 */
#ifdef LIM_FASTLED
class LimMatrix : public FastLED_NeoMatrix
#elif LIM_NEOPIXELS
class LimMatrix : public Adafruit_NeoMatrix
#endif
{

public:
    // Inherith constructors
#ifdef LIM_FASTLED
    using FastLED_NeoMatrix::FastLED_NeoMatrix;
#elif LIM_NEOPIXELS
    using Adafruit_NeoMatrix::Adafruit_NeoMatrix;
#endif

    void drawRGB24Bitmap(int16_t x, int16_t y, const uint32_t bitmap[],
                         int16_t w, int16_t h);
};

#endif