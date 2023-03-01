#include "main.h"

/**
 * *_strncat - concatenates two strings
 * @src: string to append
 * @dest: string to append to
 * @n: the number of bytes from src to be appended to dest
 * Return: pointer to the resulting string dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, len = 0;

	for (i = 0; dest[i]; i++)
	{
		len++;
	}

	for (i = 0; src[i] && i < n; i++)
	{
		dest[len++] = src[i];
	}
	return (dest);
}
