#include "shell.h"

/**
 * execute_command - executes a command using PATH
 * @argv: arguments
 * @prog_name: nom du shell (./hsh) pour l'erreur
 * @count: numéro de ligne pour l'erreur
 * Return: 0 always
 */
int execute_command(char **argv, char *prog_name, int count)
{
	pid_t pid;
	int status;
	char *cmd_path;

	if (argv == NULL || argv[0] == NULL)
		return (0);

	cmd_path = find_path(argv[0]);

	if (cmd_path == NULL)
	{
		print_error(prog_name, count, argv[0]);
		return (0);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		free(cmd_path);
		return (0);
	}

	if (pid == 0)
	{
		execve(cmd_path, argv, environ);
		perror(argv[0]);
		free(cmd_path);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}

	free(cmd_path);
	return (0);
}