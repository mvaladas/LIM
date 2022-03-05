/**
 * @file Application.h
 * @author Miguel Valadas (mvaladas@users.noreply.github.com)
 * @brief Application class declaration
 * @version 0.1
 * @date 16-08-212021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _H_APPLICATION
#define _H_APPLICATION

#define BTN_LEFT_PRESS 1
#define BTN_RIGHT_PRESS 2
#define BTN_MIDDLE_PRESS 3
#define BTN_LEFT_RELEASE 4
#define BTN_RIGHT_RELEASE 5
#define BTN_MIDDLE_RELEASE 6

#include <LimMatrix/LimMatrix.h>
#include "Sprites/Sprite.h"

/**
 * @brief Abstract class for any application.
 * 
 * @details All application should inherit from the Application abstract class.
 * It takes care of functionality generic to all applications like positioning and update intervals.
 * Also allows for one sprite to be defined and displayed.
 * 
 * Application loops should go in the following order:
 * 1. First a call to Begin() to initialize the application. Calls doBegin.
 * 2. Then a call to Update(). Calls doUpdate when the update interval has expired and doDraw on every loop.
 * 
 */
class Application
{
protected:
    /** The display offset in the X axis */
    int8_t offset_x = 0;
    /** The display offset in the Y axis */
    int8_t offset_y = 0;

    /** Pointer to the sprite to display */
    const Sprite* sprite;
    /** The sprite offset in the X axis */
    int8_t sprite_offset_x = 0;
    /** The display offset in the Y axis */
    int8_t sprite_offset_y = 0;
    /** Current sprite frame index*/
    uint16_t currentFrameIdx = 0;
    /** Last time the current sprite frame was drawn */
    unsigned long lastFrameTime = 0;

    /** Time, in milliseconds, when the last update occured. */
    unsigned long previousUpdate = 0;
    /** Interval, in milliseconds, for each app update */
    unsigned long updateInterval = 1000;

    /** Reference to the matrix that will draw the application */
    LimMatrix *matrix;

    /** Force this app to have focus and not transition */
    boolean forceFocus = false;

    /** Abstract function to execute the acutal application update operations on specific class*/
    virtual void doUpdate() = 0;
    /** Abstract function to execute the acutal application begin operations on specific class*/
    virtual void doBegin() = 0;
    /** Abstract function to execute the acutal draw operations on specific class*/
    virtual void draw() = 0;

    /** Draws the sprite on the matrix */
    virtual void drawSprite();

public:

    explicit Application();
    explicit Application(LimMatrix *matrix);
    virtual ~Application();

    virtual void Update();
    virtual void Begin();

    virtual void getOffset(int8_t* x, int8_t* y);
    virtual void setOffset(int8_t x, int8_t y);
    virtual void addOffset(int8_t x, int8_t y);

    virtual boolean isForceFocus();
    virtual void setFocus(boolean focus);

    virtual void setUpdateInterval(unsigned long updateInterval);

    virtual void setSprite(const Sprite* sprite, int8_t offsetX, int8_t offsetY);

/** Abstract function to handle button presses of the application.*/
    virtual void buttonEvent(uint8_t btnEvent);
};

#endif
