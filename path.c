#include "shell.h"


/**
 * find_path - Searches for a command in the directories listed in PATH.
 * @command: Name of the program (e.g. "ls").
 * Return: Full path to the command (e.g. "/bin/ls"), or NULL if not found.
 */

char *find_path(char *command)
{
    char *path_env, *path_copy, *dir, *full_path;
    struct stat st;

    if (!command)
        return NULL;

    /* If command contains a '/', check it directly */
    if (strchr(command, '/'))
    {
        if (stat(command, &st) == 0 && access(command, X_OK) == 0)
            return _strdup(command);
        return NULL;
    }

    path_env = getenv("PATH");
    if (!path_env || _strlen(path_env) == 0)
        return NULL;

    path_copy = _strdup(path_env);
    if (!path_copy)
        return NULL;

    dir = strtok(path_copy, ":");
    while (dir)
    {
        full_path = malloc(_strlen(dir) + _strlen(command) + 2);
        if (!full_path)
            break;

        _strcpy(full_path, dir);
        _strcat(full_path, "/");
        _strcat(full_path, command);

        if (stat(full_path, &st) == 0 && access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
