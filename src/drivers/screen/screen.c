#include <drivers/screen.h>

uint8_t* VID_ADD = (uint8_t*)VID_MEM;

void clear_screen(void)
{
    for(int i = 0; i < 80*25; i++)
        VID_ADD[i*2] = ' ';
}

void put_char(uint8_t* c, int offset)
{
    VID_ADD[offset] = c;
}