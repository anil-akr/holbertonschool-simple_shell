#include "shell.h"

/**
 * fork_and_execute - forks a child and executes a command
 * @command_path: full path to the command
 * @argv: array of arguments
 * Return: 0 on success, -1 on fork failure
 */

static int fork_and_execute(char *command_path, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(command_path, argv, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);

	return (0);
}

/**
 * get_command_path - returns full path of a command
 * @argv: array of arguments
 *
 * Return: full path string if found, otherwise NULL
 */

static char *get_command_path(char **argv)
{
	char *command_path;

	if (argv[0][0] == '/')
		command_path = argv[0];
	else
		command_path = find_path(argv[0]);

	return (command_path);
}

/**
 * execute_command - executes a command with arguments
 * @argv: null-terminated array of arguments
 *
 * This function checks for built-ins, resolves the command path,
 * forks a child process and executes the command. Parent waits for child.
 *
 * Return: 0 on success, -1 on failure
 */

int execute_command(char **argv)
{
	char *command_path;

	if (!argv || !argv[0])
		return (0);

	if (built_in(argv, NULL) == 0) /* builtin executed */
		return (0);

	command_path = get_command_path(argv);
	if (!command_path)
	{
		print_error(argv[0]);
		return (-1);
	}

	fork_and_execute(command_path, argv);

	if (argv[0][0] != '/')
		free(command_path);

	return (0);
}
