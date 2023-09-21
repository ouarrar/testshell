#include "shell.h"

/**
 * is_builtin - Checks if a given command is a built-in command.
 * @command: The command to check.
 *
 * Return: 1 if it's a built-in command, 0 otherwise.
 */
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
