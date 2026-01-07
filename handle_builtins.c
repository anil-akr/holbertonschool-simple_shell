#include "shell.h"

/**
 * handle_builtins - checks and executes a builtin command
 * Description: This function determines whether the first element
 * of argv matches a shell builtin command. If a matching builtin
 * is found, it is executed. Otherwise, the function does nothing.
 * @argv: array of strings containing the command name and arguments
 *
 * Return: 1 if a builtin command was executed, 0 otherwise
 */

int handle_builtins(char **argv)
{
	void (*func)(char *);

	if (!argv || !argv[0])
		return (0);

	func = check_built_ins(argv[0]);
	if (!func)
		return (0);

	func(NULL);

	if (strcmp(argv[0], "exit") == 0)
		printf("OK\n");

	return (1);
}
