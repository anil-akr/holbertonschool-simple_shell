#ifndef MAIN_H
#define MAIN_H

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