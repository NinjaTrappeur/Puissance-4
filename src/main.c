#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "engine.h"
#include "grid.h"

int main(int argc, char **argv)
{
  int nbLines=6,nbColumns=7,noGui=0,log=0,quit=0,megafunMode=0;
  char** grid;
  grid=createGrid(nbLines,nbColumns);
  if (grid==NULL)
    {
      printf("Mémoire non alouée");
      return -1;
    }
  else
    {
      defineParameters(argc,argv,&noGui,&megafunMode,&log,&quit);
      if(!quit)
	{
	  playerInterface(grid,nbColumns,nbLines,noGui,log,megafunMode);
	  freeGrid(grid,nbLines,nbColumns);
	}
    }
  return 0;
}
