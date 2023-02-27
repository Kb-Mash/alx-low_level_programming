#include "main.h"

/**
 * _puts -  prints a string, followed by a new line, to stdout
 * @str: pointer to a str parameter
 * Retur: void
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_ptchar(str[i]);
		i++;
	}
	_putchar('\n');
}
