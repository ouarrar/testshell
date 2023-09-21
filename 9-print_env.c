#include "shell.h"

/**
 * print_env - Prints the environment variables to the standard output.
 * @command: The command being executed (unused in this function).
 * @status: A pointer to the exit status of the shell.
 */
void print_env(char **command, int *status)
{
		int i;

		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		free2DArray(command);
		(*status) = 0;
}
