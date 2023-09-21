#include "shell.h"

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
