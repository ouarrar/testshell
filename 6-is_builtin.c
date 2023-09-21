#include "shell.h"

int is_builtin(char *command)
{
    char *builtins[] = {"exit", "env"};
    int i;

    for (i = 0; builtins[i]; i++)
    {
        if (_strcmp(command, builtins[i]) == 0)
            return (1);
    }
    return (0);
}
