/**
 * @file LimManager.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 18-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "LimManager.h"
#include "Application/Application.h"
#include "TransitionEffect/HorizontalEffect/HorizontalEffect.h"

/**
 * @brief Construct a new Lim Manager:: Lim Manager object
 * 
 */
LimManager::LimManager()
{
}

/**
 * @brief Adds an application to LIM
 * 
 * @param app reference to the application
 */
void LimManager::AddApplication(Application *app)
{
    apps.push_back(app);
}

/**
 * @brief Initialize the LIM Manager. Calls all of the begin function of previously added apps.
 * 
 */
void LimManager::Begin()
{
    for (auto &&app : apps)
    {
        app->Begin();
    }
    currentAppIdx = 0;
}

/**
 * @brief LIM Manager Update Function. Should be called every loop.
 * 
 * @details The update function makes sure to call the update of the currently displayed app
 * or the update of the currently running transition effect. Will also trigger the application cycle if 
 * auto-cycle is enabled.
 */
void LimManager::Update()
{
    // If there is an effect reference, we are cycling apps
    if (this->currentEffect != nullptr)
    {
        this->currentEffect->Update();
        // Remove the effect if it's stopped running
        if (!this->currentEffect->IsRunning())
        {
            delete this->currentEffect;
            this->currentEffect = nullptr;
            currentAppIdx = nextAppIdx;
        }
    }
    else
    {
        apps[currentAppIdx]->Update();
    }

    //If autocycle is enabled
    if (enableAutoCycle)
    {
        if ((millis() - lastCycleMillis >= autoCycleDuration) && currentEffect == nullptr)
        {
            AppTransition(TRANSITION_FORWARD);
            lastCycleMillis = millis();
        }
    }
}

/**
 * @brief calculates the index of the next application to display
 * 
 * @param direction direction of the next applicaton
 * @return uint8_t index of the next application
 */
uint8_t LimManager::calculateCycleApp(TransitionDirection direction)
{
    int modifier = 0;
    switch (direction)
    {
    case TRANSITION_FORWARD:
        modifier = 1;
        break;
    case TRANSITION_BACKWARDS:
        modifier = -1;
        break;
    default:
        break;
    }
    if ((this->currentAppIdx + modifier) < 0)
    {
        return apps.size();
    }
    else if ((this->currentAppIdx + modifier) > (apps.size() - 1))
    {
        return 0;
    }
    else
    {
        return this->currentAppIdx + modifier;
    }
}

/**
 * @brief Starts the transition of applications in the given direction
 * 
 * @param direction direction of the transition
 */
void LimManager::AppTransition(TransitionDirection direction)
{
    // Calculate the transition app. The app that's going to replace the current one
    nextAppIdx = calculateCycleApp(direction);

    // can't transition into itself.
    if (nextAppIdx == currentAppIdx)
    {
        return;
    }
    // Create an effect instance
    // TODO: make this function more generic once more effects have been implemented.
    this->currentEffect = new HorizontalEffect(apps[currentAppIdx], apps[nextAppIdx], direction, 32);
    this->currentEffect->Begin();
}