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

size_t _strlen_recursion(char *s);
void print_arguments(char **av);
void execute_execve_example(void);
int execute_command(char *command, char *args[]);
void print_process_info(pid_t pid);
int display_file_content(const char *filename);
void print_pid(void);
void read_and_print_line(void);
int _strlen(char *s);
void print_number(int n);
int _putchar(char c);

#endif /* MAIN_H */
