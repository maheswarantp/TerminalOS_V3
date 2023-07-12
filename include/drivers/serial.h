#ifndef __SERIAL__
#define __SERIAL__

#include <types.h>
#include <ports.h>
#include <lib/string.h>
#include <stdarg.h>


#define COM1 0x3F8

int init_serial();

void write_serial(uint8_t* c);

void qemu_printf(uint8_t* string, ...);

#endif