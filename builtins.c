#include "shell.h"

/**
 * exit_b - builtin exit, termine le shell
 * @line: ligne d'entrée (non utilisée)
 */

void exit_b(__attribute__((unused)) char *line)
{
    free(line);
    exit(0);
}

/**
 * env_b - builtin env, affiche les variables d'environnement
 * @line: ligne d'entrée (non utilisée)
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
 * check_built_ins - retourne le pointeur sur la fonction builtin si elle existe
 * @str: nom de la commande
 * Return: pointeur sur fonction ou NULL si pas trouvé
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
 * built_in - exécute un builtin si reconnu
 * @command: tableau de commandes
 * @line: ligne entrée (peut être NULL)
 * Return: 0 si builtin exécuté, -1 sinon
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
