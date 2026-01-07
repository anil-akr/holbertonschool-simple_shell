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
<<<<<<< HEAD
	if (strcmp(argv[0], "exit") == 0)
    	exit(0);
	if (handle_builtins(argv) == 1)
		return (0);
	if (argv[0][0] == '/')
		command_path = argv[0];
	else
		command_path = find_path(argv[0]);
	if (!command_path)
	{
		print_error(argv[0]);
		return (-1);
	}
	
=======

	cmd_path = find_path(argv[0]);
	if (cmd_path == NULL)
	{
		print_error(argv[0]);
		return (0);
	}

>>>>>>> f356b02 (Fixed all problems normally)
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
