#include "main.h"
#include <stdio.h>

void _cp(const char *src, const char *dest);

/**
 * main - entry point
 * @ac: number of arguments
 * @av: array of pointers to arguments
 * Return: 0 (success)
 */

int main(int ac, char *av[])
{
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	_cp(av[1], av[2]);

	return (0);
}

/**
 * _cp - copies content of one file to another file
 * @src: the file to copy from
 * @dest: the file to copy to
 */

void _cp(const char *src, const char *dest)
{
	char buffer[1024];
	int from, to;
	ssize_t w, r;

	from = open(src, O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(dest, O_WRONLY | O_APPEND);

	} while (r > 0);

	if (close(from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	}

	if (close(to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to);
		exit(100);
	}
}
