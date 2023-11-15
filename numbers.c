#include "main.h"

/**
 * print_number - Prints an integer to stdout using recursion.
 * @n: Number to print to stdout.
 *
 * Return: None.
 */
void print_number(int n)
{
unsigned int m;

if (n < 0)
{
_putchar('-');
m = (unsigned int)(-n);
}
else
{
m = (unsigned int)n;
}

if (m < 10)
{
_putchar(m + '0');
}
else
{
print_number(m / 10);
_putchar(m % 10 + '0');
}
}
