#include "shell.h"

/**
 * resize_argv - resize argv array
 * @argv: current argv
 * @size: current size
 * Return: new argv or NULL
 */

static char **resize_argv(char **argv, int *size)
{
	char **new_argv;
	int i = 0;

	*size *= 2;
	new_argv = malloc(sizeof(char *) * (*size));
	if (new_argv == NULL)
		return (NULL);

	while (argv[i] != NULL)
	{
		new_argv[i] = argv[i];
		i++;
	}

	free(argv);
	return (new_argv);
}

/**
 * parse_line - splits a line into arguments
 * @line: input line
 * Return: NULL-terminated array
 */

char **parse_line(char *line)
{
	int bufsize = 8, i = 0;
	char **argv = malloc(bufsize * sizeof(char *));
	char *token;

	if (!argv)
		return (NULL);

	token = strtok(line, " \t\n\r\a");
	while (token != NULL)
	{
		argv[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize *= 2;
			char **old_argv = argv;
			argv = realloc(argv, bufsize * sizeof(char *));
			if (!argv)
			{
				free(old_argv);
				return (NULL);
			}
		}
		token = strtok(NULL, " \t\n\r\a");
	}
	argv[i] = NULL;
	return (argv);
}