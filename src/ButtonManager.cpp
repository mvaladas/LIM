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
#include "Constants.h" // for the key PINS

ButtonManager::ButtonManager(/* args */)
{
}

ButtonManager::~ButtonManager()
{
}

void ButtonManager::checkButtons()
{
    for (auto& item : buttons)
    {
        int value = digitalRead(item.second.pin);
        if (item.second.invert) {
            value = !value;
        }

        ButtonStatus currentStatus = value == 0 ? NOT_PRESSED : PRESSED;
        item.second.status = currentStatus;
    }
}

void ButtonManager::addButton(unsigned int pin, bool invert)
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