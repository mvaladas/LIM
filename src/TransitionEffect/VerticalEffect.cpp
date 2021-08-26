/**
 * @file VerticalEffect.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 17-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "TransitionEffect/TransitionEffect.h"
#include "VerticalEffect.h"
#include "Application/Application.h"
#include <LimMatrix/LimMatrix.h>

/**
 * @brief Construct a new Horizontal Effect:: Horizontal Effect object
 * 
 * @param currentApp Reference to the currently displayed APP
 * @param nextApp Reference to the next app to display
 * @param direction Direction of the transition
 * @param width Width of the transition
 */
VerticalEffect::VerticalEffect(TransitionDirection direction, uint8_t steps) : TransitionEffect(direction), steps(steps), transitionInterval(VERTICAL_EFFECT_LENGTH / steps)
{
}

/**
 * @brief Initializes the transition
 * 
 */
void VerticalEffect::Begin()
{
    int8_t currX, currY;
    int8_t nextX, nextY;
    currentApp->getOffset(&currX, &currY);
    currentApp->getOffset(&nextX, &nextY);
    switch (direction)
    {
    case TRANSITION_FORWARD:
        currentApp->setOffset(currX, 0);
        nextApp->setOffset(nextX, steps + 2);
        break;
    case TRANSITION_BACKWARDS:
        currentApp->setOffset(currX, 0);
        nextApp->setOffset(nextX, -steps - 2);
        break;
    default:
        break;
    }
    isRunning = true;
}

/** * @brief Updates the transition effect by drawing whatever is needed. */
void VerticalEffect::Update()
{
    unsigned long currentTime = millis();
    unsigned long interval = currentTime - lastCycleMillis;
    int modifier = (this->direction == TRANSITION_FORWARD) ? -1 : 1;

    // Update App position
    if (interval >= transitionInterval)
    {
        currentApp->addOffset(0, modifier);
        nextApp->addOffset(0, modifier);
        int8_t x, y;
        nextApp->getOffset(&x, &y);
        if (y == 0)
        {
            // The Effect has ended
            this->isRunning = false;
        }
        lastCycleMillis = currentTime;
    }
    // Always draw both apps
    currentApp->Update();
    nextApp->Update();
}