#include <stdlib.h>

/**
 * *str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: pointer to cocatenated string
 * NULL (fail)
 */

char *str_concat(char *s1, char *s2)
{
	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}

	int i, j, len = 0, index = 0;

	for (i = 0; s2[i]; i++)
	{
		len++;
	}

	for (j = 0; s2[j]; j++)
	{
		len++;
	}

	char *concat_str = malloc(sizeof(char) * (len + 1));

	if (concat_str == NULL)
	{
		return (NULL);
	}

	for (i = 0; s1[i]; i++)
	{
		concat_str[index++] = s1[i];
	}

	for (j = 0; s2[j]; j++)
	{
		concat_str[index++] = s2[j];
	}

	return (concat_str);
}
