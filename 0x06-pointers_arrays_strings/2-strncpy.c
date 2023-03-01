#include "main.h"

/**
 * *_strncpy -  copies a string
 * @src: string to be copied
 * @dest:storing the copied string
 * @n: number of bytes to be copied
 * Return: pointer to the resulting string dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, len = 0;

	for (i = 0; src[i]; i++)
	{
		len++;
	}

	for (i = 0; src[i] && i < n; i++)
	{
		dest[i] = src[i];
	}

	for (i = len; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
