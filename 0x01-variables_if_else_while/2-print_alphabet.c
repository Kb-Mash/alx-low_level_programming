#include <stdio.h>

/**
 * main - prints alphabet in lowercase
 * Return: 0 (Success)
 */

int main(void)
{
	int cha;

	for (cha = 'a'; cha <= 'z'; cha++)
	{
		putchar(cha);
	}
	putchar('\n');
	return (0);
}
