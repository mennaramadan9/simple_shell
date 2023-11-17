#include "main.h"

/**
 * print_environment - print
 */
void print_environment(void)
{
extern char **environ;
char **env_ptr = environ;

while (*env_ptr != NULL)
{
write(STDOUT_FILENO, *env_ptr, _strlen(*env_ptr));
write(STDOUT_FILENO, "\n", 1);
env_ptr++;
}
}
