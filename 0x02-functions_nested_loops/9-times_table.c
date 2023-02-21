#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 * Return: void
 */

void times_table(void)
	{
	int i = 0, j, k;

	while (i < 10)
	{
		for (j = 0; j < 10; j++)
		{
			k = i * j;
			if (j == 0)
			{
				_putchar(k + '0');
			}
			if (k < 10 && j != 0)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar(k + '0');
			}
			else if (k >= 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar((k / 10) + '0');
				_putchar((k % 10) + '0');
			}
		}
		_putchar('\n');
		i++;
	}
}
