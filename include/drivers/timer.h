#ifndef __TIMER__
#define __TIMER__

#include <types.h>

#define TIMER_INTERRUPT 32

void init_timer(uint32_t freq);
uint32_t getTime();
void sleep(uint32_t time);

#endif
