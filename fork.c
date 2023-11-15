#include "main.h"

/**
 * execute_command - function
 * @command: com
 * @args: args
 * Return: Always 0.
 */
int execute_command(char *command, char *args[])
{
pid_t child_pid;
int status;

child_pid = fork();
if (child_pid == -1)
{
perror("fork");
return (1);
}

if (child_pid == 0)
{
execve(command, args, NULL);
perror("execve");
exit(EXIT_FAILURE);
}
else
{
wait(&status);
}

return (0);
}
