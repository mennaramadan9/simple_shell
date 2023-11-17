#include "main.h"

/**
 * display_prompt - display
 */
void display_prompt(void)
{
write(STDOUT_FILENO, "$ ", 2);
}
