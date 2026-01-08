#include "shell.h"

/**
 * main - entry point of the simple shell
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *line;
	char **argv;
	int line_count = 0;
	(void)ac;

	while (1)
	{
		line_count++; /* On compte les lignes pour l'erreur */
		
		print_prompt(); /* Ton fichier prompt.c est utilisé ici */
		
		line = read_line();
		if (line == NULL) /* EOF (Ctrl+D) */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		argv = parse_line(line);
		if (argv != NULL)
		{
			if (argv[0] != NULL)
			{
				/* Si ce n'est pas un builtin, on exécute */
				if (handle_builtins(argv) == 0)
				{
					execute_command(argv, av[0], line_count);
				}
			}
			free(argv);
		}
		free(line);
	}
	return (0);
}