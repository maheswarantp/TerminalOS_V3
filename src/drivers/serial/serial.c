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

void qemu_printf(uint8_t* string, ...)
{


    int varNum = 0;
    for(int i = 0; string[i] != '\0'; i++)
    {
        if(string[i] == '%' && string[i+1] == 'x')
            varNum++;
    }

    va_list valist;

    va_start(valist, varNum);   

    for(int i = 0; string[i] != '\0'; i++)
    {
        if(string[i] != '%')
            write_serial(string + i);
        else {
            uint8_t* s;
            switch(string[i+1])
            {
                case 'd':
                    itoa(s, va_arg(valist, int), 10);
                    qemu_printf(s);
                    qemu_printf("D");
                    i++;
                    break;
                case 'x':
                    itoa(s, va_arg(valist, int), 16);
                    qemu_printf("0");
                    qemu_printf("x");
                    qemu_printf(s);
                    i++;
                    break;
                case 'b':                                       // TO BE FIXED
                    itoa(s, va_arg(valist, int), 2);
                    qemu_printf("0");
                    qemu_printf("b");
                    qemu_printf(s);
                    i++;
                    break;
                default:
                    break;
            }
        }
    }
        // write_serial(string + i);
}
