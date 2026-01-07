#include "shell.h"

/**
 * main - entry point of the simple shell
 * Description: This function implements the main loop of the simple
 * shell. It repeatedly displays a prompt, reads user input, parses
 * the input into arguments, executes commands (builtin or external),
 * and frees allocated memory. The loop continues until EOF (Ctrl+D)
 * or an input error occurs.
 *
 * Return: 0 on successful termination
 */

int main(void)
{
	char *line;
	char **argv;

	while (1)
	{
		print_prompt();

		line = read_line();
		if (!line)
			break;

		argv = parse_line(line);
		if (argv)
		{
			execute_command(argv);
			free(argv);
		}

		free(line);
	}

	return (0);
}

