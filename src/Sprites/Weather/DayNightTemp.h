#include <stdint.h>
#include <avr/pgmspace.h>

#define DAYNIGHTTEMP_FPS 4
#define DAYNIGHTTEMP_FRAME_COUNT 10
#define DAYNIGHTTEMP_FRAME_WIDTH 32
#define DAYNIGHTTEMP_FRAME_HEIGHT 8

/* Piskel data for "DayNightTemp" */

static const uint32_t PROGMEM daynighttemp_data[10][256] = {
{
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff333300, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffdb29, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xffffde38, 0xfffff0a0, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff0a1, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff2b0, 0xffffd60a, 0xffac9000, 0xff000000, 0xffffff00, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffffefb, 0xffffde37, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff999900, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xfffff7ce, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffdb29, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffdb29, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xffffde38, 0xfffff0a0, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffcb46, 0xffffcb46, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff0a1, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffcb46, 0xffffcb46, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff2b0, 0xffffd60a, 0xffac9000, 0xff000000, 0xffcccc00, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffffefb, 0xffffde37, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xffcccc00, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xfffff7ce, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffdb29, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff333300, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffcb46, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffdb29, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xffffde38, 0xfffff0a0, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff0a1, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff2b0, 0xffffd60a, 0xffac9000, 0xff000000, 0xff999900, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffffefb, 0xffffde37, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xffffff00, 
0xffffcb46, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xfffff7ce, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffdb29, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xffffcb46, 0xffffcb46, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff666600, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffdb29, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xffffde38, 0xfffff0a0, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff0a1, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff2b0, 0xffffd60a, 0xffac9000, 0xff000000, 0xff666600, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffffefb, 0xffffde37, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xffcccc00, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xfffff7ce, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffcb46, 0xffffcb46, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffdb29, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff999900, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffdb29, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xffffde38, 0xfffff0a0, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffcb46, 0xffffcb46, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff0a1, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffcb46, 0xffffcb46, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff2b0, 0xffffd60a, 0xffac9000, 0xff000000, 0xff333300, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffffefb, 0xffffde37, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff999900, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xfffff7ce, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffdb29, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xffcccc00, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffcb46, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffdb29, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xffffde38, 0xfffff0a0, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff0a1, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff2b0, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffffefb, 0xffffde37, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff666600, 
0xffffcb46, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xfffff7ce, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffdb29, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xffffcb46, 0xffffcb46, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xffffff00, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffdb29, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xffffde38, 0xfffff0a0, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff0a1, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff2b0, 0xffffd60a, 0xffac9000, 0xff000000, 0xff333300, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffffefb, 0xffffde37, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff333300, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xfffff7ce, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffcb46, 0xffffcb46, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffdb29, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xffcccc00, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffdb29, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xffffde38, 0xfffff0a0, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffcb46, 0xffffcb46, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff0a1, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffcb46, 0xffffcb46, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff2b0, 0xffffd60a, 0xffac9000, 0xff000000, 0xff666600, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffffefb, 0xffffde37, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xfffff7ce, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffdb29, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff999900, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffcb46, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffdb29, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xffffde38, 0xfffff0a0, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff0a1, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff2b0, 0xffffd60a, 0xffac9000, 0xff000000, 0xff999900, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffffefb, 0xffffde37, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff333300, 
0xffffcb46, 0xffffcb46, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xfffff7ce, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffdb29, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
},
{
0xffffcb46, 0xffffcb46, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff666600, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffde38, 0xffffdb29, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xffffde38, 0xfffff0a0, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff0a1, 0xffffd60a, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffff2b0, 0xffffd60a, 0xffac9000, 0xff000000, 0xffcccc00, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xfffffefb, 0xffffde37, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff999900, 
0xffffba08, 0xffffba08, 0xffffba08, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xfffff7ce, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 
0xffffcb46, 0xffffcb46, 0xffffcb46, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff4cc9f0, 0xff44b3d6, 0xff3c9ebd, 0xff3489a3, 0xff2c738a, 0xff245e70, 0xff1b4957, 0xff13333d, 0xff0b1e24, 0xff03090a, 0xff03090a, 0xff03090a, 0xff03090a, 0xffffdb29, 0xffeac300, 0xffac9000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000
}
};