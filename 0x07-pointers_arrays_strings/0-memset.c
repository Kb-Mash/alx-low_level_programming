#include "main.h"

/**
 * *_memset -  fills memory with a constant byte
 * @s: pointer to the memory area to be filled
 * @b: constant char to fill the memory area with
 * @n: number of bytes of memory area to fill
 * Return: pointer to memory area
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
