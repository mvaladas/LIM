#include <stdint.h>
#include <avr/pgmspace.h>

#define CLOUDY_FPS 5
#define CLOUDY_FRAME_COUNT 11
#define CLOUDY_FRAME_WIDTH 8
#define CLOUDY_FRAME_HEIGHT 8

/* Piskel data for "Cloudy" */

static const uint32_t PROGMEM cloudy_data[11][64] = {
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffcd00, 0xffffcd00, 0xffffcd00, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffcd00, 0xffffd31f, 0xffffd31f, 0xffffd31f, 0xffffcd00, 0x00000000, 0x00000000, 
0xffffcd00, 0xffffd31f, 0xffffd93e, 0xffffd93e, 0xff19c3fb, 0xff19c3fb, 0xff19c3fb, 0x00000000, 
0xffffcd00, 0xffffd31f, 0xffffd93e, 0xff19c3fb, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 
0xff19c3fb, 0xff19c3fb, 0xffffd93e, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 
0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffd31f, 0xffffd31f, 0xffffd31f, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffd31f, 0xffffd93e, 0xffffd93e, 0xffffd93e, 0xffffd31f, 0x00000000, 0x00000000, 
0xffffd31f, 0xffffd93e, 0xffffdf5d, 0xff19c3fb, 0xff19c3fb, 0xff19c3fb, 0xffffd31f, 0x00000000, 
0xffffd31f, 0xffffd93e, 0xff19c3fb, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0x00000000, 
0xff19c3fb, 0xffffd93e, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 
0xffe3f4fe, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffd93e, 0xffffd93e, 0xffffd93e, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffd93e, 0xffffdf5d, 0xffffdf5d, 0xffffdf5d, 0xffffd93e, 0x00000000, 0x00000000, 
0xffffd93e, 0xffffdf5d, 0xff19c3fb, 0xff19c3fb, 0xff19c3fb, 0xffffdf5d, 0xffffd93e, 0x00000000, 
0xffffd93e, 0xff19c3fb, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffffd93e, 0x00000000, 
0xffffd93e, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0x00000000, 
0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffdf5d, 0xffffdf5d, 0xffffdf5d, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffdf5d, 0xffffcd00, 0xffffcd00, 0xffffcd00, 0xffffdf5d, 0x00000000, 0x00000000, 
0xffffdf5d, 0xff19c3fb, 0xff19c3fb, 0xff19c3fb, 0xffffd31f, 0xffffcd00, 0xffffdf5d, 0x00000000, 
0xff19c3fb, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffffcd00, 0xffffdf5d, 0x00000000, 
0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffffdf5d, 0xff19c3fb, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffe3f4fe, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffcd00, 0xffffcd00, 0xffffcd00, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffcd00, 0xffffd31f, 0xffffd31f, 0xffffd31f, 0xffffcd00, 0x00000000, 0x00000000, 
0xff19c3fb, 0xff19c3fb, 0xff19c3fb, 0xffffd93e, 0xffffd93e, 0xffffd31f, 0xffffcd00, 0x00000000, 
0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffffd93e, 0xffffd31f, 0xffffcd00, 0x00000000, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffffd31f, 0xff19c3fb, 0xff19c3fb, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffd31f, 0xffffd31f, 0xffffd31f, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffd31f, 0xffffd93e, 0xffffd93e, 0xffffd93e, 0xffffd31f, 0x00000000, 0x00000000, 
0xff19c3fb, 0xff19c3fb, 0xffffdf5d, 0xffffdf5d, 0xffffdf5d, 0xffffd93e, 0xffffd31f, 0x00000000, 
0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffffcd00, 0xffffdf5d, 0xffffd93e, 0xffffd31f, 0x00000000, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffffdf5d, 0xff19c3fb, 0xff19c3fb, 0x00000000, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffd93e, 0xffffd93e, 0xffffd93e, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffd93e, 0xffffdf5d, 0xffffdf5d, 0xffffdf5d, 0xffffd93e, 0x00000000, 0x00000000, 
0xff19c3fb, 0xffffdf5d, 0xffffcd00, 0xffffcd00, 0xffffcd00, 0xffffdf5d, 0xffffd93e, 0x00000000, 
0xffe3f4fe, 0xff19c3fb, 0xffffcd00, 0xffffd31f, 0xffffcd00, 0xffffdf5d, 0xffffd93e, 0xff19c3fb, 
0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffffcd00, 0xff19c3fb, 0xff19c3fb, 0xffffd93e, 0xff19c3fb, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffe3f4fe, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffdf5d, 0xffffdf5d, 0xffffdf5d, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffdf5d, 0xffffcd00, 0xffffcd00, 0xffffcd00, 0xffffdf5d, 0x00000000, 0x00000000, 
0xffffdf5d, 0xffffcd00, 0xffffd31f, 0xffffd31f, 0xffffd31f, 0xffffcd00, 0xffffdf5d, 0xff19c3fb, 
0xff19c3fb, 0xffffcd00, 0xffffd31f, 0xffffd93e, 0xffffd31f, 0xffffcd00, 0xff19c3fb, 0xff19c3fb, 
0xffe3f4fe, 0xff19c3fb, 0xffffd31f, 0xff19c3fb, 0xff19c3fb, 0xffffcd00, 0xff19c3fb, 0xffe3f4fe, 
0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffcd00, 0xffffcd00, 0xffffcd00, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffcd00, 0xffffd31f, 0xffffd31f, 0xffffd31f, 0xffffcd00, 0x00000000, 0x00000000, 
0xffffcd00, 0xffffd31f, 0xffffd93e, 0xffffd93e, 0xffffd93e, 0xffffd31f, 0xff19c3fb, 0xff19c3fb, 
0xffffcd00, 0xffffd31f, 0xffffd93e, 0xffffdf5d, 0xffffd93e, 0xff19c3fb, 0xff19c3fb, 0xffe3f4fe, 
0xff19c3fb, 0xffffd31f, 0xff19c3fb, 0xff19c3fb, 0xffffd93e, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 
0xffe3f4fe, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffd31f, 0xffffd31f, 0xffffd31f, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffd31f, 0xffffd93e, 0xffffd93e, 0xffffd93e, 0xffffd31f, 0x00000000, 0x00000000, 
0xffffd31f, 0xffffd93e, 0xffffdf5d, 0xffffdf5d, 0xffffdf5d, 0xff19c3fb, 0xff19c3fb, 0xff19c3fb, 
0xffffd31f, 0xffffd93e, 0xffffdf5d, 0xffffcd00, 0xff19c3fb, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 
0xffffd31f, 0xff19c3fb, 0xff19c3fb, 0xffffdf5d, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 
0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe
},
{
0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0x00000000, 0xffffd93e, 0xffffd93e, 0xffffd93e, 0x00000000, 0x00000000, 0x00000000, 
0x00000000, 0xffffd93e, 0xffffdf5d, 0xffffdf5d, 0xffffdf5d, 0xffffd93e, 0x00000000, 0x00000000, 
0xffffd93e, 0xffffdf5d, 0xffffcd00, 0xffffcd00, 0xff19c3fb, 0xff19c3fb, 0xff19c3fb, 0x00000000, 
0xffffd93e, 0xffffdf5d, 0xffffcd00, 0xff19c3fb, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 
0xff19c3fb, 0xff19c3fb, 0xffffcd00, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 
0xffe3f4fe, 0xffe3f4fe, 0xff19c3fb, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 
0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe, 0xffe3f4fe
}
};