#ifndef __VISUALS__
#define __VISUALS__

#include <drivers/screen.h>
#include <lib/string.h>
#include <types.h>


#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LGRAY 7
#define DGRAY 8
#define LBLUE 9
#define LGREEN 10
#define LCYAN 11
#define LRED 12
#define LMAGENTA 13
#define YELLOW 14
#define WHITE 15

void boot_screen();
void change_color(int COLOR);
void change_background_color(int COLOR);


#endif