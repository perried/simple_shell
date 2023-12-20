#include "main.h"

/**
 * parser - Breaks the input string into a single command
 * @buffer: Input buffer
 * @delim: Delimeter
 *
 * Return: a pointer to the processed commands
 */

char **parser(char *buffer, const char *delim)
{
	char **cmd;
	char *token;

	cmd = malloc(2 * sizeof(char*));
	token = strtok(buffer, delim);

	cmd[0] = token;
	cmd[1] = NULL;

	return (cmd);
}
