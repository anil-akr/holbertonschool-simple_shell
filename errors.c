#include "shell.h"

/**
 * print_error - prints error message correctly
 * @prog_name: shell name (argv[0])
 * @count: line number
 * @command: command not found
 */
void print_error(char *prog_name, int count, char *command)
{
	fprintf(stderr, "%s: %d: %s: not found\n", prog_name, count, command);
}