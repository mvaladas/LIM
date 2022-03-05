#include <stdint.h>

// Define Sprite structure
#ifndef _H_SPRITESTRUCT
#define _H_SPRITESTRUCT

struct Sprite
{
    const uint16_t frameCount;
    const uint16_t width;
    const uint16_t height;
    const uint32_t *frameduration;
    const uint32_t *frames;
};

#endif