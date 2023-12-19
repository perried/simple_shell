#include "main.h"

/**
 * main - Main function of the program
 * @argc: argument count
 * @argv: argument vector
 * Return: returns 0 if successful
 */
int main(int argc, char *argv[])
{
	pid_t pid;
	size_t bufsize = 0;
	char *buffer = NULL;
	const char *delim = "\n\t\r";
	char *token;
	char *av[2];
	ssize_t status;

	(void) argc;
	while (1)
	{

		write(1, &"#cisfun$ ", 10);
		status = getline(&buffer, &bufsize, stdin);
		if (status == -1 || status == EOF)
			return (-1);

		token = strtok(buffer, delim);

		if (token != NULL || token != " ")
		{
			av[0] = token;
			av[1] = NULL;
		}
		else
			continue;

		pid = fork();

		if (pid == 0)
		{
			if (execve(av[0], av, environ) == -1)
			{
				perror(argv[0]);
			}

		}
		else
		{
			wait(NULL);
		}

	}

	free(buffer);

	return (0);
}
