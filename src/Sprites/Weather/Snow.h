#include <stdint.h>
#include <avr/pgmspace.h>

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


/* Data exported for Snow*/
static const uint32_t PROGMEM snow_frameduration[1] = {100};

static const uint32_t PROGMEM snow_data[1][64] = {
{
0x00000000, 0x00000000, 0x00000000, 0xFFE3F4FE, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0xFFE3F4FE, 0xFFE3F4FE, 0xFFE3F4FE, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0xFFE3F4FE, 0x00000000, 0x00000000, 0xFFE3F4FE, 0x00000000,
0x00000000, 0xFFE3F4FE, 0x00000000, 0xFFE3F4FE, 0xFFE3F4FE, 0xFFE3F4FE, 0xFFE3F4FE, 0xFFE3F4FE,
0xFFE3F4FE, 0xFFE3F4FE, 0xFFE3F4FE, 0xFFE3F4FE, 0xFFE3F4FE, 0x00000000, 0xFFE3F4FE, 0x00000000,
0x00000000, 0xFFE3F4FE, 0x00000000, 0x00000000, 0xFFE3F4FE, 0x00000000, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0xFFE3F4FE, 0xFFE3F4FE, 0xFFE3F4FE, 0x00000000, 0x00000000,
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFE3F4FE, 0x00000000, 0x00000000, 0x00000000
}
};
Sprite Snow = {
    1, // Frames
    8, // Width
    8, // Height
    &(snow_frameduration[0]), // Frames duration
    &(snow_data[0][0]) // Frames Data
};
