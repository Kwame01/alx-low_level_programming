#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 *
 * @filename: Pointer to the file name
 * @letters: Number of letters to read and print
 *
 * Return: Number of letters it could read and print, or 0 if failed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t read_chars, write_chars;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters));
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	read_chars = read(fd, buffer, letters);
	close(fd);

	if (read_chars == -1)
	{
		free(buffer);
		return (0);
	}

	write_chars = write(STDOUT_FILENO, buffer, read_chars);

	free(buffer);

	if (read_chars != write_chars)
		return (0);

	return (write_chars);
}

