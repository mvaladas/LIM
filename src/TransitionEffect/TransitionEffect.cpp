/**
 * @file TransitionEffect.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @version 0.1
 * @date 17-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "TransitionEffect.h"

/**
 * @brief Construct a new Transition Effect:: Transition Effect object
 * 
 * @param currentApp Currently displayed aplication
 * @param nextApp Application to transition
 * @param direction direction of transition
 */
TransitionEffect::TransitionEffect(Application *currentApp, Application *nextApp, TransitionDirection direction)
: currentApp(currentApp), nextApp(nextApp), direction(direction), isRunning(false)
{
}

/**
 * @brief Destroy the Transition Effect:: Transition Effect object
 * 
 */
TransitionEffect::~TransitionEffect()
{
}

bool TransitionEffect::IsRunning()
{
    return isRunning;
}