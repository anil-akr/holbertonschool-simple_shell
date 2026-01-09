#include "shell.h"

/**
 * exit_b - exits the shell
 * @line: line to free
 */
void exit_b(char *line)
{
	free(line);
	exit(0);
}

/**
 * env_b - prints environment
 * @line: unused
 */

void env_b(char *line)
{
	int i = 0;
	(void)line;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * built_in - checks and executes builtins
 * @command: tokens
 * @line: original line
 * Return: 0 if builtin, -1 if not
 */

int built_in(char **command, char *line)
{
	int i = 0;
	builtin_t builtins[] = {
		{"exit", exit_b},
		{"env", env_b},
		{NULL, NULL}
	};

	while (builtins[i].name)
	{
		if (_strcmp(command[0], builtins[i].name) == 0)
		{
			builtins[i].func(line);
			return (0);
		}
		i++;
	}
	return (-1);
}