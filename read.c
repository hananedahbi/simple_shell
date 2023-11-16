#include "shell.h"

char *line = NULL;
size_t len = 0;
ssize_t n;
n = getline(&line, &len, stdin);
if (n == -1)
{
  
}
