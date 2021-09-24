#include "my_printf.h"

int my_printf(char * restrict format, ...) //C Programming Language (Ritchie) - pg 153-156
{
    va_list ap; 
    char* p;
    char* sval;
    char cval;
    int ival;
    long pval;
    int char_count = 0; //variable to count the number of characters printed

    va_start(ap, format);
    for (p = format; *p; p++)
    {
        if (*p != '%')
        {
            my_putchar(*p);
            char_count += 1;
            continue;
        }
        switch (*++p)
        {
            case 'd':
                ival = va_arg(ap, int);
                if (ival == 0)
                {
                    my_putchar('0');
                    char_count += 1;
                }
                else
                {
                    my_putnbr(ival, 10);
                    char_count += count_digit(ival);
                }
                break;
            case 'o':
                ival = va_arg(ap, int);
                char_count += convert(ival, 8);
                break;
            case 'u':
                ival = va_arg(ap, int);
                char_count += convert(ival, 10);
                break;
            case 'x':
                ival = va_arg(ap, int);
                char_count += convert(ival, 16);
                break;
            case 's':
                sval = va_arg(ap, char*);
                if (sval == NULL)
                {
                    my_putstr("null", 4);
                    char_count += 4;
                }
                else 
                {
                    my_putstr(sval, my_strlen(sval));
                    char_count += my_strlen(sval);
                }
                break;
            case 'c':
                cval = va_arg(ap, int);
                my_putchar(cval);
                char_count += 1;
                break;
            case 'p':
                pval = va_arg(ap, long);
                my_putstr("0x", 2);
                 my_put_ptr(pval, "0123456789abcdef");
                char_count += (count_digit(pval) - 1);  //-1 because is counting 1 letter like 2 (ASCII table)
                break;
            default:
                my_putchar(*p);
                char_count += 1;
                break;
        }
    }
    va_end(ap);
    return char_count;
}
