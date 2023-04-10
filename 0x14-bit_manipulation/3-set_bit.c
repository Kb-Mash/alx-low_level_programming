#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: the number to set
 * @index: the index at which to set bit
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	int size = sizeof(unsigned long int) * 8;

	if (index > size)
		return (-1);

	*n |= (1 << index);

	return (1);
}
