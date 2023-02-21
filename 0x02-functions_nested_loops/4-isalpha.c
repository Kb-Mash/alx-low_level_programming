#include "main.h"

/**
 * _isalpha - checks for alphabetic character
 * @c: parameter for an argument
 * Return: 1 (success), 0 (fail)
 */

int _isalpha(int c)
{
	char low = 'a', upp = 'A';

	while (low <= 'z')
	{
		if (c == low)
			return (1);
	}

	while (upp <= 'Z')
	{
		if (c == upp)
			return (1);
	}
	return (0);
}
