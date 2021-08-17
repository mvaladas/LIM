#include "AppManager.h"
#include "Application/Application.h"
#include "TransitionEffect/HorizontalEffect/HorizontalEffect.h"

AppManager::AppManager()
{
}

AppManager::~AppManager()
{
}

void AppManager::AddApplication(Application *app)
{
    apps.push_back(app);
}

void AppManager::Begin()
{
    for (auto &&app : apps)
    {
        app->Begin();
    }
    currentAppIdx = 0;
}

void AppManager::Update()
{
    // If there is an effect reference, we are cycling apps
    if(this->currentEffect != nullptr)
    {
        this->currentEffect->Update();
        // Remove the effect if it's stopped running
        if(!this->currentEffect->IsRunning())
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
    if(enableAutoCycle)
    {
     if((millis() - lastCycleMillis >= autoCycleDuration) && currentEffect == nullptr)
     {
         AppTransition(TRANSITION_FORWARD);
         lastCycleMillis = millis();
     }   
    }
}

uint8_t AppManager::calculateCycleApp(TransitionDirection direction)
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

void AppManager::AppTransition(TransitionDirection direction)
{
    // Calculate the transition app. The app that's going to replace the current one
    nextAppIdx = calculateCycleApp(direction);

// can't transition into itself.
if(nextAppIdx == currentAppIdx) {
    return;
}
    // Create an effect instance
    // TODO: make this more generic. Effects should be configurable
    this->currentEffect = new HorizontalEffect(apps[currentAppIdx], apps[nextAppIdx],direction,32);
    this->currentEffect->Begin();
}