#include "main.h"
#define MAX_INPUT_SIZE 1024

/**
 * display_prompt - function
 */
void display_prompt(void)
{
printf("($) ");
fflush(stdout);
}

/**
 * main - main function
 * Return: 0
 */
int main(void)
{
char input[MAX_INPUT_SIZE];
pid_t pid;

while (1)
{
display_prompt();

if (fgets(input, sizeof(input), stdin) == NULL)
{
printf("\n");
break;
}

input[strcspn(input, "\n")] = '\0';

if (strcmp(input, "exit") == 0)
{
break;
}

pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execlp(input, input, (char *)NULL) == -1)
{
perror("execlp");
exit(EXIT_FAILURE);
}}
else
{
wait(NULL);
}}
return (0);
}
