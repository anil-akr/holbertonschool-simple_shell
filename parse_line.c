#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
* parse_line - Split line into arguments
* @line: Input line
* Return: NULL-terminated array of strings
*/

char **parse_line(char *line)
{
	char **argv = NULL;
	char *token;
	int i = 0;

	if (line == NULL)
		return (NULL);

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		argv = realloc(argv, sizeof(char *) * (i + 2));
		if (argv == NULL)
			return (NULL);

		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}

	if (argv != NULL)
		argv[i] = NULL;

	return (argv);
}
