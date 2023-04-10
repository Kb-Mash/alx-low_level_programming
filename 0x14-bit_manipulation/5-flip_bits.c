#include "main.h"

/**
 * flip_bits - returns the number of bits you would
 * need to flip to get from one number to another
 * @n: the number to flip
 * @m: the number to flip to
 * Return: number of bits to flip a number
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int exclusive = n ^ m, num_bits = 0;

	while (exclusive)
	{
		num_bits += (exclusive & 1);
		exclusive >>= 1;
	}

	return (num_bits);
}
