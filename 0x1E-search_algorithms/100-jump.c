#include "search_algos.h"

/**
  * jump_search - Searches for a value in a sorted array
  *               of integers using jump search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the first index where the value is located.
  */

int jump_search(int *array, size_t size, int value)
{
	int jump_point, low, high, i;
	char *message;

	if (array == NULL)
		return (-1);

	jump_point = sqrt(size);
	for (i = 0; i < (int)size; i += jump_point)
	{
		if (value <= array[i])
		{
			low = i - 3;
			high = i;
			message = "Value found between indexes";
			printf("%s [%d] and [%d]\n", message, low, high);
			break;
		}
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
	}
	if (i > (int)size)
	{
		low = i - jump_point;
		high = low;
		message = "Value found between indexes";
		printf("%s [%d] and [%d]\n", message, low, i);
	}

	for (i = low; i <= high; i++)
	{
		printf("Value checked array[%d] = [%d]\n", low, array[i]);
		if (value == array[i])
			return (i);
	}
	return (-1);
}
