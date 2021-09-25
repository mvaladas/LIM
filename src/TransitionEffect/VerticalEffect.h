/**
 * @file VerticalEffect.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 17-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_VERTICALEFFECT
#define _H_VERTICALEFFECT

#include "TransitionEffect/TransitionEffect.h"

/**
 * @brief Horizontal Transition Effect of Apps
 * 
 */
class VerticalEffect : public TransitionEffect
{
private:
    /** Length of time in millis for the transition */
    static const unsigned long VERTICAL_EFFECT_LENGTH = 250;
    /** How long between each transition step */
    unsigned long transitionInterval = VERTICAL_EFFECT_LENGTH / 8;
    /** Last time, in millis, the transition updated */
    unsigned long lastCycleMillis = 0;
    /** Number of steps the transition lasts */
    uint8_t steps;

public:
    VerticalEffect(TransitionDirection direction = TRANSITION_FORWARD, uint8_t steps = 8);
    void Update() override;
    void Begin() override;
};

#endif