#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

extern char **environ;

/**
 * struct builtin - builtin commands
 * @name: name
 * @func: function pointer
 */
typedef struct builtin
{
	char *name;
	void (*func)(char *);
} builtin_t;

/* Prototypes */
int built_in(char **command, char *line);
void print_prompt(void);
int execute_command(char **argv);
char *find_path(char *command);
void print_error(char *command);
char **parse_line(char *line);
char *read_line(void);

/* Utils */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

#endif
