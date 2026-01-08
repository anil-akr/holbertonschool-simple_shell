#include "shell.h"

/**
 * find_path - searches PATH directories for a command
 * @command: name of the command
 * Return: full path or NULL
 */
char *find_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;
	struct stat st;

	/* Cas spécial: chemin absolu ou relatif (ex: /bin/ls ou ./script) */
	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	/* Récupération du PATH */
	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		/* Construction: dir + / + command */
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		sprintf(full_path, "%s/%s", dir, command);

		if (stat(full_path, &st) == 0)
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