#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the addition of positive numbers
 * @argc: number of arguments
 * @argv: array name
 * Return: 1 if one of the numbers contains symbols that are non-digits
 */
int main(int argc, char *argv[])
{
	int n, digit, sum = 0;

	for (n = 1; n < argc; n++)
	{
		for (digit = 0; argv[n][digit]; digit++)
		{
			if (argv[n][digit] < '0' || argv[n][digit] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		sum += atoi(argv[n]);
	}

	printf("%d\n", sum);

	return (0);
}
