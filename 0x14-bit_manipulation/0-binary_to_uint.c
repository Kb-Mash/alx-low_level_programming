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
	unsigned int decimal = 0, weight = 1, len = _strlen(b);
	int i;

	if (b == NULL)
		return (0);

	for (i = len - 1; i >= 0; i--)
	{
		if (b[i] != '1' && b[i] != '0')
			return (0);

		if (b[i] == '1')
			decimal += weight;

		weight *= 2;
	}

	return (decimal);
}
