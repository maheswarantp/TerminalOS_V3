#ifndef __KEYBOARD__
#define __KEYBOARD__

#include <cpu/isr.h>
#include <ports.h>
#include <lib/string.h>
#include <types.h>

#define KEYBOARD_INTERRUPT 33
#define SC_MAX 0x58
#define SPACE 0x30 
#define BACKSPACE 0x0e
#define ENTER 0x1c

void init_keyboard();

#endif