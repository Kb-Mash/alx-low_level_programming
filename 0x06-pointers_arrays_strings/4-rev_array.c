#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: array
 * @n: number of elements in the array
 * Return: void
 */

void reverse_array(int *a, int n)
{
	int i, tmp, num = n - 1;

	for (i = 0; i < n; i++)
	{
		tmp = a[i];
		a[i] = a[num];
		a[num] = tmp;
	}
}
