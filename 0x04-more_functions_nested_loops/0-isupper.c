#include "main.h"

/**
 * _isupper -  checks for uppercase character
 * @c: integer parameter
 * Return: 1 if argument is upercase, 0 otherwise
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}
