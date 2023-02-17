#include <stdio.h>

/**
 * main -Entry point
 * Description: prints numbers of base 16
 * Return: 0 (success)
 */

int main(void)
{
	int num;
	char cha;

	for (num = '0'; num <= '9'; num++)
		putchar(num);
	for (cha = 'a'; cha <= 'f'; cha++)
		putchar(cha);
	putchar('\n');
	return (0);
}
