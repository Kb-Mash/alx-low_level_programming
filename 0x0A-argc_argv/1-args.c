#include "main.h"
#include <stdio.h>

/**
 * main - prints the number of arguements passed into it
 * @argc: number of arguments
 * @argv: array name
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	if (argv[0])
	{
		printf("%d\n", argc - 1);
	}

	return (0);
}
