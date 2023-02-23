#include "main.h"

/**
 * print_triangle - prints triangle
 * @size: argument, size of the triangle
 * Return: void
 */

void print_triangle(int size)
{
	int i, j;

	if (size <= 0)
	{
		_putchar('\n');
	}

	for (i = 0; i < size; i++)
	{
		for (j = size - i; j > 0; j--)
		{
			_putchar(' ');
		}
		for (j = 0; j < i; j++)
		{
			_putchar('#');
		}
		if (i == j)
		{
			continue;
		}
		_putchar('\n');
	}
}
