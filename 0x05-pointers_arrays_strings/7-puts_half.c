#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: pointer for char parameter
 * Return: void
 */

void puts_half(char *str)
{
	int len = 0, i, n;

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

	i = n;

	while (i < len)
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
