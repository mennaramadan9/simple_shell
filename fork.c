#include "main.h"

/**
 * execute_command - Execute a command with arguments using execve.
 *
 * Return: 0 on success, 1 on error.
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

/**
 * main - Program entry point.
 *
 * Return: 0 on success, 1 on error.
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
