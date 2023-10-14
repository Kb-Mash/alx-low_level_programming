#include "search_algos.h"

int interpolation_helper(int *array, int min, int max, int value);

/**
 * interpolation_search - Searches for a number in an array
 * @array: List of integers in which the potential number might be located.
 * @size: The length of the list.
 * @value: The value we are trying to find.
 * Return: The first index where value is located, or if value is not present
 * in array or if array is NULL, your function must return -1
 */

int interpolation_search(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (interpolation_helper(array, 0, size - 1, value));
}

/**
 * interpolation_helper - Searches for a number in an array
 * @array: array of integers in which the potential number might be located
 * @min: min
 * @max: max
 * @value: value to find
 * Return: index if found, else -1
 */

int interpolation_helper(int *array, int min, int max, int value)
{
	size_t pos = min + (((double)(max - min) /
		(array[max] - array[min])) * (value - array[min]));

	if ((int)pos > max)
	{
		printf("Value checked array[%ld] is out of range\n", pos);
		return (-1);
	}
	if (min <= max)
	{
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] > value)
			return (interpolation_helper(array, 0, pos - 1, value));
		else if (array[pos] < value)
			return (interpolation_helper(array, pos + 1, max, value));
		else if (array[pos] == value)
			return (pos);
	}
	return (-1);
}
