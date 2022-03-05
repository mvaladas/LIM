/**
 * @file ButtonManager.cpp
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @date 29-09-2021
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "ButtonManager.h"
#include "Arduino.h"
#include "Application/Application.h"
#include "Constants.h" // for the key PINS

ButtonManager::ButtonManager(/* args */)
{
}

ButtonManager::~ButtonManager()
{
}

void ButtonManager::checkButtons(Application *app)
{
    for (auto &item : buttons)
    {
        int value = digitalRead(item.second.pin);
        if (item.second.invert)
        {
            value = !value;
        }

        ButtonStatus currentStatus = value == 0 ? NOT_PRESSED : PRESSED;
        uint8_t appEvt = updateButtonStatus(item.second, currentStatus);
        if (appEvt > 0)
        {
            app->buttonEvent(appEvt);
        }
    }
}

void ButtonManager::registerButton(unsigned int pin, bool invert)
{
    ButtonInfo info;
    info.pin = pin;
    info.lastUpdate = millis();
    info.invert = invert;
    this->buttons.insert(std::pair<unsigned int, ButtonInfo>(pin, info));
}

ButtonStatus ButtonManager::buttonStatus(unsigned int pin)
{
    return buttons[pin].status;
}

int8_t ButtonManager::updateButtonStatus(ButtonInfo &button, ButtonStatus currentStatus)
{
    uint8_t appEvt = -1;
    if (currentStatus == PRESSED && button.status == NOT_PRESSED)
    {
        switch (button.pin)
        {
        case keyLeft:
            appEvt = BTN_LEFT_RELEASE;
            break;
        case keyRight:
            appEvt = BTN_RIGHT_RELEASE;
            break;
        case keyOk:
            appEvt = BTN_MIDDLE_RELEASE;
            break;
        default:
            break;
        }
    }
    else if (currentStatus == NOT_PRESSED && button.status == PRESSED)
    {
        switch (button.pin)
        {
        case keyLeft:
            appEvt = BTN_LEFT_PRESS;
            break;
        case keyRight:
            appEvt = BTN_RIGHT_PRESS;
            break;
        case keyOk:
            appEvt = BTN_MIDDLE_PRESS;
            break;
        default:
            break;
        }
    }
    button.status = currentStatus;
    return appEvt;
}