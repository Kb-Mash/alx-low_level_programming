#include <stdlib.h>

/**
 * *argstostr - concatenates all the arguments of your program
 * @ac: argument count
 * @av: argument array/vector
 * Return: pointer to new string, NULL (fail)
 */

char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, str_i = 0, size = ac;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			size++;
	}

	str = malloc(sizeof(char) * size + 1);

	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			str[str_i++] = av[i][j];

		str[str_i++] = '\n';
	}

	str[size] = '\0';

	return (str);
}
