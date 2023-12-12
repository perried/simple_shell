#ifndef READ_CMD_H
#define READ_CMD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;
void getcmd(char **buffer, size_t *bufsize);

#endif
