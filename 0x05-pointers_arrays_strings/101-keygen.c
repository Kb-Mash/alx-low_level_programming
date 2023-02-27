#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random passwords for 101-crackme
 * Return: 0 (Success)
 */
int main(void)
{
	int sum;
	char password;

	srand(time(NULL));
	while (sum <= 2645)
	{
		password = rand() % 128;
		sum += password;
		putchar(password);
	}
	putchar(2772 - sum);
	return (0);
}
