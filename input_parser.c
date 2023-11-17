#include "main.h"

/**
 * parse_input - function
 * @input: char
 * @args: char
 * @arg_count: size_t
 */
void parse_input(const char *input, char **args, size_t *arg_count)
{
char input_copy[1024];
char *token;

strcpy(input_copy, input);

token = strtok(input_copy, " ");

while (token != NULL && *arg_count < 32 - 1)
{
args[(*arg_count)++] = token;
token = strtok(NULL, " ");
}
args[*arg_count] = NULL;
}
