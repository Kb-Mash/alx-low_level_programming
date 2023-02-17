#include <stdio.h>

/**
 * main - prints alphabet except q and e
 * Return: 0 (Success)
 */

int main(void)
{
	char cha;

	for (cha = 'a'; cha <= 'z'; cha++)
	{
		if (cha == 'q' || cha == 'e')
			continue;
		putchar(cha);
	}

	putchar('\n');
	return (0);
}
