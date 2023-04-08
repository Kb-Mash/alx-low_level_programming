#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the decimal number to convert to a binary number
 */

void print_binary(unsigned long int n)
{
	unsigned int binary;
	int i, size = sizeof(n) * 8;

	for (i = size - 1; i >= 0; i--)
	{
		binary = n >> i;
		if (binary & 1)
			_putchar('1');
		else
			_putchar('0');
	}
}
