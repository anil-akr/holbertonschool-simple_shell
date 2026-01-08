#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

/* Structure pour les builtins */
typedef struct builtin
{
	char *name;
	void (*func)(char **);
} builtin_t;

/* Main functions */
char **parse_line(char *line);
char *read_line(void);
int execute_command(char **argv, char *prog_name, int count);

/* Prompt */
void print_prompt(void);

/* Path & Builtins */
char *find_path(char *command);
int handle_builtins(char **argv);
void exit_b(char **line);
void env_b(char **line);

/* Errors */
void print_error(char *prog_name, int count, char *command);

#endif