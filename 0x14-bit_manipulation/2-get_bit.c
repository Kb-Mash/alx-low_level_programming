#include "main.h"

/**
 * get_bit -  returns the value of a bit at a given index
 * @n: the decimal to get the bit from
 * @index: the index, starting from 0 of the bit to get
 * Return: the value of the bit at index
 * or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int size = sizeof(n) * 8;

	if (index >= size)
	{
		return (-1);
	}

	if ((n & (1 << index)) == 0)
	{
		return (0);
	}

	return (1);
}
