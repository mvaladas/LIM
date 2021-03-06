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


/* Data exported for Clear*/
static const uint32_t PROGMEM clear_frameduration[4] = {150, 150, 150, 150};

static const uint32_t PROGMEM clear_data[4][64] = {
{
0x00000000, 0x00000000, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0x00000000, 0x00000000,
0x00000000, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0x00000000,
0xFFFFDF5D, 0xFFFFD93E, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD93E, 0xFFFFDF5D,
0xFFFFDF5D, 0xFFFFD93E, 0xFFFFD31F, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFD31F, 0xFFFFD93E, 0xFFFFDF5D,
0xFFFFDF5D, 0xFFFFD93E, 0xFFFFD31F, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFD31F, 0xFFFFD93E, 0xFFFFDF5D,
0xFFFFDF5D, 0xFFFFD93E, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD93E, 0xFFFFDF5D,
0x00000000, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0x00000000,
0x00000000, 0x00000000, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0x00000000, 0x00000000,
0x00000000, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0x00000000,
0xFFFFD93E, 0xFFFFD31F, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFD31F, 0xFFFFD93E,
0xFFFFD93E, 0xFFFFD31F, 0xFFFFCD00, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFCD00, 0xFFFFD31F, 0xFFFFD93E,
0xFFFFD93E, 0xFFFFD31F, 0xFFFFCD00, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFCD00, 0xFFFFD31F, 0xFFFFD93E,
0xFFFFD93E, 0xFFFFD31F, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFD31F, 0xFFFFD93E,
0x00000000, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0x00000000,
0x00000000, 0x00000000, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0x00000000, 0x00000000,
0x00000000, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0x00000000,
0xFFFFD31F, 0xFFFFCD00, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFCD00, 0xFFFFD31F,
0xFFFFD31F, 0xFFFFCD00, 0xFFFFDF5D, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFDF5D, 0xFFFFCD00, 0xFFFFD31F,
0xFFFFD31F, 0xFFFFCD00, 0xFFFFDF5D, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFDF5D, 0xFFFFCD00, 0xFFFFD31F,
0xFFFFD31F, 0xFFFFCD00, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFCD00, 0xFFFFD31F,
0x00000000, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0x00000000,
0x00000000, 0x00000000, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD31F, 0x00000000, 0x00000000
},
{
0x00000000, 0x00000000, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0x00000000, 0x00000000,
0x00000000, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0x00000000,
0xFFFFCD00, 0xFFFFDF5D, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFDF5D, 0xFFFFCD00,
0xFFFFCD00, 0xFFFFDF5D, 0xFFFFD93E, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD93E, 0xFFFFDF5D, 0xFFFFCD00,
0xFFFFCD00, 0xFFFFDF5D, 0xFFFFD93E, 0xFFFFD31F, 0xFFFFD31F, 0xFFFFD93E, 0xFFFFDF5D, 0xFFFFCD00,
0xFFFFCD00, 0xFFFFDF5D, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFD93E, 0xFFFFDF5D, 0xFFFFCD00,
0x00000000, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0xFFFFDF5D, 0x00000000,
0x00000000, 0x00000000, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0xFFFFCD00, 0x00000000, 0x00000000
}
};
Sprite Clear = {
    4, // Frames
    8, // Width
    8, // Height
    &(clear_frameduration[0]), // Frames duration
    &(clear_data[0][0]) // Frames Data
};
