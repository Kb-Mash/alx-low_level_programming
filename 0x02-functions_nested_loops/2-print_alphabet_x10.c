#include "main.h"

/**
 * print_alphabet_x10 - prints 10 times the alphabet, in lowercase
 * Return: void
 */

void print_alphabet_x10(void);
{
char cha = 'a';
int i = 0;

while (i <= 10)
{
while (cha <= 'z')
{
_putchar(cha);
cha++;
}
_putchar('\n');
i++;
}
}
