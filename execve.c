#include "main.h"

/**
 * execute_command - function
 * @command: command
 * @args: an array of strings.
 * Return: 0 on success, 1 on error.
 */
void execute_commandd(char *command, char *args[])
{
execve(command, args, NULL);
perror("execve");
exit(EXIT_FAILURE);
}
