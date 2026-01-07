#include "shell.h"

/**
 * parse_line - splits a line into an array of arguments
 * @line: input line
 * Return: NULL-terminated array of strings
 */

char **parse_line(char *line)
{
	char **argv;
	char **new_argv;
	char *token;
	int i = 0;
	int size = 8;
	int j;

	if (!line)
		return (NULL);

	argv = malloc(sizeof(char *) * size);
	if (!argv)
		return (NULL);

	token = strtok(line, " \t\n");
	while (token)
	{
		if (i >= size - 1)
		{
			size *= 2;
			new_argv = malloc(sizeof(char *) * size);
			if (!new_argv)
			{
				free(argv);
				return (NULL);
			}

			j = 0;
			while (j < i)
			{
				new_argv[j] = argv[j];
				j++;
			}

			free(argv);
			argv = new_argv;
		}

		argv[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}

	argv[i] = NULL;
	return (argv);
}
