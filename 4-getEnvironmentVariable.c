#include "shell.h"
/**
 * getEnvironmentVariable - Get the value of an environment variable.
 *
 * @variableName: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *getEnvironmentVariable(char *variableName)
{
	char *currentEntry, *key, *value, *environmentValue;
	int index;

	for (index = 0; environ[index]; index++)
	{
		currentEntry = _strdup(environ[index]);
		key = strtok(currentEntry, "=");
		if (_strcmp(key, variableName) == 0)
		{
			value = strtok(NULL, "\n");
			environmentValue = _strdup(value);
			free(currentEntry), currentEntry = NULL;
			return (environmentValue);
		}
		free(currentEntry), currentEntry = NULL;
	}
	return (NULL);
}
