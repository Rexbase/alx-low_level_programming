#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - Copies the content of a file to another file
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int fd_r, fd_w, bytes_read, bytes_written;
	char buf[BUFSIZ];

	if (argc != 3)
	{
		fprintf(stderr, "Usage: cp file_from file_to\n");
		exit(EXIT_FAILURE);
	}

	fd_r = open(argv[1], O_RDONLY);
	if (fd_r == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fd_w = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_w == -1)
	{
		fprintf(stderr, "Error: Can't write to file %s\n", argv[2]);
		close(fd_r);
		exit(EXIT_FAILURE);
	}

	while ((bytes_read = read(fd_r, buf, BUFSIZ)) > 0)
	{
		bytes_written = write(fd_w, buf, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			fprintf(stderr, "Error: Can't write to file %s\n", argv[2]);
			close(fd_r);
			close(fd_w);
			exit(EXIT_FAILURE);
		}
	}

	if (bytes_read == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		close(fd_r);
		close(fd_w);
		exit(EXIT_FAILURE);
	}

	if (close(fd_r) == -1 || close(fd_w) == -1)
	{
		perror("Error: Can't close file descriptor");
		exit(EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
