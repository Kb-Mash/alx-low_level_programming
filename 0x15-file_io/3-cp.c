#include "main.h"

/**
 * main - entry point
 * @argc: the number of arguments
 * @argv: the array of pointers pointing to the arguments
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	_cp(argv[1], argv[2]);

	return (0);
}

/**
 * _cp - copies the content of a file to another file
 * @file_from: source to copy content from
 * @file_to: destination to copy content to
 */

void _cp(const char *file_from, const char *file_to)
{
	int fd_to, fd_from, r, w;
	char buffer[1024];

	fd_from = open(file_from, O_RDONLY);
	if (!file_from || fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	r = read(fd_from, buffer, 1024);
	w = write(fd_to, buffer, r);

	while (r > 0)
	{
		if (w != r || fd_to == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	_close(fd_from);
	_close(fd_to);
}

/**
 * _close - close the file descriptor
 * @fd: file descriptor to close
 */

void _close(int fd)
{
	int c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
