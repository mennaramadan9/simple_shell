#include "main.h"

/**
 * print_process_info - Print process information.
 * @pid: Process ID.
 *
 * Return: None.
 */
void print_process_info(pid_t pid)
{
pid_t my_pid;

printf("After fork, %u\n", pid);
my_pid = getpid();
printf("My pid is %u\n", my_pid);
}
