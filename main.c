#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
//main max:30 lignes
int main()
{
  int nbLignes=6;//nombre de lignes + nombre de colonnes
  int nbColonnes=7;
  char** grille;
  grille=creationGrille(nbLignes,nbColonnes);//On alloue dynamiquement la grille
  //printf("%c",grille[2][2]);  
  //liberationGrille(grille,nbLignes,nbColonnes);//On libère la memoire prise par grille
  return 0;
}
