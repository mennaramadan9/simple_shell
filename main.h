#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

void parse_input(const char *input, char **args, size_t *arg_count);
void execute_command(char **args);
size_t _strlen(char *s);
void print_number(int n);
int _putchar(char c);

#endif /* MAIN_H */
