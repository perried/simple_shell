#include "main.h"

/**
 * main - Main function of the program
 *
 * Return: returns 0 if successful
 */
int main(void)
{
	pid_t pid;
	size_t bufsize = 0;
	char *buffer = NULL;
	const char *delim = "\n\t\r";
	char *token;
	char *argv[2];
	int status = 0;

	while (1)
	{
		char prompt[] = {'>', '>', '>', ' '};

		write(1, &prompt, 4);
		status = getline(&buffer, &bufsize, stdin);

		if (status == -1)
			break;

		token = strtok(buffer, delim);
		argv[0] = token;
		argv[1] = NULL;

		pid = fork();

		if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
				perror("hsh");

		}
		else
		{
			wait(NULL);
		}

	}

	return (0);
}
