#include "main.h"

/**
 * check_space - Checks if a strings is a space with no other character
 * @str: A string to be checked
 *
 * Return - 1 if all spaces and 0 if not
 */

int check_space(char *str)
{
	int all_space = 1;
	int i = 0;

	while(str[i] != '\n')
	{
		if(str[i] != ' ')
		{
			all_space = 0;
			break;
		}
	}

	return (all_space);
}
