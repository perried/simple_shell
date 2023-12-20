#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFSIZE 1000

extern char **environ;

char *get_cmd();
int check_space(char *str);
char **parser(char *buffer, const char *delim);

#endif
