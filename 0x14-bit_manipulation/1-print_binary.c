#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to print in binary
 */
void print_binary(unsigned long int n)
{
    unsigned long int mask = 1;
    int len = sizeof(n) * 8 - 1;
    int i;

    for (i = len; i >= 0; i--)
    {
        if ((n >> i) & mask)
            _putchar('1');
        else
            _putchar('0');
    }
}
