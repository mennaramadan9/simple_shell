#include "main.h"

/**
 * _strlen - Calculate the length of a string.
 * @s: The string.
 *
 * Return: The length of the string.
 */
size_t _strlen(char *s)
{
size_t len = 0;

while (s[len] != '\0')
{
len++;
}

return (len);
}
