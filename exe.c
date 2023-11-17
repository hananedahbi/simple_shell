#include "shell.h"

int _exe(char **command, char **argv)
{
  pid_t child;
  int status;
  child = fork();
  if (child == 0)
  {
    if (execve(command[0],command,) == -1)
    {
      perror(argv[0]);
      freearg(command);
      exit(0);
    }
  }
  else
  {
    waitpid(child, &status, 0);
    freearg(command);
  }
  return (WEXITSTATUS(status));
}
