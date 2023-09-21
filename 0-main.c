#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @ac: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: The exit status of the shell.
 */
int main(int ac, char **argv)
{
	char *input_line = NULL, **parsed_command = NULL;
	int exit_status = 0, index = 0;
	(void) ac;

	while (1)
	{
		input_line = read_line();
		if (input_line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (exit_status);
		}
		index++;
		parsed_command = tokenize_input(input_line);
		if (!parsed_command)
			continue;

		if (is_builtin(parsed_command[0]))
			handle_builtin(parsed_command, argv, &exit_status, index);
		else
		exit_status = execute_command(parsed_command, argv, index);
	}
}
