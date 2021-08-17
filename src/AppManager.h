#ifndef _H_APPMANAGER
#define _H_APPMANAGER

#include "Application/Application.h"
#include "TransitionEffect/TransitionEffect.h"
#include <vector>

class AppManager
{
private:

    std::vector<Application*> apps;

    TransitionEffect* currentEffect;

    uint8 currentAppIdx;
    uint8 nextAppIdx;

    bool enableAutoCycle = true;
    unsigned long autoCycleDuration = 10000;
    unsigned long lastCycleMillis = 0;

    uint8_t calculateCycleApp(TransitionDirection direction);

public:
    AppManager();
    ~AppManager();

    void AddApplication(Application* app);
    void AppTransition(TransitionDirection direction);

    void Update();
    void Begin();
};

#endif