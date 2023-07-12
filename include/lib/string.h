#ifndef __STRING__
#define __STRING__

#include <drivers/screen.h>

void printf(const char* str, ...);
boolean strcmp(char* str1, char* str2);
void print_binary(uint32_t val);
void* memset(void* _s, uint32_t c, uint32_t _n);
void backspace(uint8_t s[]);
void append(uint8_t s[], uint8_t c);
void itoa(uint8_t* str, int val, int base);


#endif