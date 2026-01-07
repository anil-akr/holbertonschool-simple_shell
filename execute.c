#include "shell.h"

/**
 * execute_command - executes a command using PATH
 * @argv: null-terminated array of arguments
 *
 * Return: 0 always
 */

int execute_command(char **argv)
{
	pid_t pid;
	int status;
	char *cmd_path;

	if (argv == NULL || argv[0] == NULL)
		return (0);

	cmd_path = find_path(argv[0]);
	if (cmd_path == NULL)
	{
		print_error(argv[0]);
		return (0);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return (0);
	}

	if (pid == 0)
	{
		execve(cmd_path, argv, environ);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}

	free(cmd_path);
	return (0);
}
