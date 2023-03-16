#include <stdlib.h>
#include "main.h"

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
	char *ptr;
	int len = 0, i, j, k;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i]; i++)
		len++;

	int size = len + n;

	ptr = malloc(sizeof(char) * (size + 1));

	if (ptr == NULL)
		return (NULL);

	for (j = 0; s1[j]; j++)
		ptr[j] = s1[j];

	for (k = 0; k < n; k++)
		ptr[i++] = s2[k];

	ptr[k] = '\0';

	return (ptr);
}
