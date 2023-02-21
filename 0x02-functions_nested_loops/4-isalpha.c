#include "main.h"

/**
 * _isalpha - checks for alphabetic character
 * @c: parameter for an argument
 * Return: 1 (success), 0 (fail)
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
