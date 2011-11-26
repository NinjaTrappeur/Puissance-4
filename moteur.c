#include <stdio.h>

void placerPion(char** grille, int nbLignes, int nbColonnes, int colonneCible, char pion)
{
  int i=0,place=0;
  while(place==0)
    {
      if(grille[i][colonneCible]!=' ')
	{
	  printf("allo?");
	  grille[i-1][colonneCible]=pion;
	  place=1;
	}
     else if(i=(nbLignes))
	{
	  grille[i-1][colonneCible]=pion;
	  place=1;
	}
      else
	++i;
    }
}

void interfaceJoueur(char** grille, int nbColonnes, int nbLignes)
{
  int i=0,gagne=0,choix;
  char pion;
  while(gagne==0)
    {
      affichageGrille(grille,nbLignes,nbColonnes);
      if(i%2==0)
	{
	  printf("\nJoueur 1, choisissez une colonne dans laquelle insérer votre pion:");
	  pion='X';
	}
      else
	{
	  printf("\nJoueur 2, choisissez une colonne dans laquelle insérer votre pion:");
	  pion='O';
	}
      scanf("%d",&choix);
      if(choix<0 || choix>nbColonnes) //si choix fantaisiste
	{
	  printf("Veuillez choisir une colonne entre 0 et %d\n",nbColonnes-1);
	  ++i;//on incrémente i deux fois afin que ce soit le même joueur qui rejoue
	}
      else
	placerPion(grille,nbLignes,nbColonnes,choix,pion);
      ++i;
    }
}
