#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: converted number,
 * otherwise 0 if b is NULL or contains chars not 0 or 1
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal = 0;
	int i = 0;

	if (b == NULL || b[i] == '\0')
		return (0);

	for (; b[i]; i++)
	{
		if (b[i] == '0' || b[i] == '1')
		{
			decimal <<= 1;
			decimal += b[i] - '0';
		}
		else
		{
			return (0);
		}

	}

	return (decimal);
}
