#include "search_algos.h"

/**
  * jump_search - Searches for a value in a sorted array
  *               of integers using jump search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the first index where the value is located
  */
int jump_search(int *array, size_t size, int value)
{
	int jump, prev, i, j = 0;

	if (array == NULL)
		return (-1);

	jump = sqrt(size);
	for (i = 0, prev = 0; i < (int)size; i += jump)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if ((i + jump >= (int)size || array[i + jump] >= value) && !j)
		{
			prev = i;
			i += jump;
			printf("Value found between indexes [%d] and [%d]\n", prev, i);
			if (i < (int)size)
				size = i + 1;
			i = prev - 1;
			jump = 1;
			j++;
		}
		else if (array[i] == value)
			return (i);
		prev = i;
	}
	return (-1);
}
