#include "shell.h"

void print_error(char *command)
{
	if (!command)
	return;

	write(STDERR_FILENO, "./simple_shell: ", 16);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
}