#include "shell.h"
/**
 * getPath - Find the full path of a command.
 * @command: The name of the command.
 * Return: The full path of the command if found, or NULL if not found.
 */
char *getPath(char *command)
{
	char *pathEnv, *fullCommand, *directory;
	int index;
	struct stat fileStat;

	for (index = 0; command[index]; index++)
	{/* Check if the command is already a full path */
		if (command[index] == '/')
		{/* Check if the path exists */
			if (stat(command, &fileStat) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}
    /* Attempt to find the command in the PATH environment variable */
	pathEnv = getEnvironmentVariable("PATH");
	if (!pathEnv)
		return (NULL);
	/* Try to find the command in each directory specified in PATH */
	directory = strtok(pathEnv, ":");
	while (directory)
	{/* Calculate the size of the full command string */
		int fullCommandSize = _strlen(directory) + _strlen(command) + 2;

		fullCommand = malloc(fullCommandSize);
		if (fullCommand)
		{
			_strcpy(fullCommand, directory);
			_strcat(fullCommand, "/");
			_strcat(fullCommand, command);
			if (stat(fullCommand, &fileStat) == 0)
			{
				free(pathEnv);
				return (fullCommand);
			}
			free(fullCommand), fullCommand = NULL;
			directory = strtok(NULL, ":");
		}
	}
	free(pathEnv);
	return (NULL);
}
