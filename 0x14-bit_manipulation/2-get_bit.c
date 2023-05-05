#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: the bit to find its value
 * @index: index of the bit you want to get
 * Return: value of bit at index, else -1
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int divi;

	if (index >= (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	divi = 1 << index;
	if ((n & divi) == 0)
		return (0);

	return (1);
}
