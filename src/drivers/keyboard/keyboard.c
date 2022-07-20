#include <drivers/keyboard.h>

char charset[] = {

};


void keyboard_callback(registers_t *regs)
{
    uint8_t data = inb(0x60);
    printf("%x\n", data);
}


void init_keyboard()
{
    register_interrupt_handler(IRQ1, &keyboard_callback);
}

// https://wiki.osdev.org/PS/2_Keyboard