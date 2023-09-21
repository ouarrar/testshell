#include "shell.h"
/**
 *_strcmp - Entry point.
 *@s1: pointer to first string.
 *@s2: pointer to second string.
 *
 *Description:
 *compares two strings.
 *
 *Return: value less than 0 if string is less than the other.
 *value greater than 0 if string is greater than the other.
 *0 if strings are equal.
 */
int _strcmp(char *s1, char *s2)
{
	int counter, cmp;

	counter = 0;
	while (*(s1 + counter) == *(s2 + counter) && *(s1 + counter) != '\0')
	{
		counter++;
	}

	cmp = *(s1 + counter) - *(s2 + counter);
	return (cmp);
}
