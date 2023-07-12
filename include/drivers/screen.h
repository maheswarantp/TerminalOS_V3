#ifndef __SCREEN__
#define __SCREEN__

#include <types.h>
#include <ports.h>


#define VID_MEM 0xB8000

void clear_screen(void);
void put_char(uint8_t* c, int offset);
int get_current_color();
void set_color_at_addr(int color, int offset);
void enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
void update_cursor(int offset);

#endif