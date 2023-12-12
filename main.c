#include "main.h"

/**
 * main - Main function of the program
 *
 * Return: returns 0 if successful
 */
int main(void)
{
	size_t bufsize = 0;
	char *buffer = NULL;
	const char *delim = "\n\t\r";
	char *token;
	char *argv[2];

	while (true)
	{
		char prompt[] = {'>', '>', '>', ' '};

		write(1, &prompt, 4);
		getline(&buffer, &bufsize, stdin);

		token = strtok(buffer, delim);
		argv[0] = token;
		argv[1] = NULL;

		if (execve(argv[0], argv, environ) == -1)
			perror("hsh");

		free(buffer);
	}

	return (0);
}
