#include "shell.h"

/**
 * tokenize_input - Tokenize a given string into an array of tokens.
 *
 * @input_line: The string to tokenize.
 *
 * Return: An array of tokens (strings).
 *         NULL if @input_line is NULL or if memory allocation fails.
 */
char **tokenize_input(char *input_line)
{
	char *token = NULL, *tmp = NULL;
	char **tokens = NULL;
	int token_count = 0, i = 0;

	if (!input_line)
		return (NULL);
	tmp = _strdup(input_line);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(input_line), input_line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		token_count++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	tokens = malloc(sizeof(char *) * (token_count + 1));

	if (!tokens)
	{
		free(input_line), input_line = NULL;

		return (NULL);
	}
	token = strtok(input_line, DELIM);

	while (token)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(input_line), input_line = NULL;
	tokens[i] = NULL;
	return (tokens);
}
