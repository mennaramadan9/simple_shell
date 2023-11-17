#include "main.h"

/**
 * execute_command - function
 * @args: args
 */
void execute_command(char **args)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0) {
if (execvp(args[0], args) == -1)
{
perror("shell");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("shell");
}
else
{
waitpid(pid, &status, 0);
}
}
