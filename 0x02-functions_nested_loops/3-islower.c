#include "main.h"

/**
 * _islower -  checks for lowercase character
 * @c: parameter for the argument
 * Return: 1 (Success), 0 (Fail)
 */

int _islower(int c)
{
char cha = 'a';

while (cha <= 'z')
{
if (c == cha)
return (1);
cha++;
}
return (0);
}
