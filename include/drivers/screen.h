#ifndef __SCREEN__
#define __SCREEN__

#include <types.h>

#define VID_MEM 0xB8000

void clear_screen(void);
void put_char(uint8_t* c, int offset);
int get_current_color();
void set_color_at_addr(int color, int offset);

#endif