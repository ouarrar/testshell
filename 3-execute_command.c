#include "shell.h"

/**
 * execute_command - Execute a given command.
 *
 * @parsed_command: An array of strings representing the command and its
 * arguments.
 * @argv: An array of strings representing the program's arguments.
 * @index: The index of the command in the input.
 * Return: The exit status of the executed command.
 */
int execute_command(char **parsed_command, char **argv, int index)
{
	char *full_command_path;
	pid_t child_pid;
	int status;

	full_command_path = getPath(parsed_command[0]);
	if (!full_command_path)
	{
		printNotFoundError(argv[0], parsed_command[0], index);
		free2DArray(parsed_command);
		return (127);
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(full_command_path, parsed_command, environ) == -1)
		{
			free(full_command_path), full_command_path = NULL;
			free2DArray(parsed_command);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free2DArray(parsed_command);
		free(full_command_path), full_command_path = NULL;
	}
	return (WEXITSTATUS(status));
}
