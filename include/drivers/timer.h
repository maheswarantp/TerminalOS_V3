#ifndef TIMER_H
#define TIMER_H

#include <types.h>
#include <ports.h>
#include <cpu/isr.h>
#include <lib/string.h>

#define TIMER_INTERRUPT 32

void init_timer(uint32_t freq);
uint32_t getTime();
void sleep(uint32_t time);

#endif