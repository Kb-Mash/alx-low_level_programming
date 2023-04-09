#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: pointer to the file name to read from
 * @letters: the number of letters it should read and print
 *
 * Return: actual number of letters it could read and print,
 * 0 if filename is NULL or if write fails
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd_o;
	ssize_t fd_r, fd_w;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);

	if (buf == NULL)
		return (0);

	fd_o = open(filename, O_RDONLY);
	fd_r = read(fd_o, buf, letters);
	fd_w = write(STDOUT_FILENO, buf, fd_r);

	if (fd_o == -1 || fd_r == -1 || fd_w == -1 || fd_w != fd_r)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(fd_o);

	return (fd_w);
}
