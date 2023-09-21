#include "shell.h"

/**
 * _strlen - Entry point
 * @s: input string.
 *
 * Description:
 * Returns the length of a string.
 *
 * Return: length of @s.
 */

int _strlen(char *s)
{
	int length = 0;

	while (*(s + length) != '\0')
		length++;
	return (length);
}
