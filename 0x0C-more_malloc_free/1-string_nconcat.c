#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: bytes of s2
 * Return: pointer to allocated memory
 * NULL(fail)
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	int len, i, j;
	char *ptr;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i]; i++)
		len++;

	ptr = malloc(sizeof(char) * (len + n + 1));

	if (ptr == NULL)
		return (NULL);

	for (i = 0; s1[i]; i++)
		ptr[i] = s1[i];

	for (j = 0; j < n; j++)
		ptr[i++] = s2[j];

	ptr[i] = '\0';

	return (ptr);

}
