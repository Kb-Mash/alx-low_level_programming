#include "main.h"

/**
 * print_alphabet - prints the alphabet, in lowercase
 * Return: void
 */

void print_alphabet(void)
{
	char cha = 'a';

	while (cha <= 'z')
	{
		_putchar(cha);
		cha++;
	}

	_putchar('\n');
}
