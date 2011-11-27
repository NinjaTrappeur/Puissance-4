#include <stdio.h>

int placerPion(char** grille, int nbLignes, int nbColonnes, int colonneCible, char pion)
{
  int i=0,place=0;
  while(place==0)
    {
      if(grille[i][colonneCible]!=' ')
	{
	  if(i==0)
	    {
	      printf("\n\nImpossible d'ajouter un pion dans cette colonne, veuillez en choisir une autre\n\n");
	      place=-1;
	    }
	  else
	    {
	      grille[i-1][colonneCible]=pion;
	      place=1;
	    }	
	}
      else if(i==(nbLignes-1))
	{
	  grille[i][colonneCible]=pion;
	  place=1;
	}
      else
	{
	  ++i;
	}
    }
  return place;
}

void interfaceJoueur(char** grille, int nbColonnes, int nbLignes)
{
  int i=0,gagne=0,choix,x;
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
	{
	  x=placerPion(grille,nbLignes,nbColonnes,choix,pion);
	  if(x==-1)//si on ne peut pas placer le pion dans cette ligne on incremente i deux fois pour que le même joueur joue
	    ++i;
	}
      ++i;
    }
}
