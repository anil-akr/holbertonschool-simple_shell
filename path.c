#include "shell.h"

/**
 * get_path_from_environ - get PATH from environ manually
 * Return: PATH string or NULL if not found
 */

char *get_path_from_environ(void)
{
	int i = 0;
	char *prefix = "PATH=";

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], prefix, 5) == 0)
			return (environ[i] + 5);
		i++;
	}
	return (NULL);
}

/**
 * build_full_path - concatenate dir + "/" + command
 * @dir: directory path
 * @command: command name
 * Return: malloced string or NULL
 */

static char *build_full_path(char *dir, char *command)
{
	char *full_path;
	int dir_len = _strlen(dir);
	int cmd_len = _strlen(command);

	full_path = malloc(dir_len + cmd_len + 2);
	if (full_path == NULL)
		return (NULL);

	_strcpy(full_path, dir);
	_strcat(full_path, "/");
	_strcat(full_path, command);

	return (full_path);
}

/**
 * find_path - searches PATH directories for a command
 * @command: name of the command
 * Return: malloced full path if found, NULL otherwise
 */

char *find_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;

	if (command == NULL)
		return (NULL);

	path_env = get_path_from_environ();
	if (path_env == NULL)
		return (NULL);

	path_copy = strdup(path_env);
	if (path_copy == NULL)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = build_full_path(dir, command);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

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
