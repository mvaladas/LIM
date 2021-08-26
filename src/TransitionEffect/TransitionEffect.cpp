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
TransitionEffect::TransitionEffect(TransitionDirection direction)
: direction(direction), isRunning(false)
{
}

/**
 * @brief Is the transition effect currently running?
 * 
 * @return true if the effect is running
 * @return false if the effect has finished
 */
bool TransitionEffect::IsRunning()
{
    return isRunning;
}

void TransitionEffect::setApps(Application* currentApp, Application* nextApp)
{
    this->currentApp = currentApp;
    this->nextApp = nextApp;
}
