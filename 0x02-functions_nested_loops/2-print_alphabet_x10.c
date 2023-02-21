#include "main.h"

/**
 * print_alphabet_x10 - prints 10 times the alphabet, in lowercase
 * Return: void
 */

void print_alphabet_x10(void)
{
char cha;
int i = 0;

while (i <= 9)
{
for (cha = 0; cha <= 'z'; cha++)
{
_putchar(cha);
}
_putchar('\n');
i++;
}
}
