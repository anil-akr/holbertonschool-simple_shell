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
	char **argv;
	char *token;
	int i = 0;
	int size = 8;

	if (line == NULL)
		return (NULL);

	argv = malloc(sizeof(char *) * size);
	if (argv == NULL)
		return (NULL);

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		if (i >= size - 1)
		{
			argv = resize_argv(argv, &size);
			if (argv == NULL)
				return (NULL);
		}

		argv[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}

	argv[i] = NULL;
	return (argv);
}
