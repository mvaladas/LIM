/**
 * @file TransitionEffect.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @version 0.1
 * @date 17-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_TRANSITIONEFFECT
#define _H_TRANSITIONEFFECT

#include "Application/Application.h"
#include <LimMatrix/LimMatrix.h>

/**
 * @brief Direction of the transition.
 * 
 */
enum TransitionDirection
{
    TRANSITION_FORWARD,
    TRANSITION_BACKWARDS
};

/**
 * @brief Class defines a transition effect between two applications.
 */
class TransitionEffect
{
protected:
    /** Currently displayed application */
    Application *currentApp;
    /** Application to transition to */
    Application *nextApp;
    /** Transition direction */
    TransitionDirection direction;
    /** true if the effect is currently running */
    bool isRunning;

public:
    TransitionEffect(Application *currentApp, Application *nextApp, TransitionDirection direction);
    virtual ~TransitionEffect();

    bool IsRunning();

    virtual void Begin() = 0;
    virtual void Update() = 0;
};

#endif
