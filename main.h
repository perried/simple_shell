#ifndef READ_CMD_H
#define READ_CMD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

char **parser(char *buffer, const char *delim);

#endif
