int built_in(char **command, char *line)
{
    void (*build)(char *);

	if (command == NULL || command[0] == NULL)
    {
        return (-1);
    }
    build = check_built_ins(command[0]);
    if (build == NULL)
    {
        return (-1);
    }
	build(line);
	return (0);
}

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

    for (i = 0; builtins[i].name != NULL; i++)
    {
        if (_strcmp(str, builtins[i].name) == 0)
        {
            return (builtins[i].func);
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