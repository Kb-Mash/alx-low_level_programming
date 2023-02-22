#include "main.h"

/**
 * print_times_table -  prints the n times table, starting with 0
 * @n: parameter for an argument to be passed
 * Return: void
 */

void print_times_table(int n)
{
	int i = 0, j, k;

	if (n >= 0 && n <= 14)
	{
		while (i <= n)
		{
			for (j = 0; j <= n; j++)
			{
				k = i * j;
				if (k > 99)
				{
					_putchar(k / 100 + '0');
					_putchar((k / 10 % 10) + '0');
					_putchar(k % 10 + '0');
				}
				else if (k > 9)
				{
					_putchar(' ');
					_putchar(k / 10 + '0');
					_putchar(k % 10 + '0');
				}
				else if (j != 0)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar(k + '0');
				}
				else
				{
					_putchar(k + '0');
				}
				if (j != n)
				{
					_putchar(',');
					_putchar(' ');
				}
			}
			_putchar('\n');
			i++;
		}
	}
}
