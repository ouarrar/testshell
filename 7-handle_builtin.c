#include "shell.h"

/**
 * handle_builtin - Handles built-in commands like "exit" and "env".
 * @command: The command to handle.
 * @argv: The arguments passed to the program.
 * @status: The exit status of the shell.
 * @idx: The index of the current command.
 */
void handle_builtin(char **command, char **argv, int *status, int idx)
{
	(void)argv;
	(void)idx;

	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, status);

	else if (_strcmp(command[0], "env") == 0)
		print_env(command, status);
}
