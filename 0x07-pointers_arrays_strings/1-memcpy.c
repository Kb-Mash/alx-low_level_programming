#include "main.h"

/**
 * *_memcpy - copies memory area
 * @dest: pointer to the memory area to copy @src into
 * @src: source buffer to copy characters from
 * @n: the number of bytes to copy from @src
 * Return: pointer to the destination buffer
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
