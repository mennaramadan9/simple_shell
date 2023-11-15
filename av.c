#include "main.h"

/**
 * _strlen_recursion - Program entry point.
 * @s: s
 * Return: size_t.
 */
size_t _strlen_recursion(char *s)
{
if (*s == '\0')
return (0);

return (1 + _strlen_recursion(s + 1));
}

/**
 * print_arguments - Program entry point.
 * @av: av
 */
void print_arguments(char **av)
{
int i = 0;
for (; av[i]; i++)
write(STDOUT_FILENO, av[i], _strlen_recursion(av[i]));
}
