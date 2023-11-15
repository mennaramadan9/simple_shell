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

/**
 * main - Fork example.
 *
 * Return: Always 0.
 */
int main(void)
{
pid_t parent_pid, child_pid;

printf("Before fork\n");
child_pid = fork();

if (child_pid == -1)
{
perror("Error:");
return (1);
}
if (child_pid == 0)
{
print_process_info(child_pid);
}
else
{
print_process_info(child_pid);
}

return (0);
}
