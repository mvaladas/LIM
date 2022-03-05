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

enum ButtonStatus
{
  NOT_PRESSED = 0,
  PRESSED = 1,
  LONG_PRESS = 2
};

struct ButtonInfo
{
  unsigned int pin;
  unsigned long lastUpdate;
  bool invert;
  ButtonStatus status;
};

class ButtonManager
{
private:
  std::map<unsigned int, ButtonInfo> buttons;

  int8_t updateButtonStatus(ButtonInfo &button, ButtonStatus currentStatus);

public:
  ButtonManager(/* args */);
  ~ButtonManager();

  void checkButtons(Application* app);

  void registerButton(unsigned int pin, bool invert);
  ButtonStatus buttonStatus(unsigned int pin);
};

#endif