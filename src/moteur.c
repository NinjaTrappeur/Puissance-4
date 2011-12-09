#include <stdio.h>
#include"moteur.h"

int placeBawn(char** grille, int nbLignes, int nbColonnes, int colonneCible, struct Coord* Coord)
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
	      grille[i-1][colonneCible]=Coord->pion;
	      Coord->x=colonneCible;
	      Coord->y=i-1;
	      place=1;
	    }	
	}
      else if(i==(nbLignes-1))
	{
	  grille[i][colonneCible]=Coord->pion;
	  Coord->x=colonneCible;
	  Coord->y=i;
	  place=1;
	}
      else
	{
	  ++i;
	}
    }
  return place;
}

int winner(char** tab, int nbLines, int nbColumns,struct Coord* Coord)
{
  int win1=0,win2=0;
  win1=checkColumn(tab,nbLines,nbColumns,Coord);
  win2=checkLine(tab,nbLines,nbColumns,Coord);
  return (win1|win2);
}

/*int checkDiagonalL(char** tab,int nbLines,int nbColumns,struct Coord* Coord)
{
  int xmax = defineMax(nbColumns-1,Coord->x + 4);
  int xmin = defineMin(0,Coord->x - 4);
  int ymin = defineMin(0,Coord->y - 4);
  int ymax = defineMax(nbLines-1,Coord->y + 4);
  int i = min;
  int win = 0;
  int count = 0;
  while(i<max && win==0)
    {
      if(count>=4)
	win = 1;
      else if(tab[i])
    }
    }*/

int checkColumn(char** tab, int nbLines, int nbColumns, struct Coord* Coord)
{
  int ymin = defineMin(0,Coord->y - 3);
  int ymax = defineMax(nbLines-1,Coord->y + 3);  
  int i = ymin;
  int win = 0;
  int count = 0;
  do
    {
      if(tab[i][Coord->x]==Coord->pion)
	{
	  ++count;
	}
      else
	{
	  count=0;
	}
      if(count==4)
	{
	  win=1;
	}
      i++;
    }while(i<=ymax && win==0);
  return win;
}
int checkLine(char** tab, int nbLines, int nbColumns, struct Coord* Coord)
{
  int xmin = defineMin(0,Coord->x - 3);
  int xmax = defineMax(nbLines-1,Coord->x + 3);  
  int i = xmin;
  int win = 0;
  int count = 0;
  do
    {
      if(tab[Coord->y][i]==Coord->pion)
	{
	  ++count;
	}
      else
	{
	  count=0;
	}
      if(count==4)
	{
	  win=1;
	}
      i++;
    }while(i<=xmax && win==0);
  return win;
}

int defineMin(int min, int value)
{
  if(value<min)
    return min;
  else
    return value;
}

int defineMax(int max, int value)
{
  if(value>max)
    return max;
  else
    return value;
}
int takeSmall(int x, int y)
{
  if(x<y)
    return x;
  else
    return y;
}
void playerInterface(char** tab, int nbColumns, int nbLines)
{
  int i=0,gagne=0,choix,x,joueur;
  char pion;
  struct Coord Coord;
  while(winner(tab,nbLines,nbColumns,&Coord)==0)
    {
      affichageGrille(tab,nbLines,nbColumns);
      if(i%2==0)
	{
	  joueur=1;
	 Coord.pion='X';
	}
      else
	{
	  joueur=2;
	  Coord.pion='O';
	}
      printf("\nJoueur %d, choisissez une colonne dans laquelle insérer votre pion:",joueur);
      scanf("%d",&choix);
      if(choix<0 || choix>nbColumns) //si choix fantaisiste
	{
	  printf("Veuillez choisir une colonne entre 0 et %d\n",nbColumns-1);
	  ++i;//on incrémente i deux fois afin que ce soit le même joueur qui rejoue
	}
      else
	{
	  x=placeBawn(tab,nbLines,nbColumns,choix,&Coord);
	  if(x==-1)//si on ne peut pas placer le pion dans cette ligne on incremente i deux fois pour que le même joueur joue
	    ++i;
	}
      ++i;
    }
  affichageGrille(tab,nbLines,nbColumns);
  printf("\nLe joueur %d gagne la partie!!\n",joueur);
}
