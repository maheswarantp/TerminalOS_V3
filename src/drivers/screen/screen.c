#include <drivers/screen.h>

uint8_t* VID_ADD = (uint8_t*)VID_MEM;

void clear_screen(void)
{
    for(int i = 0; i < 80*25; i++)
        VID_ADD[i*2] = ' ';
    enable_cursor(0, 80*25);
    update_cursor(0);
}

void put_char(uint8_t* c, int offset)
{
    VID_ADD[offset] = c;
    update_cursor(offset/2 + 1);
}

int get_current_color()
{
    uint8_t* VID_ADD = (uint8_t*)VID_MEM;
    return VID_ADD[0+1];
}

void set_color_at_addr(int color, int offset)
{
    uint8_t* VID_ADD = (uint8_t*)VID_MEM;
    VID_ADD[offset+1] = color;
}

void enable_cursor(uint8_t cursor_start, uint8_t cursor_end)
{
    outb(0x3D4, 0x0A);
    outb(0x3D5, (inb(0x3D5 & 0xC0)) | cursor_start);
    outb(0x3D4, 0x0B);
    outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

void update_cursor(int offset)
{
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t)(offset &0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t)((offset >> 8) & 0xFF));
}