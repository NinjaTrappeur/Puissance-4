#include <stdio.h>
#include <stdlib.h>
#include "moteur.h"
#include "grille.h"

//main max:30 lignes
int main()
{
  int nbLignes=6,nbColonnes=7;//nombre de lignes + nombre de colonnes
  char** grille;
  grille=creationGrille(nbLignes,nbColonnes);//On alloue dynamiquement la grille
  if (grille==NULL)//si l'alloction n'a pas fonctionné...
    {
      printf("Mémoire non alouée");
      return -1;
    }
  else
    {
      playerInterface(grille,nbColonnes,nbLignes);
      liberationGrille(grille,nbLignes,nbColonnes);//On libère la memoire prise par grille
      return 0;
    }
}
