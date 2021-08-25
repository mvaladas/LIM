#include <stdint.h>
#include <avr/pgmspace.h>

#define LOWTEMP_FPS 3
#define LOWTEMP_FRAME_COUNT 7
#define LOWTEMP_FRAME_WIDTH 7
#define LOWTEMP_FRAME_HEIGHT 8

/* Piskel data for "LowTemp" */

static const uint32_t PROGMEM lowtemp_data[7][56] = {
{
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0xff0000c8, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0xff0000c8, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0xff0000c8, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0x00000000, 0x00000000
},
{
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0xffffffff, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0x00000000, 0xffffffff, 0x00000000, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0xffffffff, 0xff0000c8, 0xff0000c8, 0xff0000c8, 0xffffffff, 0x00000000, 0x00000000, 
0x00000000, 0xffffffff, 0xffffffff, 0xffffffff, 0x00000000, 0x00000000, 0x00000000
}
};