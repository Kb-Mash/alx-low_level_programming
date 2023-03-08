#include "main.h"

int _sqrt(int n, int root);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: integer to return sqrt of
 * Return: root
 */

int _sqrt_recursion(int n)
{
	int root = 0;

	if (n < 0)
		return (-1);
	if (n == 1)
		return (1);

	return (_sqrt(n, root));
}


/**
 * _sqrt - finds the natural sqrt of n
 * @n: integer to find the natural sqrt of
 * @root: sqrt value
 * Return: sqrt value
 */

int _sqrt(int n, int root)
{
	if (n == root * root)
		return (root);
	if (n / 2 == root)
		return (-1);

	return (_sqrt(n, root + 1));
}
