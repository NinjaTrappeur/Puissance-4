#include <stdio.h>
#include <stdlib.h>

enum Joueur{ 
  A, B
};
//Coordonees pion + type (X ou O)
struct Pion{
  int x;
  int y;
  enum Joueur joueur;
};


char** creationGrille(int nbLignes,int nbColonnes)
{
  int i,j;
  //Déclaration et allocation de mémoire de la grille de jeu
  char* ligne = NULL;
  char** grille = malloc(nbLignes*sizeof(char*)); // 7 trous dans une ligne
  if(grille)// La mémoire de ligne a ete allouee
    {
      for(i=0;i<nbLignes;++i)
	{
	  grille[i]=malloc(nbColonnes*sizeof(char));
	  if(grille[i]==NULL)
	    return NULL;
	}
    }
  else
    return NULL; // La mémoire n'a pas été allouée...
  //Maintenant que la grille à étée crée il faut l'initialiser (elle sera vide par défaut)!
  for(i=0;i<nbLignes;++i)
    for(j=0;j<nbColonnes;++j)
      grille[i][j]=' ';
  return grille;
}


void liberationGrille(char** grille,int nbLignes, int nbColonnes)
{
  int i;
  for(i=0;i<nbColonnes;++i)
    free(grille[i]);// On libère d'abord les lignes
  free(grille); //Puis les colonnes
}

void affichageGrille(char** grille, int nbLignes, int nbColonnes)
{

}
