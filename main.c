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
	char *buffer;
	const char *delim = "\n\t\r";
	char **cmd;

	(void) argc;
	while (1)
	{
		buffer = get_cmd();

		if (buffer == NULL)
		{
			break;
		}
		else if(check_space(buffer))
		{
			continue;
		}

		cmd = parser(buffer, delim);

		pid = fork();

		if (pid == 0)
		{
			if (execve(cmd[0], cmd, environ) == -1)
			{
				free(cmd);
				perror(argv[0]);
			}

		}
		else
		{
			wait(NULL);
			free(buffer);
			free(cmd);
		}
	}	

	free(buffer);

	return (0);
}
