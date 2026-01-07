#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* read_line - Reads a line from standard input
* Return: Pointer to the line read or NULL on EOF or error
*/

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
