#include "shell.h"
/**
 * find_path - searches for a command in the PATH environment variable
 * @command: the command to locate
 *
 * This function parses the PATH environment variable and checks each
 * directory to determine if the command exists and is executable.
 *
 * Return: full path to the executable if found, otherwise NULL
 */
<<<<<<< HEAD

=======
>>>>>>> 31464c82661c7a1fbda85f75a72f85d4f33401ca
char *find_path(char *command)
{
	char *path_env;
	char *path_copy;
	char *dir;
	char *full_path;
	int cmd_len, dir_len;

	if (!command)
	return (NULL);

		path_env = getenv("PATH");
	if (!path_env)
	return (NULL);
		path_copy = strdup(path_env);
	if (!path_copy)
	return (NULL);
		cmd_len = _strlen(command);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		dir_len = _strlen(dir);
		full_path = malloc(dir_len + cmd_len + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
free(path_copy);
return (NULL);
}
