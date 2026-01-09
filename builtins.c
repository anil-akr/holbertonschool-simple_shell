#include "shell.h"

/**
 * exit_b - builtin exit, terminates the shell
 * @line: input line (unused)
 * This function exits the shell program.
 * The input line is freed before exiting.
 */

void exit_b(__attribute__((unused)) char *line)
{
    free(line);
    exit(0);
}

/**
 * env_b - builtin env, prints environment variables
 * @line: input line (unused)
 * This function iterates through the environment variables
 * and prints each one followed by a newline.
 */
void env_b(__attribute__((unused)) char *line)
{
    int i = 0;

    while (environ[i])
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}

/**
 * check_built_ins - checks if a command is a builtin
 * @str: command name
 *
 * Return: pointer to the corresponding builtin function,
 * or NULL if the command is not a builtin
 */

void (*check_built_ins(char *str))(char *str)
{
    int i = 0;
    builtin_t buildin[] = {
        {"exit", exit_b},
        {"env", env_b},
        {NULL, NULL}
    };

    if (str == NULL)
        return (NULL);

    while (buildin[i].name)
    {
        if (strcmp(str, buildin[i].name) == 0)
            return (buildin[i].func);
        i++;
    }
    return (NULL);
}

/**
 * built_in - executes a builtin command if recognized
 * @command: array containing the command and its arguments
 * @line: input line (can be NULL)
 *
 * Return: 0 if a builtin was executed, -1 otherwise
 */

int built_in(char **command, char *line)
{
    void (*build)(char *);

    if (!command || !*command)
        return (-1);

    build = check_built_ins(command[0]);
    if (build == NULL)
        return (-1);

    build(line);
    return (0);
}
