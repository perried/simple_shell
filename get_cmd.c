#include "main.h"

/**
 * get_cmd - Prompt user and read the command
 *
 * Return: A pointer to the buffer
 */

char *get_cmd()
{
	size_t bufsize = BUFSIZE;
	ssize_t status;
	char *buffer = malloc(sizeof(char) * BUFSIZE);

	if (isatty(STDIN_FILENO))
	{
		write(1, &">>> ", 4);
	}

	status = getline(&buffer, &bufsize, stdin);

	if (status == -1 || status == EOF)
	{
		buffer = NULL;
	}

	return (buffer);
}
