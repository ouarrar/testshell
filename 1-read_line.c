#include "shell.h"

/**
 * read_line - Read a line of input from the user.
 *
 * Return: A pointer to the string containing the user's input.
 *         NULL if an error occurs or if the input is empty.
 */
char *read_line(void)
{
	char *input_line = NULL;
	size_t buffer_size = 0;
	ssize_t characters_read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	characters_read = getline(&input_line, &buffer_size, stdin);

	if (characters_read == -1)
	{
		free(input_line);
		return (NULL);
	}

	return (input_line);
}
