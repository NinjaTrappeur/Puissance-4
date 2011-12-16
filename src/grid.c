#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
char** createGrid(int nbLines,int nbColumns)
{
  int i,j;
  //Déclaration et allocation de mémoire de la grille de jeu
  char** grid = malloc(nbLines*sizeof(char*)); // 7 trous dans une ligne
  if(grid)// La mémoire de ligne a ete allouee
    {
      for(i=0;i<nbLines;++i)
	{
	  grid[i]=malloc(nbColumns*sizeof(char));
	  if(grid[i]==NULL)
	    return NULL;
	}
    }
  else
    return NULL; // La mémoire n'a pas été allouée...
  //Maintenant que la grille à étée crée il faut l'initialiser (elle sera vide par défaut)!
  for(i=0;i<nbLines;++i)
    for(j=0;j<nbColumns;++j)
      grid[i][j]=' ';
  return grid;
}


void freeGrid(char** grid,int nbLines, int nbColumns)
{
  int i;
  for(i=0;i<nbColumns;++i)
    free(grid[i]);// On libère d'abord les lignes
  free(grid); //Puis les colonnes
}

void displayGrid(char** grid, int nbLines, int nbColumns)
{
  int i,j;
  for(i=0;i<nbColumns;++i)
    printf("|%d|",i);//permet d'avoir la numérotation des colonnes
  for(i=0;i<nbLines;++i) // affichage du tableau
    {
      printf("\n");
      for(j=0;j<nbColumns;++j)
	{
	  printf("|%c|",grid[i][j]);
	}
    }
  printf("\n");
}
