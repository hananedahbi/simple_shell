#include "shell.h"

int _exe(char **command, char **argv)
{
  pid_t child;
  int status;
  child = fork();
  if (child == 0)
  {
    if (execve(command[0],command,))
  }
}
