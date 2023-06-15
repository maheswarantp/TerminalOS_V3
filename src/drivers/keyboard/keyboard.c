#include <drivers/keyboard.h>

const char *sc_name[] = { "ERROR", "Esc", "1", "2", "3", "4", "5", "6", 
    "7", "8", "9", "0", "-", "=", "Backspace", "Tab", "Q", "W", "E", 
        "R", "T", "Y", "U", "I", "O", "P", "[", "]", "Enter", "Lctrl", 
        "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`", 
        "LShift", "\\", "Z", "X", "C", "V", "B", "N", "M", ",", ".", 
        "/", "RShift", "Keypad *", "LAlt", " "
};

void keyboard_handler(registers_t *regs)
{
    uint8_t temp = inb(0x60);
    if(temp > SC_MAX) return;
    
    printf(sc_name[temp]);
    // printf(" ");

}

void init_keyboard()
{
    set_interrupt_handler(KEYBOARD_INTERRUPT, &keyboard_handler);
}