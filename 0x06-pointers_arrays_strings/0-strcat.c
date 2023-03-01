#include "main.h"

/**
 * *_strcat - concatenates two strings
 * @src: string to append
 * @dest: string to append to
 * Return: pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int i, len = 0;

	for (i = 0; dest[i]; i++)
	{
		len++;
	}

	for (i = 0; src[i]; i++)
	{
		dest[len++] = src[i];
	}

	return (dest);
}
