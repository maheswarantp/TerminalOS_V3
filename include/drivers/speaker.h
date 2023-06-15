#ifndef __SPEAKER__
#define __SPEAKER__

/*
PC Speaker directly connected to 
Output of timer number 2 of the PIT
*/

#include <ports.h>
#include <cpu/isr.h>
#include <drivers/timer.h>
#include <lib/string.h>
#include <types.h>

void play_sound(uint32_t freq);
void stop_sound();
void beep(uint32_t timeMilliSeconds);

#endif