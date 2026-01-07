#include "shell.h"
/**
 * print_error - prints an error message when a command is not found
 * @command: the command that could not be executed
 *
 * This function writes an error message to the standard error output
 * indicating that the given command was not found.
 */
void print_error(char *command)
{
	if (!command)
		return;

	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": No such file or directory\n", 28);
}
