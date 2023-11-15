#include "main.h"

/**
 * read_and_print_line - Program entry point.
 */
void read_and_print_line(void)
{
char *lineptr = NULL;
size_t line_len = 0;
int count;
ssize_t len_read;

write(STDOUT_FILENO, "$ ", 2);

len_read = getline(&lineptr, &line_len, stdin);

for (count = 0; lineptr[count] != '\n' && count < _strlen(lineptr); count++)
{
if (lineptr[count] == EOF)
return;
}

write(STDOUT_FILENO, lineptr, len_read);
free(lineptr);
}
