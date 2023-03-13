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
	char *concat_str;
	int i, index = 0, len = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i]; i++)
	{
		len++;
	}

	for (i = 0; s2[i]; i++)
	{
		len++;
	}

	concat_str = malloc(sizeof(char) * (len + 1));

	if (concat_str == NULL)
		return (NULL);

	for (i = 0; s1[i]; i++)
		concat_str[index++] = s1[i];

	for (i = 0; s2[i]; i++)
		concat_str[index++] = s2[i];

	return (concat_str);
}
