#include "shell.h"

int handle_builtins(char **argv)
{
    void (*func)(char *);

    if (!argv || !argv[0])
        return 0;

    func = check_built_ins(argv[0]);
    if (!func)
        return 0;

    func(NULL);
    return 1; /* builtin trouvé et exécuté */
}
