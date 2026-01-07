#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void exit_b(__attribute__((unused)) char *line);
void env_b(__attribute__((unused)) char *line);

static builtin_t builtins[] = {
	{"exit", exit_b},
	{"env", env_b},
	{NULL, NULL}
};

/**
 * check_built_ins - return the function pointer for a builtin command
 * @str: command string
 *
 * Return: pointer to builtin function, or NULL if not found
 */
void (*check_built_ins(char *str))(char *str)
{
	int i = 0;

	if (!str)
		return (NULL);

	while (builtins[i].name)
	{
		if (strcmp(str, builtins[i].name) == 0)
			return (builtins[i].func);
		i++;
	}

	return (NULL);
}

/**
 * built_in - checks if a command is a shell builtin and executes it
 * @command: array of strings containing the command and arguments
 * @line: original input line
 *
 * Return: 0 if a builtin was executed, -1 otherwise
 */
int built_in(char **command, char *line)
{
	void (*build)(char *);

	if (command == NULL || command[0] == NULL)
		return (-1);

	build = check_built_ins(command[0]);
	if (build == NULL)
		return (-1);

	build(line);
	return (0);
}

/**
 * exit_b - exits the shell
 * Description: This function terminates the simple shell by calling
 * the exit system call with a status code of 0. It is used as a
 * builtin command.
 * @line: unused parameter (original input line)
 *
 * Return: nothing
 */
void exit_b(__attribute__((unused)) char *line)
{
	exit(0);
}

/**
 * env_b - prints all environment variables
 * Description: This function iterates over the global `environ`
 * variable and prints each environment string followed by a newline.
 * It is used as a builtin command in the simple shell.
 * @line: unused parameter (original input line)
 *
 * Return: nothing
 */

void env_b(__attribute__((unused)) char *line)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
