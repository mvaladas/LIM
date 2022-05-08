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

/**
 * @brief Construct a new Button Manager:: Button Manager object
 * 
 */
ButtonManager::ButtonManager()
{
}
/**
 * @brief Destroy the Button Manager:: Button Manager object
 * 
 */
ButtonManager::~ButtonManager()
{
}

/**
 * @brief Checks the button status and calls buttonEvent of the passed application
 * 
 * @param app The application to send button events to.
 */
void ButtonManager::checkButtons(Application *app)
{
    for (auto &item : buttons)
    {
        int value = digitalRead(item.second.pin);
        if (item.second.invert)
        {
            value = !value;
        }

        ButtonStatus newStatus = value == 0 ? NOT_PRESSED : PRESSED;
        uint8_t appEvt = updateButtonStatus(item.second, newStatus);
        if (appEvt > 0)
        {
            app->buttonEvent(appEvt);
        }
    }
}

/**
 * @brief Add a button to the button manager
 * 
 * @param pin pin ID of the button
 * @param invert true if the button is inverted
 */
void ButtonManager::registerButton(unsigned int pin, bool invert)
{
    ButtonInfo info;
    info.pin = pin;
    info.lastUpdate = millis();
    info.invert = invert;
    this->buttons.insert(std::pair<unsigned int, ButtonInfo>(pin, info));
}

/**
 * @brief returns the status of the button
 * 
 * @param pin pin ID of the button
 * @return the status of the button
 */
ButtonStatus ButtonManager::buttonStatus(unsigned int pin)
{
    return buttons[pin].status;
}

/**
 * @brief Updates the button status.
 * @details internal function to update the current button status.
 * It's used to make sure long presses are detected
 * 
 * @param button The button to upated
 * @param newStatus The new status of the button
 * @return int8_t 
 */
int8_t ButtonManager::updateButtonStatus(ButtonInfo &button, ButtonStatus newStatus)
{
    uint8_t appEvt = -1;
    if (newStatus == PRESSED && button.status == NOT_PRESSED)
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
    else if (newStatus == NOT_PRESSED && button.status == PRESSED)
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
    button.status = newStatus;
    return appEvt;
}