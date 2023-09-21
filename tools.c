#include "shell.h"

/**
 * free2DArray - Frees memory allocated for a 2D array of strings.
 *
 * @array: A pointer to the 2D array of strings.
 */
void free2DArray(char **array)
{
	int index;

	if (!array)
		return;
	for (index = 0; array[index]; index++)
	{
		free(array[index]), array[index] = NULL;
	}
	free(array), array = NULL;
}

/**
 * printNotFoundError - Print a "not found" error message.
 *
 * @programName: The name of the program.
 * @command: The command that was not found.
 * @index: The index where the error occurred.
 */
void printNotFoundError(char *programName, char *command, int index)
{
	char *indexStr;
	char errorMessage[] = ": not found\n";

	indexStr = _itoa(index);

	write(STDERR_FILENO, programName, _strlen(programName));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, indexStr, _strlen(indexStr));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, errorMessage, _strlen(errorMessage));

	free(indexStr);
}

/**
 * _itoa - Convert an integer to a string.
 *
 * @n: The integer to convert.
 *
 * Return: A pointer to the resulting string.
 */
char *_itoa(int n)
{/*Maximum number of digits for a 64-bit integer*/
	char buffer[20];
	int index = 0;

	if (n == 0)
	{/*Special case for zero*/
		buffer[index++] = '0';
	}
	else
	{/*Convert each digit to a character*/
		while (n > 0)
		{
			buffer[index++] = (n % 10) + '0';
			n /= 10;
		}
	}
	/*Null-terminate the string*/
	buffer[index] = '\0';
	reverse_string(buffer, index);

	/*Duplicate the string using _strdup*/
	return (_strdup(buffer));
}

/**
 * reverse_string - Reverse a string in place.
 *
 * @str: The string to reverse.
 * @len: The length of the string.
 */
void reverse_string(char *str, int len)
{
	char temp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
