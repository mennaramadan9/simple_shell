#include "main.h"
#include <unistd.h>

/**
 * execute_command - Execute a command with arguments using execve.
 * @command: The path of the command
 * @args: An array of strings
 *
 * Return: 0 on success, 1 on error.
 */
void execute_command(char *command, char *args[])
{
extern char **environ;
execve(command, args, environ);
perror("execve");
exit(EXIT_FAILURE);
}
