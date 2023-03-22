#include "3-calc.h"

/**
 * get_op_func - selects the correct function to perform the operation
 * @s: operator passed as argument to the program
 * Return: pointer to the function corresponding
 * to the operator given as a parameter
 */

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
	{"+", op_add},
	{"-", op_sub},
	{"*", op_mul},
	{"/", op_div},
	{"%", op_mod},
	{NULL, NULL}
	};
	int i;

	for (i = 0; ops[i].op; i++)
	{
		if (strcmp(ops[i].op, s) == 0)
			return (ops[i].f);
	}

	return (NULL);
}
