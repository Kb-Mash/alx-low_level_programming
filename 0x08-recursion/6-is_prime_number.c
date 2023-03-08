#include "main.h"

int _divisible(int n, int divi);

/**
 * is_prime_number - checks if a number is prime.
 * @n: integer to be checked
 * Return: 0 (success), 1 (fail)
 */

int is_prime_number(int n)
{
	int divi = 2;

	if (n <= 1)
		return (0);

	if (n == 2 && n == 3)
		return (1);

	return (_divisible(n, divi));
}

/**
 * _divisible - checks if n is divisible by divi
 * @n: integer to be checked
 * @divi: divisor
 * Return: 0 (success), 1 (fail)
 */

int _divisible(int n, int divi)
{
	if (n % divi == 0)
		return (0);
	else
		return (1);

	return (_divisible(n, divi + 1));
}
