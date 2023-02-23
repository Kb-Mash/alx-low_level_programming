#include "main.h"
#include <stdio.h>
#include <math.h>

/**
 * main - finds and prints the largest prime factor of the number 612852475143
 * Return: 0 (Success)
 */

int main(void)
{
	long n = 612852475143;
	int i;

	for (i = (int) sqrt(n); i > 2; i++)
	{
		if (n % i == 0)
		{
			printf("%d\n", i);
			break;
		}
	}
	return (0);
}
