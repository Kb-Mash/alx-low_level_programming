#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer parameter
 * Return: void
 */

void rev_string(char *s)
{
	int len = 0, revlen, i = 0;
	char tmp;

	while (s[len] != '\0')
	{
		len++;
	}

	revlen = len - 1;

	while (i < len / 2)
	{
		tmp = s[i];
		s[i] = s[revlen];
		s[revlen--] = tmp;

		i++;
	}
}
