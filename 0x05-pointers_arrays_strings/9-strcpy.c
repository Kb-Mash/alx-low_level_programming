#include "main.h"

/**
 * *_strcpy - copies a string
 * @dest: A buffer to copy the string to
 * @src: The string to copy
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
