#include "main.h"

/**
 * flip_bits - returns the number of bits you would
 * to to flip to get from one number to another
 * @n: first number
 * @m: second number
 * Return: number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int count = 0, exclusive = n ^ m;

	while (exclusive > 0)
	{
		count += (exclusive & 1);
		exclusive >>= 1;
	}

	return (count);
}
