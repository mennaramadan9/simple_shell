#include "main.h"

/**
 * display_file_content - Display the content of a file line by line.
 * @filename: Name of the file to display.
 *
 * Return: 0 on success, -1 on error.
 */
int display_file_content(const char *filename)
{
FILE *file;
char *line = NULL;
size_t len = 0;
ssize_t nread;

file = fopen(filename, "r");
if (file == NULL)
{
perror("Error opening file");
return (-1);
}

while ((nread = getline(&line, &len, file)) != -1)
{
printf("Line length: %lu\n", nread);
fwrite(line, nread, 1, stdout);
}

free(line);
fclose(file);
return (0);
}
