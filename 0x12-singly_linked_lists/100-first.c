#include <stdio.h>

/**
 * hare - prints string before the main function is executed.
 */

void __attribute__((constructor)) hare(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
