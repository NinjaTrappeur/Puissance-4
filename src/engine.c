#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "engine.h"
#include "grid.h"
#include "megafunMode.h"

int placeBawn(char** grid, int nbLines, int nbColumns, int targetColumn, struct Coord* Coord)
{
  int i=0,place=0;
  while(place==0)
    {
      if(grid[i][targetColumn]!=' ')
	{
	  if(i==0)
	    {
	      printf("\n\nImpossible d'ajouter un pion dans cette colonne, veuillez en choisir une autre\n\n");
	      place=-1;
	    }
	  else
	    {
	      grid[i-1][targetColumn]=Coord->bawn;
	      Coord->x=targetColumn;
	      Coord->y=i-1;
	      place=1;
	    }	
	}
      else if(i==(nbLines-1))
	{
	  grid[i][targetColumn]=Coord->bawn;
	  Coord->x=targetColumn;
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
  int win1=0,win2=0,win3=0,win4=0;
  win1=checkColumn(tab,nbLines,nbColumns,Coord);
  win2=checkLine(tab,nbLines,nbColumns,Coord);
  win3=checkDiagonalL(tab,nbLines,nbColumns,Coord);
  win4=checkDiagonalR(tab,nbLines,nbColumns,Coord);
  if(Coord->y==0)  
    if(draw(tab,nbLines,nbColumns))
      {
	return -1;
      }
  return (win1|win2|win3|win4);
}

int draw(char**grid, int nblines, int nbColumns)
{
  int i;
  for(i=0;i<nbColumns;++i)
    if(grid[0][i]==' ')
      return 0;
  return -1;
}

int checkDiagonalL(char** tab,int nbLines,int nbColumns,struct Coord* Coord)
{
  int xmin,xmax,ymin,ymax,imin,imax,i,count,win=0;
  ymin=Coord->y;
  ymax=nbLines-1-Coord->y;
  xmin=Coord->x;
  xmax=nbColumns-1-Coord->x;
  count=0;
  imin=defineMin(defineMin(ymin,4),defineMin(xmin,4));
  imax=defineMin(defineMin(ymax,4),defineMin(xmax,4));
  for(i=imin;i>=-imax;--i)
    {
      if(tab[Coord->y-i][Coord->x-i]==Coord->bawn)
	++count;
      else
	count=0;
      if(count==4)
	win=1;
    }
  return win;
}
int checkDiagonalR(char** tab,int nbLines,int nbColumns,struct Coord* Coord)
{
  int xmin,xmax,ymin,ymax,imin,imax,i,count,win=0;
  ymin=Coord->y;
  ymax=nbLines-1-Coord->y;
  xmin=Coord->x;
  xmax=nbColumns-1-Coord->x;
  count=0;
  imin=defineMin(defineMin(ymin,4),defineMin(xmax,4));
  imax=defineMin(defineMin(ymax,4),defineMin(xmin,4));
  for(i=imin;i>=-imax;--i)
    {
      if(tab[Coord->y-i][Coord->x+i]==Coord->bawn)
	++count;
      else
	count=0;
      if(count==4)
	win=1;
    }
  return win;
}

int checkColumn(char** tab, int nbLines, int nbColumns, struct Coord* Coord)
{
  int ymin = defineMax(0,Coord->y - 3);
  int ymax = defineMin(nbLines-1,Coord->y + 3);  
  int i = ymin;
  int win = 0;
  int count = 0;
  do
    {
      if(tab[i][Coord->x]==Coord->bawn)
	++count;
      else
	count=0;
      if(count==4)
	win=1;
      i++;
    }while(i<=ymax && win==0);
  return win;
}
int checkLine(char** tab, int nbLines, int nbColumns, struct Coord* Coord)
{
  int xmin = defineMax(0,Coord->x - 3);
  int xmax = defineMin(nbLines-1,Coord->x + 3);  
  int i = xmin;
  int win = 0;
  int count = 0;
  do
    {
      if(tab[Coord->y][i]==Coord->bawn)
	++count;
      else
	count=0;
      if(count==4)
	win=1;
      i++;
    }while(i<=xmax && win==0);
  return win;
}

int defineMin(int min, int value)
{
  if(min<value)
    return min;
  else
    return value;
}

int defineMax(int max, int value)
{
  if(max>value)
    return max;
  else
    return value;
}

void playerInterface(char** tab, int nbColumns, int nbLines,int noGui, int log,int megafunModeOption)
{
  int i=0,x,player=1,choice,win=0;
  char cChoice[2];
  int nbBombs[2]={3,3};
  struct Coord Coord;
  do
    {
      system("clear");
      if(!noGui)
	displayGrid(tab,nbLines,nbColumns);
      if(i%2==0)
	{
	  player=1;
	  Coord.bawn='X';
	}
      else
	{
	  player=2;
	  Coord.bawn='O';
	}
      if(megafunModeOption)
	bombInterface(tab,nbColumns,nbLines,&nbBombs[player-1],log,noGui);
      printf("\nJoueur %d, choisissez une colonne dans laquelle insérer votre pion:",player);
      if(read(cChoice,2,&choice)==0)
	printf("Problème dans la fonction read!!!!!");
      if(choice<0 || choice>nbColumns-1) //si choix fantaisiste
	{
	  printf("Veuillez choisir une colonne entre 0 et %d\n",nbColumns-1);
	  ++i;//on incrémente i deux fois afin que ce soit le même joueur qui rejoue
	}
      else
	{
	  x=placeBawn(tab,nbLines,nbColumns,choice,&Coord);
	  win=winner(tab, nbLines, nbColumns,&Coord);
	  if(log)
	    logFunction(&Coord,i,0,player,x);
	  if(x==-1)
	    ++i;
	}
      if(megafunModeOption)
	megafunMode(tab,nbLines,nbColumns,&i,log);
      i++;
    }while(win==0);
  system("clear");
  if(!noGui)
    displayGrid(tab,nbLines,nbColumns);
  if(winner(tab,nbLines,nbColumns,&Coord)==1)
    printf("\nLe joueur %d gagne la partie!!\n",player);
  else 
    printf("\nEgalité!\n");
  if(log)
    logFunction(&Coord,i,1,player,x);
}

void defineParameters(int argc, char** argv, int* noGui, int* megafunMode, int* log, int* quit)
{
  int i;
  for(i=1;i<argc;++i)
    {
      if(strcmp(argv[i],"--noGui")==0)
	*noGui=1;
      else if(strcmp(argv[i],"--help")==0)
	{
	  printf("\nAide:\n\n--megafunMode : mode megafun (lire readme pour plus d'infos)\n--help : aide\n--log : enregistrer le déroulement de la partie dans un fichier\n--noGui : jouer sans l'interface visuelle\n");
	  *quit=1;
	}
      else if(strcmp(argv[i],"--log")==0)
	*log=1;
      else if(strcmp(argv[i],"--megafunMode")==0)
	  *megafunMode=1;
      else
	{
	  printf("\nOption inconnue, entrez --help pour voir la liste des options disponibles\n\n");
	  *quit=1;
	}
    }
}

void logFunction(struct Coord* Coord,int i,int win,int player, int x)
{
  if(x!=-1)
    {
      FILE* logFile=NULL;
      if(i==0)
	logFile=fopen("log","w+");
      else
	logFile=fopen("log","a");
      if(logFile!=NULL)
	{
	  if(win==0)
	    fprintf(logFile,"Le joueur %d place son pion en [%d][%d]\n",player,Coord->x,Coord->y);
	  else if(win==1)
	    fprintf(logFile,"Le joueur %d à gagné la partie!!!!!!!\n",player);
	  fclose(logFile);
	}
      else
	printf("Imposssible d'ouvrir le fichier log\n");
    }
}

void cleanBuffer()
{
  int c = 0;
  while (c != '\n' && c != EOF)
    {
      c = getchar();
    }
}
 
int read(char *string, int lenght, int* number)
{
  char *end = NULL;
  if (fgets(string, lenght, stdin) != NULL)
    {
      end = strchr(string, '\n');
      if (end != NULL)
	{
	  *end = '\0';
        }
      else
        {
	  cleanBuffer();
        }
      if(string[0]>=48&&string[0]<=57)
	*number=atoi(string);
      else
	*number=-1;
      return 1;
    }
  else
    {
      cleanBuffer();
      return 0;
    }
}
