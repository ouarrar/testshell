#include "shell.h"

/**
 * exit_shell - Exits the shell program with a specified status.
 * @command: The command being executed.
 * @status: A pointer to the exit status of the shell.
 */
void exit_shell(char **command, int *status)
{
	free2DArray(command);
	exit(*status);
}
