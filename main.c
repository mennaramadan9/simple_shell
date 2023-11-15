#include "main.h"

/**
 * main - main function
 * Return: Always 0.
 */
int main(void)
{
char *ls_args[] = {"/bin/ls", "-l", "/tmp", NULL};
int count;

for (count = 0; count < 5; count++)
{
if (execute_command(ls_args[0], ls_args) != 0)
{
fprintf(stderr, "Error executing command.\n");
return (1);
}
}

return (0);
}
