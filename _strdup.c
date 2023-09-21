#include "shell.h"
#include <stdlib.h>
/**
 * _strdup - Duplicates a string in memory.
 * @str: The input string to duplicate.
 *
 * Return: A pointer to the newly allocated duplicated string, or NULL if
 *         memory allocation fails or if str is NULL.
 *
 * Author: MedAMEZZANE
 */
char *_strdup(char *str)
{
	char *new_str;          /* Pointer to the duplicated string */
	int length = 0;         /* Length counter for the input string */
	int i = 0;              /* Loop counter */

	if (str == NULL)
		return (NULL);      /* Return NULL if input string is NULL */

	while (str[length])
		length++;           /* Calculate the length of the input string */

	/* Allocate memory for the duplicated string */
	new_str = malloc(sizeof(char) * (length + 1));
	if (new_str == NULL)
		return (NULL);      /* Return NULL if memory allocation fails */

	while (str[i])
	{
		/*Copy each character from the input string to the duplicated string*/
		new_str[i] = str[i];
		i++;
	}
	/* Add null-terminator at the end of the duplicated string */
	new_str[i] = '\0';

	return (new_str);       /* Return the pointer to the duplicated string */
}
