/**
 * @file AppContainer.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 18-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "AppContainer.h"
#include "Application/Application.h"
#include "TransitionEffect/TransitionEffect.h"
#include "TransitionEffect/HorizontalEffect.h"

/**
 * @brief Construct a new Lim Manager:: Lim Manager object
 * 
 */
AppContainer::AppContainer()
{
    // Setup a default transition effect
    this->currentEffect = new HorizontalEffect();
}

/**
 * @brief Adds an application to LIM
 * 
 * @param app reference to the application
 */
void AppContainer::AddApplication(Application *app)
{
    apps.push_back(app);
}

/**
 * @brief Initialize the LIM Manager. Calls all of the begin function of previously added apps.
 * 
 */
void AppContainer::Begin()
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
void AppContainer::Update()
{
    if (this->currentEffect->IsRunning())
    {
        this->currentEffect->Update();
        // Switch current app if the effect has stopped
        if (!this->currentEffect->IsRunning())
        {
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
        unsigned long currentMillis = millis();
        if ((currentMillis - lastCycleMillis >= autoCycleDuration) && !currentEffect->IsRunning())
        {
            AppTransition(TRANSITION_FORWARD);
            lastCycleMillis = currentMillis;
        }
    }
}

/**
 * @brief calculates the index of the next application to display
 * 
 * @param direction direction of the next applicaton
 * @return uint8_t index of the next application
 */
uint8_t AppContainer::calculateCycleApp(TransitionDirection direction)
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

void AppContainer::AppTransition(TransitionDirection direction)
{
    // Calculate the transition app. The app that's going to replace the current one
    nextAppIdx = calculateCycleApp(direction);

    // can't transition into itself.
    if (nextAppIdx == currentAppIdx)
    {
        return;
    }
    this->currentEffect->setApps(this->apps[currentAppIdx], this->apps[nextAppIdx]);
    this->currentEffect->Begin();
}

void AppContainer::setEffect(TransitionEffect* effect)
{
    if (this->currentEffect != nullptr)
    {
        delete this->currentEffect;
    }
    this->currentEffect = effect;
}

void AppContainer::doUpdate() {}
void AppContainer::doBegin() {}
void AppContainer::draw() {}

void AppContainer::setCycleDuration(unsigned long duration)
{
    this->autoCycleDuration = duration;
}

/**
     * @brief Set the X,Y offset of the application. (0,0) being the top, left pixel.
     * 
     * @param x offset in X
     * @param y offset in Y
     */
void AppContainer::setOffset(int8_t x, int8_t y)
{
    Application::setOffset(x,y);
    for (auto &&app : apps)
    {
        app->setOffset(x, y);
    }
}

/**
     * @brief Adds the passed parameters to the X,Y offset of the application
     * 
     * @param x value to add to the X offset
     * @param y value to add to the Y offset
     */
void AppContainer::addOffset(int8_t x, int8_t y)
{
    Application::addOffset(x,y);
    for (auto &&app : apps)
    {
        app->addOffset(x, y);
    }
}