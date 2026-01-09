#include "shell.h"

/**
 * parse_line - splits a line into tokens (arguments)
 * @line: the input string to be parsed
 *
 * Return: a NULL-terminated array of strings, or NULL on failure
 */
char **parse_line(char *line)
{
	int bufsize = 8, i = 0;
	char **argv;
	char **old_argv;
	char *token;

	argv = malloc(bufsize * sizeof(char *));
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
			old_argv = argv;
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