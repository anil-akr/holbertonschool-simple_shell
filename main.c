#include "shell.h"

/**
 * main - entry point
 * Return: 0 on success
 */

int main(void)
{
	char *line;
	char **argv;

	while (1)
	{
		line = read_line();
		if (line == NULL)
			break;

		argv = parse_line(line);
		if (argv != NULL && argv[0] != NULL)
		{
			if (built_in(argv, line) == -1)
			{
				execute_command(argv);
			}
			free(argv);
		}
		free(line);
	}
	return (0);
}
