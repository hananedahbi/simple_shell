#include "shell.h"

void freearg(char **dut)
{
  int i;
  if (!dut)
  return;
for(i = 0; dut[i]; i++)
{
   free(dut[i]);
  dut[i] = NULL;
}


free(dut); dut = NULL;
}
