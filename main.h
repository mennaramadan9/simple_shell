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

void execute_command(char *command, char *args[]);
void execute_commandd(char *command, char *args[]);
void execute(char *command, char *args[]);
void print_process(void);
void print_file(void);
size_t _strlen(char *s);
void display_prompt(void);
void print_environment(void);
void print_number(int n);
int _putchar(char c);

#endif /* MAIN_H */
