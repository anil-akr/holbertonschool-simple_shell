#include "main.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>

/**
 * check_built_ins - checks if a string matches a builtin command
 * Description: This function compares the given string with a list of
 * supported builtin commands. If a match is found, it returns a pointer
 * to the corresponding builtin function. If no match is found or if the
 * string is NULL, the function returns NULL.
 * @str: string containing the command name to check
 *
 * Return: pointer to the builtin function if found, or NULL otherwise
 */

void (*check_built_ins(char *str))(char *str)
{
	int i;

	builtin_t buildin[] = {
		{"exit", exit_b},
		{"env", env_b},
		{NULL, NULL}
	};

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; buildin[i].name != NULL; i++)
	{
		if (strcmp(str, buildin[i].name) == 0)
		{
			return (buildin[i].func);
		}
	}

	return (NULL);
}

/**
 * env_b - prints the current environment
 * Description: This function displays all the environment variables
 * available in the current process by writing each variable followed
 * by a new line to the standard output.
 * @line: unused parameter (original input line)
 *
 * Return: nothing
 */

void env_b(__attribute__((unused))char *line)
{
	int i;
	int j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			write(STDOUT_FILENO, &environ[i][j], 1);
		}
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * exit_b - exits the shell
 * Description: This function terminates the shell process by calling
 * the exit system call with a status code of 0.
 * @line: unused parameter (original input line)
 *
 * Return: nothing
 */

void exit_b(__attribute__((unused)) char *line)
{
	exit(0);
}
