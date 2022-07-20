#include <ports.h>


uint8_t inb(uint16_t port)               // read from a port
{ 
    uint8_t result;
    __asm__("in %%dx, %%al":"=a" (result):"d"(port));
    return result;
}

uint16_t inw(uint16_t port)
{
    uint16_t ret;
    asm volatile ("inw %1, %0": "=a" (ret): "dN" (port));
    return ret;
}

void outb(uint16_t port, uint8_t data)   // send to a port
{
    __asm__("out %%al, %%dx"::"a"(data), "d"(port));
}