#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: pointer for char parameter
 * Return: void
 */

void puts_half(char *str)
{
	int len = 0, n;

	while (str[len] != '\0')
	{
		len++;
	}

	if (n % 2 != 0)
	{
		n = (len - 1) / 2;
	}
	else
	{
		n = len / 2;
	}

	while (n <= len)
	{
		_putchar(str[n]);
		n++;
	}
	_putchar('\n');
}