#include "shell.h"

/**
 * exit_b - builtin exit
 * @argv: arguments (unused)
 */
void exit_b(char **argv)
{
	/* On free avant de quitter proprement */
	(void)argv;
	exit(0);
}

/**
 * env_b - builtin env
 * @argv: arguments (unused)
 */
void env_b(char **argv)
{
	int i = 0;
	(void)argv;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * handle_builtins - exécute un builtin
 * @argv: tableau de commandes
 * Return: 1 si exécuté, 0 sinon
 */
int handle_builtins(char **argv)
{
	builtin_t builtins[] = {
		{"exit", exit_b},
		{"env", env_b},
		{NULL, NULL}
	};
	int i = 0;

	if (!argv || !argv[0])
		return (0);

	while (builtins[i].name)
	{
		if (strcmp(argv[0], builtins[i].name) == 0)
		{
			builtins[i].func(argv);
			return (1);
		}
		i++;
	}
	return (0);
}