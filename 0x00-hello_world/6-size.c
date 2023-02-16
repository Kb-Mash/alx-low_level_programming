#include <stdio.h>

/**
 * main - a program that prints size of various types
 *
 * Return: 0 (Success)
 */

int main(void)
{
	char c;
	int n;
	long int lIn;
	long long int lLIn;
	float f;

	printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(c));

	printf("Size of an int: %lu byte(s)\n", (unsigned long)sizeof(n));

	printf("Size of a long int: %lu byte(s)\n", (unsigned long)sizeof(lIn));

	printf("Size of a long long int: %lu byte(s)\n", (unsigned long)sizeof(lLIn));

	printf("Size of a float: %lu byte(s)\n", (unsigned long)sizeof(f));

	return (0);
}
