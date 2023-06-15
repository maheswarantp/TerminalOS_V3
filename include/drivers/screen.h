#ifndef __SCREEN__
#define __SCREEN__

#include <types.h>

#define VID_MEM 0xB8000

void clear_screen(void);
void put_char(uint8_t* c, int offset);

#endif