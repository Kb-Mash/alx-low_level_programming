#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 * @n: parameter, number of times the character \ should be printed
 * Return: void
 */

void print_diagonal(int n)
{
	int i = 0, j;

	if (n <= 0)
	{
		_putchar('\n');
	}

	while (i < n)
	{
		for (j = 0; j < n; j++)
		{
			if (j == i)
			{
				_putchar('\\');
				break;
			}
			else if (j < i)
			{
				_putchar(' ');
			}
		}
		_putchar('\n');
		i++;
	}
}
