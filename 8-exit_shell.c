#include "shell.h"

void exit_shell(char **command, int *status)
{
    free2DArray(command);
    exit(*status);
}
