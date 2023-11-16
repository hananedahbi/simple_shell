#include "shell.h"

void arg(char **dut)
{
  int i;
  return;
for(i = 0; dut[i]; i++)
{
   free(dut[i]);
  dut[i] = NULL;
}


free(dut); dut = NULL;
}
