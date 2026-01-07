#include "main.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>

void (*check_built_ins(char *str))(char *str)
{
	int i;

	builtin_t buildin[] = {
		{"exit", exit_b},
		{"env", env_b},
		{NULL, NULL}
	};

    if (str == NULL)
    {
        return (NULL);
    }

    for (i = 0; buildin[i].name != NULL; i++)
    {
        if (strcmp(str, buildin[i].name) == 0)
        {
            return (buildin[i].func);
        }
    }

    return (NULL);
}

void env_b(__attribute__((unused))char *line)
{
	int i;
	int j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			write(STDOUT_FILENO, &environ[i][j], 1);
		}
		write(STDOUT_FILENO, "\n", 1);
	}
}

void exit_b(__attribute__((unused)) char *line)
{
	exit(0);
}