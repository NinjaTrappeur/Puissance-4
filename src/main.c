#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
#include "grid.h"

//main max:30 lignes
int main()
{
  int nbLines=6,nbColumns=7;//nombre de lignes + nombre de colonnes
  char** grid;
  grid=createGrid(nbLines,nbColumns);//On alloue dynamiquement la grille
  if (grid==NULL)//si l'alloction n'a pas fonctionné...
    {
      printf("Mémoire non alouée");
      return -1;
    }
  else
    {
      playerInterface(grid,nbColumns,nbLines);
      freeGrid(grid,nbLines,nbColumns);//On libère la memoire prise par grille
      return 0;
    }
}
