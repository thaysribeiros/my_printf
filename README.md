# my_printf
My own implementation of C's standard 'printf' function.

The my_printf() functions write output to stdout, the standard output stream;

This function writes the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.

The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.

Each conversion specification is introduced by the % character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the %, the following appear in sequence:

    doux: The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).
    c: The int argument is converted to an unsigned char, and the resulting character is written.
    s: The char * argument is expected to be a pointer to an array of character type (pointer to a string). 
       Characters from the array are written up to (but not including) a terminating NUL character.
    p: The void * pointer argument is printed in hexadecimal.
 
 # Instructions
 
    1. Run make to create the command my_printf
    2. Then run ./my_printf to print the test cases set on main.c
    3. You can comment/modify test cases on main.c to test the function call
    4. You can use my_printf to replace printf with limitations, of course :)
    5. Have fun!
