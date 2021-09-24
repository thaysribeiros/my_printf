#ifndef MY_PRINTF
#define MY_PRINTF

#include <stdarg.h> //variable-length argument lists
#include <unistd.h> //write
#include <stdio.h> //test printf

int my_strlen(char* str);
void my_putchar(char c);
void my_putstr(char* str, int nbr);
int convert(unsigned int nbr, int base);
int count_digit(long long n);
void my_putnbr(int nbr, int base);
void my_put_ptr(long nbr, char* base);
int my_printf(char * restrict format, ...);

#endif
