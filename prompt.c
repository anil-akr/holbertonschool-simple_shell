#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * print_prompt - displays the shell prompt
 */
void print_prompt(void)
{
    write(STDOUT_FILENO, "$ ", 2);
}
