#include "shell.h"
/**
 * _strcat - Entry point
 * @dest: string with concatenation
 * @src: string to be concatenated
 *
 * Description:
 * Function that concatenates two strings.
 *
 * Return: Pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int lengthD, lengthS;

	lengthD = 0;
	lengthS = 0;

	while (*(dest + lengthD))
		lengthD++;
	while ((*(dest + lengthD) = *(src + lengthS)))
	{
		lengthD++;
		lengthS++;
	}
	return (dest);
}
