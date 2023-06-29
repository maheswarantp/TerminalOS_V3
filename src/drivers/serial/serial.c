#include <drivers/serial.h>

int init_serial()
{
    outb(COM1 + 1, 0x00);
    outb(COM1 + 3, 0x80);
    outb(COM1 + 0, 0x03);
    outb(COM1 + 1, 0x00);
    outb(COM1 + 3, 0x03);
    outb(COM1 + 2, 0xC7);
    outb(COM1 + 4, 0x0B);
    outb(COM1 + 4, 0x1E);
    outb(COM1 + 0, 0xAE);


    if(inb(COM1 + 0) != 0xAE)
        return 0;

    outb(COM1 + 4, 0x0F);
    return 1;
}


// Write Data
int is_transmit_empty()
{
    return inb(COM1 + 5) & 0x20;
}

void write_serial(uint8_t* a)
{
    while(is_transmit_empty() == 0);
    outb(COM1, *a);
}

void qemu_printf(uint8_t* string)
{
    for(int i = 0; string[i] != '\0'; i++)
        write_serial(string + i);
}