#include <stdarg.h> //variable-length argument lists
#include <unistd.h> 
#include <stdio.h> //test printf
int my_strlen(char* str)
{
    int len = 0;
    while(str[len] != '\0')
    {
        len += 1;
    }
    return len;
}
void my_putchar(char c)
{
    {
        write (1, &c, 1);
    }
}
void my_putstr(char* str, int nbr) 
{
    if (str[0] == '\0' || str == NULL)
    {
        my_putstr("null", 4);
    }
    write (1, str, nbr);
}

int convert(unsigned int nbr, int base) //makes the conversion to unsigned - cases o, u, x
{ 
	char representation[]= "0123456789abcdefg"; //ASCII needed for the max conversion (hexadecimal)
	char buffer[50];
	char* ptr; 

	ptr = &buffer[49];  //pointing for the end, it will make the "reverse" function
    *ptr = '\0';        //null char in the end 
	
	while(nbr != 0)
	{ 
		*--ptr = representation[nbr % base]; //feeds the buffer with the chars converted; decrementing because we started from the end
		nbr /= base;                         // nbr%base && nbr/= base - same putnbr logic   
	}
    my_putstr(ptr, my_strlen(ptr)); 
    return my_strlen(ptr);                  //I'm returning the length of ptr to know how many characters are being printed 
}
int count_digit(long long n)                //Function to count how many digits/characters are being printed in the case 'd'
{
    int count = 0;
    if (n < 0)                              //if n is negative, we count+= 1 for the signal char
    {
        count += 1;
        n *= -1;                            //transforming in positive to count the digits
    }
    while (n != 0 && n > 0) 
    {
        count += 1;
        n = n / 10;                         //when the base is decimal, we count+=1 everytime we divide by 10
    }
    return count;
}
void my_putnbr(int nbr, int base) //recursive function to convert int in str in a determined base
{
    if (nbr < 0)                  //if nbr is negative, we print the '-' signal, multiplies nbr*-1, and keep going 
    {
        my_putchar('-');
        my_putnbr(-nbr, base);
    }
    else if (nbr > 0)                   //nbr being positive, we keep dividing nbr for the base until the end  
    {
        my_putnbr(nbr/base, base);
        my_putchar(nbr % base + '0'); //printing each nbr in the corresponded ASCII char 
    }
}
void my_put_ptr(long nbr, char* base) //recursive function to print the memory addresses; needed to make it separated because of the variable type being long
{
    long nb;

    if (nbr > 0)
    {
        nb = nbr;
        nbr /= 16;
        my_put_ptr(nbr, base);          //it is a mix of the put_nbr logic with the convert_function logic, because my base is the char* = "0123456789abcdef" 
        my_putchar(base[nb % 16]);      //it is always 16 because the project asks for hexadecimal
    }
}
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
int main()
{   
    char character = '9';
    char* char_ptr = &character;
    int res_my_printf = my_printf("case -> %p\n", char_ptr);
    int res_printf = printf("case -> %p\n", char_ptr);

    if (res_my_printf == res_printf)
    {
        printf("OK\n");
    }
    else
    {
        printf("KO\n");
    }

    int zero = 0;
    int a = 123;
    int neg = -123;
    int* p = &a;
    char b = 'l';
    char* c = "I love baby Yoda! ! !";
    char** ptr = &c;
    my_printf("My_printf:\n");
    my_printf("case 'zero' -> %d\n", zero);
    my_printf("case 'd' -> %d\n", a);
    my_printf("case 'd' negative -> %d\n", neg);
    my_printf("case 'o' -> %o!\n", a);
    my_printf("case 'u' -> %u\n", a);
    my_printf("case 'x' -> %x\n", a);
    my_printf("case 'c' -> %c\n", b);
    my_printf("case 's' -> %s\n", c);
    my_printf("case int* 'p' -> %p\n", p);
    my_printf("case char* 'p' -> %p\n", ptr);
    my_printf("The REAL printf:\n");
    printf("case 'zero' -> %d\n", zero);
    printf("case 'd' -> %d\n", a);
    printf("case 'd' negative -> %d\n", neg);
    printf("case 'o' -> %o!\n", a);
    printf("case 'u' -> %u\n", a);
    printf("case 'x' -> %x\n", a);
    printf("case 'c' -> %c\n", b);
    printf("case 's' -> %s\n", c);
    printf("case int* 'p' -> %p\n", p);
    printf("case char* 'p' -> %p\n", ptr);
}
