#ifndef __KEYBOARD__
#define __KEYBOARD__

#include <cpu/isr.h>
#include <ports.h>
#include <lib/string.h>
#include <types.h>

#define KEYBOARD_INTERRUPT 33
#define SC_MAX 0x58

void init_keyboard();

#endif