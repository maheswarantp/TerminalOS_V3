#include <drivers/keyboard.h>

// rudimentary keyboard driver with a static keybuffer
static uint8_t key_buffer[256];


const char *sc_name[] = { "ERROR", "Esc", "1", "2", "3", "4", "5", "6", 
    "7", "8", "9", "0", "-", "=", "Backspace", "Tab", "Q", "W", "E", 
        "R", "T", "Y", "U", "I", "O", "P", "[", "]", "Enter", "Lctrl", 
        "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`", 
        "LShift", "\\", "Z", "X", "C", "V", "B", "N", "M", ",", ".", 
        "/", "RShift", "Keypad *", "LAlt", " "
};


const char *sc_ascii[] = { '?', '?', '1', '2', '3', '4', '5', '6',     
    '7', '8', '9', '0', '-', '=', '?', '?', 'Q', 'W', 'E', 'R', 'T', 'Y', 
        'U', 'I', 'O', 'P', '[', ']', '?', '?', 'A', 'S', 'D', 'F', 'G', 
        'H', 'J', 'K', 'L', ';', '\'', '`', '?', '\\', 'Z', 'X', 'C', 'V', 
        'B', 'N', 'M', ',', '.', '/', '?', '?', '?', ' '
};

void keyboard_handler(registers_t *regs)
{
    uint8_t scancode = inb(0x60);
    if(scancode > SC_MAX) return;
    

    // Rudimentary keyboard handler
    if(scancode > SC_MAX) return;
    if(scancode == BACKSPACE)
    {
        // Do backspace
        // backspace(key_buffer);
        // printf(key_buffer);
        return;
    }
    if(scancode == ENTER)
    {
        printf("\n");
        return;
    }

    uint8_t letter = sc_ascii[(int)scancode];
    // append(key_buffer, letter);
    printf(sc_name[(int)scancode]);
    // printf(sc_name[temp]);
    // printf(" ");

}

void init_keyboard()
{
    set_interrupt_handler(KEYBOARD_INTERRUPT, &keyboard_handler);
}