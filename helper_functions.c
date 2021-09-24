#include "my_printf.h"

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
void my_putstr(char* str, int nbr) //I created the second parameter "nbr" trying to optimize my_putstr and avoid to call my_putchar several times
{
    if (str[0] == '\0' || str == NULL)
    {
        my_putstr("null", 4);
    }
    write (1, str, nbr);
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
