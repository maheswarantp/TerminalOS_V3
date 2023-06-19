#ifndef __STRING__
#define __STRING__

#include <drivers/screen.h>

void printf(const char* str, ...);
boolean strcmp(char* str1, char* str2);
void print_binary(uint32_t val);


#endif