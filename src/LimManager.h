/**
 * @file LimManager.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 18-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_LIMMANAGER
#define _H_LIMMANAGER

#include "Application/Application.h"
#include "TransitionEffect/TransitionEffect.h"
#include <vector>

/**
 * @brief Main class for LIM. Takes care of all major functions of LIM.
 * 
 */
class LimManager
{
private:
    /** Vector of applications loaded */
    std::vector<Application*> apps;

    /** Reference to currently running transition effect */
    TransitionEffect* currentEffect;

    /** Index of the App currently displayed */
    uint8 currentAppIdx;
    /** Index of the next app to be displayed */
    uint8 nextAppIdx;

    /** Should apps cycle automatically? */
    bool enableAutoCycle = true;
    /** Default time, in milliseconds, and app should be displayed before the next one */
    unsigned long autoCycleDuration = 30000;
    /** Time of the last cycle */
    unsigned long lastCycleMillis = 0;

    uint8_t calculateCycleApp(TransitionDirection direction);

public:
    LimManager();

    void AddApplication(Application* app);
    void AppTransition(TransitionDirection direction);

    void Update();
    void Begin();
};

#endif