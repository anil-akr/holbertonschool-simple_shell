#include "shell.h"
#include <errno.h>
#include <sys/wait.h>

/**
 * execute_command - executes an external command
 * @argv: array of arguments
 * Return: status of execution
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

		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return (1);
	}

	if (pid == 0)
	{
		if (execve(cmd_path, argv, environ) == -1)
		{
			perror(argv[0]);
			free(cmd_path);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	free(cmd_path);
	return (0);
}