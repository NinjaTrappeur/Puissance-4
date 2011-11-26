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
  char** grille = malloc(nbLignes*nbColonnes*sizeof(char*)); // 7 trous dans une ligne
  if(grille)// La mémoire de ligne a ete allouee
    {
      printf("1: %d\n",sizeof(*grille));

      for(i=0;i<nbColonnes;++i)
	grille[i]=malloc(nbLignes*sizeof(char));
    }
  else
    printf("Problème alloc!!!"); // La mémoire n'a pas été allouée...
  //Maintenant que la grille à étée crée il faut l'initialiser!
  if(grille[1]==NULL)
    printf("Problème!");
  else
    printf("2: %d %d\n",sizeof(*grille),sizeof(grille[1]));
     //for(i=0;i<1;++i)
     //for(j=0;j<1;++i)
     //grille[i][j]=' ';
     //return grille;
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
