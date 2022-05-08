/**
 * @file ButtonManager.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @date 29-09-2021
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef _H_BUTTONMANAGER
#define _H_BUTTONMANAGER

#include <map>
#include <string>
#include "Application/Application.h"

/**
 * @brief Defines the status of the button press.
 * NOT_PRESSED - Button is not pressed
 * PRESSED - Button has been pressed
 * LONG_PRESS - Button has been pressed for a while
 */
enum ButtonStatus
{
  NOT_PRESSED = 0,
  PRESSED = 1,
  LONG_PRESS = 2
};

/**
 * @brief Structure to define each of the buttons current status
 * @param pin PIN number where the button is connected
 * @param lastUpdate last time the button status was changed
 * @param invert is the button hardware inverted (i.e. it reports pressed when not pressed). This is necessary for a specific button implementation.
 * @param status the current status of the button
 */
struct ButtonInfo
{
  unsigned int pin;
  unsigned long lastUpdate;
  bool invert;
  ButtonStatus status;
};

/**
 * @brief Button Manager class
 */
class ButtonManager
{
private:
  /** Map of all the buttons managed by the class **/
  std::map<unsigned int, ButtonInfo> buttons;

  int8_t updateButtonStatus(ButtonInfo &button, ButtonStatus currentStatus);

public:
  ButtonManager(/* args */);
  ~ButtonManager();

  void checkButtons(Application *app);
  void registerButton(unsigned int pin, bool invert);
  ButtonStatus buttonStatus(unsigned int pin);
};
#endif