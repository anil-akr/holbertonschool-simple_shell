#include "shell.h"

/**
 * execute_command - executes a command exactly as typed
 * @argv: null-terminated array of arguments
 *
 * Return: 0 always
 */

int execute_command(char **argv)
{
	pid_t pid;
	int status;

	if (argv == NULL || argv[0] == NULL)
		return (0);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		execve(argv[0], argv, environ);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}

	return (0);
}
