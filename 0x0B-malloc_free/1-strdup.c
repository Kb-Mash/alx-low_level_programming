#include <stdlib.h>

/**
 * *_strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: pointer of the string to copied
 * Return: pointer to the duplicated string,
 * NULL if str = NULL,
 * NULL if insufficient memory was available
 */

char *_strdup(char *str)
{
	int i, len = 0;
	char *duplicate;

	if (str == NULL)
	{
		return (NULL);
	}

	while (*str)
	{
		len++;
	}

	duplicate = malloc(sizeof(char) + (len + 1));

	if (duplicate == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i]; i++)
	{
		duplicate[i] = str[i];
	}

	duplicate[len] = '\0';

	return (duplicate);

}
