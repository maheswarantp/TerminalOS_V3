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

bool strcmp(char* str1, char* str2)
{
    uint8_t i;
    for(i = 0; str1[i] == str2[i]; i++)
        if(str1[i+1] == '\0' || str2[i+1] == '\0') return 1;
    return 0;
}


void itoa(uint8_t* str, int val, int base)
{

    if(val == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

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

    // char* str1 = "INTEGER";
    // for(int i = 0; i < 5; i++)
    //     str[i] = str1[i];
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
                default:
                    break;
                }
            }
        }
    }
    
    va_end(valist);
}