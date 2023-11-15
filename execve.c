#include "main.h"

/**
 * execute_execve_example - function
 */
void execute_execve_example(void)
{
char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

printf("Before execve\n");
if (!execve(argv[0], argv, NULL))
{
perror("Error:");
}
printf("After execve\n");
}
