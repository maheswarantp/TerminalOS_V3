#include <lib/string.h>
#include <stdarg.h>

uint8_t rows = 0, cols = 0;

int intlen(int val, int base)
{
    int count = 0;
    while(val != 0)
    {
        val = val / base;
        count++;
    }
    return count;
}

int strlen(uint8_t s[])
{
    int i = 0;
    while(s[i] != '\0') ++i;
    return i;

}

boolean strcmp(char* str1, char* str2)
{
    uint8_t i;
    for(i = 0; str1[i] == str2[i]; i++)
        if(str1[i+1] == '\0' || str2[i+1] == '\0') return 1;
    return 0;
}


void itoa(uint8_t* str, int val, int base)
{
    int len = intlen(val, base);
    str[len] = '\0';
    len--;
    while(val != 0)
    {
        if(base <= 10)
        {
            str[len] = '0' + val % 10;

        } else 
        {
            int rem = val % base;
            if(rem > 9)
                str[len] = '0' + 7 + val % base;
            else
                str[len] = '0' + val % base;
        }
        val = val / base;
        len--;
    }
}

void* memset(void* _s, uint32_t _c, uint32_t _n)
{
    uint8_t* p = _s;
    while(_n--)
    {
        *p++ = (uint8_t)_c;
    }
    return _s;
}



void print_binary(uint32_t val)
{
    char string[32] = "00000000000000000000000000000000";
    int i = __CHAR_BIT__ * sizeof(uint32_t);
    int count = 0;
    while(i--)
    {
        string[count] = '0' + ((val >> i) & 1);
        count++;
    }
    printf("0b");
    printf(string);
}

void printf(const char *str, ...)
{

    // get var num
    int varNum = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '%' && str[i+1] == 'x')
            varNum++;
    }

    va_list valist;

    va_start(valist, varNum);    

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '\n')
        {
            rows++;
            cols=0;
        } else if (rows >= 25)
        {
            clear_screen();
            rows = 0; cols = 0;
        } else 
        {

            if(str[i] != '%')
            {
                put_char(str[i], (rows * 80 + cols)*2);
                cols++;
            } else {
                uint8_t* s;
                switch (str[i+1])
                {
                case 'd':
                    itoa(s, va_arg(valist, int), 10);
                    printf(s);
                    printf("D");
                    i++;                    
                    break;
                case 'x':
                    itoa(s, va_arg(valist, int), 16);
                    printf("0");
                    printf("x");
                    printf(s);
                    i++;
                    break;
                case 'b':
                    continue;
                default:
                    break;
                }
            }
        }
    }
    
    va_end(valist);
}


void backspace(uint8_t s[])
{
    int len = strlen(s);
    s[len - 1] = '\0';
}

void append(uint8_t s[], uint8_t c)
{
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}