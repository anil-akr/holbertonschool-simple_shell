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
		/* Affiche prompt uniquement si mode interactif */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line = read_line();
		if (!line)
			break; /* EOF ou erreur */

		argv = parse_line(line);
		if (argv)
			execute_command(argv);

		free(line);
		free(argv);
	}

	return (0);
}
