#include "main.h"

/**
 * set_string - sets value of a pointer to a char
 * @s: double pointer to a string
 * @to: pointer to string to set s
 * Return: void
 */
void set_string(char **s, char *to)
{
	*s = to;
}
