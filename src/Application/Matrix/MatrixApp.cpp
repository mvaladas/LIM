/**
     * @file MatrixApp.cpp
     * @author Miguel Valadas (mvaladas@users.noreply.github.com)
     * @brief 
     * @version 0.1
     * @date 23-08-212021
     * 
     * @copyright Copyright (c) 2021
     * 
     */

#include "MatrixApp.h"
#include "Utils.h"

/**
     * @brief Initialize the Matrix App
     * 
     */
void MatrixApp::doBegin()
{
    this->updateInterval = 150;
    for (int i = 0; i < 32; i++)
    {
        positions[i] = rand() % 8;
    }
}

/**
     * @brief Update the Matrix App
     * 
     */
void MatrixApp::doUpdate()
{
    for (int i = 0; i < 32; i++)
    {
        positions[i] += (rand() % 2);
        if (positions[i] > 8 + 8)
            positions[i] = 0;
    }
}

/**
     * @brief draw the matrix app
     * 
     */
void MatrixApp::draw()
{
    uint16_t hue = 24576;
    uint8_t sat = 230;
    uint8_t level = 255;

    uint8 steps = 8;

    for (int i = 0; i < 32; i++)
    {
        if (positions[i] <= matrix->height() && positions[i] >= 0)
            matrix->drawPixel(offset_x + i, offset_y + positions[i], Utils::RGBto565(matrix->ColorHSV(hue, 50, level)));
        for (int j = 1; j < steps; j++)
            if (positions[i]-j <= matrix->height() && positions[i]-j >= 0)
                matrix->drawPixel(offset_x + i, offset_y + (positions[i] - j), Utils::RGBto565(matrix->ColorHSV(hue, sat, level - j * (250 / (steps - 1)))));
    }
}