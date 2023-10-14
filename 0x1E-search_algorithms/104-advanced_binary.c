#include "search_algos.h"

int advanced_binary_helper(int *array, int min, int max, int value);

/**
 * advanced_binary - Searches for a value in an array by splitting the arrayin
 * half every time.
 * @array: List of integer numbers sorted in an ascending order
 * @size: The total amount of numbers in the array.
 * @value: The element that the algorithm is trying to find.
 * Return: The index in which the value is located. Or if it does not exits
 * or array is NULL -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (advanced_binary_helper(array, 0, size - 1, value));
}

/**
 * advanced_binary_helper - Searches recursively for a value in a sorted
 *                             array of integers using binary search.
 *
 * @array: pointer to the first element of the [sub]array to search
 * @min: starting index of the [sub]array to search
 * @max: ending index of the [sub]array to search
 * @value: value to search for
 *
 * Return: index if found, else -1
 */

int advanced_binary_helper(int *array, int min, int max, int value)
{
	int mid = (max + min) / 2;
	int i;

	if (min <= max)
	{
		printf("Searching in array: ");
		for (i = min; i <= max; i++)
		{
			printf("%d", array[i]);
			if (i < max)
				printf(", ");
			else
				printf("\n");
		}
		if (array[mid] > value)
			return (advanced_binary_helper(array, min, mid, value));
		else if (array[mid] < value)
			return (advanced_binary_helper(array, mid + 1, max, value));
		else if (array[mid] == value && array[mid - 1] == value)
			return (advanced_binary_helper(array, min, mid, value));
		else if (array[mid] == value)
			return (mid);
	}
	return (-1);
}
