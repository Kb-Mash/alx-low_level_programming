#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of pointers to the arguments
 * Return: 0 (success)
 *
 * Description: if the argument count is incorrect - exit code 97
 * if file_from does not exist or cannot be read - exit code 98
 * if file_to cannot be created or written to - exit code 99
 * if file_to or file_from cannot be closed - exit code 100
 */

int main(int argc, char *argv[])
{
	int r, w, from, to;
	char buffer[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	from = open(argv[1], O_RDONLY);
	if (from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);

	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	while ((r = read(from, buffer, 1024)) > 0)
	{
		w = (write(to, buffer, r));
		if (w != r)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	}

	if (r == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);

	if (close(from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from), exit(100);

	if (close(to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to), exit(100);

	return (0);
}
