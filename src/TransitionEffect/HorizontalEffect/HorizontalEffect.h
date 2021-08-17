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

class HorizontalEffect : public TransitionEffect
{
private:
    static const unsigned long HORIZONTAL_EFFECT_LENGTH = 1000;

    unsigned long transitionInterval = HORIZONTAL_EFFECT_LENGTH / 32;
    unsigned long lastCycleMillis = 0;
    uint8_t maxSteps;

public:
    HorizontalEffect(Application *currentApp, Application *nextApp, TransitionDirection direction, uint8_t steps);
    void Update();
    void Begin();
};

#endif