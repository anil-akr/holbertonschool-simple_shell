#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
    
    nread = getline(&line, &len, stdin);

    if (nread == -1)
    {
        free(line);
        return (NULL);
    }
    return (line);
}
