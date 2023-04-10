#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure,
 * -1 if filename is NULL
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len, w;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		len = strlen(text_content);
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
