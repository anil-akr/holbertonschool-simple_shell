#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

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

int execute_command(char **argv);
char *find_path(char *command);
int handle_builtins(char **argv);
void print_error(char *command);

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

char **parse_line(char *line);
char *read_line(void);

#endif