#include <stdio.h>
#include "shell.h"

/**
 * _strcpy - Entry point
 * @dest: Address where string will be copied to (destination).
 * @src: Original string to be copied (source).
 *
 * Description:
 * Copies the string pointed to by src,
 * including the terminating null byte, to the
 * buffer pointed to by dest.
 *
 * Return: Pointer to the destination address.
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	/* copy the null byte */
	dest[i] = src[i];
	return (dest);
}
