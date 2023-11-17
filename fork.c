#include "main.h"

/**
 * execute_command - Execute a command with arguments using execve.
 * @command: The path of the command.
 * @args: an array of strings.
 */
/**
 * execute_command - Execute a command with arguments using execve.
 * @command: The path of the command
 * @args: An array of strings
 *
 * Return: void
 */
void execute(char *command, char *args[])
{
execve(command, args, NULL);
perror("execve");
exit(EXIT_FAILURE);
}
