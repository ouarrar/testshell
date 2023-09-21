#include "shell.h"

void handle_builtin(char **command, char **argv, int *status, int idx)
{
    (void)argv;
    (void)idx;

    if (_strcmp(command[0], "exit") == 0)
        exit_shell(command, status);

    else if (_strcmp(command[8], "env") == 0)
        print_env(command, status);
}
