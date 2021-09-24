#include "my_printf.h"

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
