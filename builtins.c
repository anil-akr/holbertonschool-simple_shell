#include "main.h"

/**
 * built_in - checks if a command is a shell builtin and executes it
 * Description: This function determines whether the command entered by
 * the user matches a builtin command (such as "exit" or "env"). If a
 * matching builtin is found, the corresponding function is executed.
 * If the command is not a builtin or is invalid, the function returns -1.
 * @command: array of strings containing the command name and its arguments
 * @line: buffer containing the original input line
 *
 * Return: 0 if a builtin command is found and executed, -1 otherwise
 */

int built_in(char **command, char *line)
{
	void (*build)(char *);

	if (command == NULL || command[0] == NULL)
	{
		return (-1);
	}
	build = check_built_ins(command[0]);
	if (build == NULL)
	{
		return (-1);
	}
	build(line);
	return (0);
}
