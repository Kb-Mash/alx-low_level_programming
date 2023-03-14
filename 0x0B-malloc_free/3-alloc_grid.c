#include <stdlib.h>

/**
 * **alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: width of the 2-dimensional array
 * @height: height of the 2-dimensional array
 * Return: pointer to the 2-dimensional array of integers
 * NULL (fail)
 */

int **alloc_grid(int width, int height)
{
	int **array = malloc(sizeof(int *) * height);
	int i, j;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	if (array == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		array[i] = malloc(sizeof(int) * width);

		if (array[i] == NULL)
		{
			for (; i >= 0; i--)
			{
				free(array[i]);
			}

			free(array);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			array[i][j] = 0;
		}
	}

	return (array);
}
