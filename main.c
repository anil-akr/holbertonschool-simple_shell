#include "shell.h"

int main(void)
{
    char *line;
    char **argv;

    while (1)
    {
        /* Affiche prompt */
        write(1, "$ ", 2);

        line = read_line();
        if (!line)
            break; /* EOF ou erreur */

        argv = parse_line(line);
        if (argv)
            execute_command(argv);

        free(line);
        free(argv);
    }

    return (0);
}
