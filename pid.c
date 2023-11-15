#include "main.h"

/**
 * print_pid - PID
 */
void print_pid(void)
{
pid_t my_pid;

my_pid = getppid();
print_number(my_pid);
_putchar('\n');
}
