#include "main.h"
#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2
 * Return: 0
 */

int main(void)
{
	int x = 0;
	long i = 1, j = 2;

	while (x < 50)
	{
		if (x == 0)
		{
			printf("%ld", i);
		}
		else if (x == 1)
			printf(", %ld", j);
		else
		{
			j += i;
			i = j - i;
			printf(", %ld", j);
		}
		x++;
	}
	printf("\n");
	return (0);
}
