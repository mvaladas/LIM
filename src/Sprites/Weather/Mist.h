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


/* Data exported for Mist*/
static const uint32_t PROGMEM mist_frameduration[16] = {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200};

static const uint32_t PROGMEM mist_data[16][64] = {
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C,
0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C,
0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
},
{
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFF85878C,
0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFF85878C, 0xFF85878C, 0xFF85878C, 0xFFC7CBD4,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFC7CBD4,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFC7CBD4, 0xFFC7CBD4, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF,
0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF, 0xFFFAFCFF
}
};
Sprite Mist = {
    16, // Frames
    8, // Width
    8, // Height
    &(mist_frameduration[0]), // Frames duration
    &(mist_data[0][0]) // Frames Data
};
