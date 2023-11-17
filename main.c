#include "main.h"
void interactive_mode();
char *get_line();
int _strcmp(const char *s1, const char *s2);


/**
 * interactive_mode - function
 */
void interactive_mode() 
{
char *command;
char *args[] = {NULL};

while (1) 
{
display_prompt();
command = get_line();

if (_strcmp(command, "exit") == 0) 
{
free(command);
break;
}

args[0] = command;
execute_command(command, args);

free(command);
}
}


#define INITIAL_MAX_ARGS 10

/**
 * parse_line - function
 * @line: char
 * Return: char
 */
char **parse_line(char *line) 
{
int max_args = INITIAL_MAX_ARGS;
char **args = malloc(max_args * sizeof(char *));
char *token;
int position = 0;
int new_size;

if (args == NULL) 
{
perror("malloc");
exit(EXIT_FAILURE);
}

token = strtok(line, " \t\n");

while (token != NULL) 
{
args[position] = strdup(token);
if (args[position] == NULL) 
{
perror("strdup");
exit(EXIT_FAILURE);
}
position++;

if (position >= max_args) 
{
new_size = max_args * 2;
args = realloc(args, new_size * sizeof(char *));
if (args == NULL) 
{
perror("realloc");
exit(EXIT_FAILURE);
}
max_args = new_size;
}

token = strtok(NULL, " \t\n");
}
args[position] = NULL;
return (args);
}


/**
 * main - main
 * Return: 0
 */
int main(void) 
{
char *line = NULL;
size_t len = 0;
ssize_t read;
int i;
char **args;

while (1) 
{
printf("($) ");
read = getline(&line, &len, stdin);
if (read == -1) 
{
perror("getline");
exit(EXIT_FAILURE);
}

if (line[read - 1] == '\n') 
{
line[read - 1] = '\0';
}

if (_strcmp(line, "exit") == 0) 
{
break;
}

args = parse_line(line);

for (i = 0; args[i] != NULL; i++) 
{
printf("Argument %d: %s\n", i, args[i]);
}

for (i = 0; args[i] != NULL; i++) 
{
free(args[i]);
}
free(args);
}

free(line);

return (0);
}


/**
 * get_line - function
 * Return: char
 */
char *get_line() 
{
char *line = NULL;
size_t len = 0;

if (getline(&line, &len, stdin) == -1) 
{
perror("getline");
exit(EXIT_FAILURE);
}
    
line[strcspn(line, "\n")] = '\0';

return (line);
}

/**
 * _strcmp - function
 * @s1: s1
 * @s2: s2
 * Return: int
 */
int _strcmp(const char *s1, const char *s2) 
{
while (*s1 && (*s1 == *s2)) 
{
s1++;
s2++;
}

return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
