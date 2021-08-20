/**
 * @file HorizontalEffect.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 17-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_HORIZONTALEFFECT
#define _H_HORIZONTALEFFECT

#include "TransitionEffect/TransitionEffect.h"

/**
 * @brief Horizontal Transition Effect of Apps
 * 
 */
class HorizontalEffect : public TransitionEffect
{
private:
    /** Length of time in millis for the transition */
    static const unsigned long HORIZONTAL_EFFECT_LENGTH = 1000;
    /** How long between each transition step */
    unsigned long transitionInterval = HORIZONTAL_EFFECT_LENGTH / 32;
    /** Last time, in millis, the transition updated */
    unsigned long lastCycleMillis = 0;
    /** Number of steps the transition lasts */
    uint8_t steps;

public:
    HorizontalEffect(Application *currentApp, Application *nextApp, TransitionDirection direction, uint8_t steps);
    void Update();
    void Begin();
};

#endif