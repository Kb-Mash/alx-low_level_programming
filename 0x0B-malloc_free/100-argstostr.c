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
	int avI, avStrI, strI = 0, len = 0;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	for (avI = 0; avI < ac; avI++)
	{
		for (avStrI = 0; av[avI][avStrI]; avStrI++)
		{
			len++;
		}
	}
	str = malloc(sizeof(char) * len);

	if (str == NULL)
	{
		return (NULL);
	}

	for (avI = 0; avI < ac; avI++)
	{
		for (avStrI = 0; av[avI][avStrI]; avStrI++)
		{
			str[strI++] = av[avI][avStrI];
		}
		str[strI] = '\n';
	}

	str[len] = '\0';

	return (str);
}
