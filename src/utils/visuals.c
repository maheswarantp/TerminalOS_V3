#include  <utils/visuals.h>

void boot_screen()
{
    clear_screen();
    printf("-------------------------------------------------------------------------------\n");
    printf("  _______                  _             _    ____   _____ \n");
    printf(" |__   __|                (_)           | |  / __ \\ / ____|\n");
    printf("    | | ___ _ __ _ __ ___  _ _ __   __ _| | | |  | | (___  \n");
    printf("    | |/ _ \\ '__| '_ ` _ \\| | '_ \\ / _` | | | |  | |\\___ \\ \n");
    printf("    | |  __/ |  | | | | | | | | | | (_| | | | |__| |____) |\n");
    printf("    |_|\\___|_|  |_| |_| |_|_|_| |_|\\__,_|_|  \\____/|_____/\n");
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");
}

// Introduce colors
void change_color(int COLOR)
{
    int ALL_COLOR, BACKGROUND_COLOR;
    ALL_COLOR = get_current_color();
    BACKGROUND_COLOR = ALL_COLOR / 16;
    ALL_COLOR = BACKGROUND_COLOR * 16 + COLOR;
    for(int i = 0; i < 80*25; i++)
        set_color_at_addr(ALL_COLOR, i*2);        
}


void change_background_color(int COLOR)
{
    int ALL_COLOR, FOREGROUND_COLOR;
    ALL_COLOR = get_current_color();
    FOREGROUND_COLOR = ALL_COLOR % 16;
    ALL_COLOR = COLOR * 16 + FOREGROUND_COLOR;
    for(int i = 0; i < 80 * 25; i++)
        set_color_at_addr(ALL_COLOR, i*2);
}