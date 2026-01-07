#ifndef MAIN_H
#define MAIN_H

/**
 * struct builtin - represents a shell builtin command
 * Description: This structure associates the name of a builtin command
 * with a pointer to the function that executes it. It is used to identify
 * and execute built-in commands such as "exit" and "env".
 * @name: name of the builtin command
 * @func: pointer to the function that executes the builtin command
 */

typedef struct builtin
{
    char *name;
    void (*func)(char *);
} builtin_t;

extern char **environ;

int built_in(char **command, char *line);
void (*check_built_ins(char *str))(char *str);
void env_b(__attribute__((unused))char *line);
void exit_b(__attribute__((unused)) char *line);
#endif