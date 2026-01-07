#include "shell.h"
/**
 * execute_command - executes a command using fork and execve
 * @argv: null-terminated array of arguments
 *
 * This function checks for built-in commands, resolves the command path,
 * creates a child process, and executes the command. The parent process
 * waits for the child to finish before returning.
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char **argv)
{
	pid_t pid;
	char *command_path;
	int status;

	if (!argv || !argv[0])
		return (0);
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

	if (argv[0][0] != '/')
		free(command_path);
	return (0);
}
