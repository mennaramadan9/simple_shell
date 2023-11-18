#include "main.h"

/**
 * display_prompt - function
 */
void display_prompt(void)
{
printf("#cisfun$ ");
fflush(stdout);
}

/**
 * command_exists - function
 * @command: command
 * Return: 0
 */
int command_exists(char *command)
{
char **args = malloc(2 * sizeof(char *));
int status, result;
pid_t pid;

if (args == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
args[0] = command;
args[1] = NULL;

pid = fork();

if (pid == 0)
{
execvp(command, args);
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("fork");
exit(EXIT_FAILURE);
}

waitpid(pid, &status, 0);

result = (WIFEXITED(status) && WEXITSTATUS(status) == 0);

free(args);
return (result);
}

/**
 * print_environment - print
 */
void print_environment(void)
{
char **env;
for (env = environ; *env != NULL; env++)
{
printf("%s\n", *env);
}
}

/**
 * main - main function
 * Return: 0
 */
int main(void)
{
#define MAX_ARGS 32
#define MAX_INPUT_SIZE 1024
size_t arg_count, len;
char *args[MAX_ARGS];
char input[MAX_INPUT_SIZE];

while (1)
{
display_prompt();

if (fgets(input, sizeof(input), stdin) == NULL)
{
printf("\n");
exit(EXIT_SUCCESS); }

len = strlen(input);
if (len > 0 && input[len - 1] == '\n')
{
input[len - 1] = '\0';
}

if (strcmp(input, "env") == 0)
{
print_environment();
continue;
}
if (strcmp(input, "exit") == 0)
{
printf("\n");
exit(EXIT_SUCCESS); }

arg_count = 0;
parse_input(input, args, &arg_count);

if (!command_exists(args[0]))
{
printf("%s: command not found\n", args[0]);
continue; }
execute_command(args); }
return (0); }
