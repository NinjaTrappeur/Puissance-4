#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
#include "grid.h"
void switchBawns(char** grid,int nbLines, int nbColumns,int log)
{
  int randNumber=1+(rand() % 20),i,j;
  FILE* logFile=NULL;
  if(randNumber==7)
    {
      printf("\nSWITCH!!!!!!!!!!!!!!!!!!\n");
      if(log)
	{
	  logFile=fopen("log","a");
	  if(logFile!=NULL)
	    {
	      fprintf(logFile,"\nSWITCH!!!!\n");
	      fclose(logFile);
	    }
	}
      for(i=0;i<nbLines;++i)
	for(j=0;j<nbColumns;++j)
	  {
	    if(grid[i][j]=='X')
	      grid[i][j]='O';
	    else if(grid[i][j]=='O')
	      grid[i][j]='X';
	  }
    }
}

void criticalStrike(int* i,int log)
{
  FILE* file=NULL;
  int randNumber;
  randNumber=1+(rand() % 5);
  if(randNumber==5)
    {
      *i=*i+1;
      if(log)
	{
	  file=fopen("log","a");
	  if(file!=NULL)
	    {
	      fprintf(file,"\n COUP CRITIQUE!!!!\n");
	      fclose(file);
	    }
	}
      printf("\n COUP CRITIQUE!!!! Vous rejouez!\n");
    }
}

void useBomb(char** grid, int nbLines, int nbColumns, int target,struct Coord* Coord,int log)
{
  int place=0,i=0;
  FILE* logFile=NULL;
  while(place==0 && i<nbLines)
    {
      if(grid[i][target]!=' ')
	{
	  grid[i][target]=' ';
	  place=1;
	  if(log)
	    {
	      logFile=fopen("log","a");
	      if(logFile!=NULL)
		{
		  fprintf(logFile,"Bombe en [%d][%d]\n",target,i);
		  fclose(logFile);
		}
	    }
	}
      ++i;
    } 
}

void megafunMode(char** grid,int nbLines, int nbColumns,int* i,int log)
{
  criticalStrike(i,log);
  switchBawns(grid,nbLines,nbColumns,log);
}

void bombInterface(char** grid,int nbColumns,int nbLines,struct Coord* Coord, int *nbBombs, int log, int noGui)
{
  char choice;
  int target,ok=0;
  if(*nbBombs>0)
    {
      printf("\nIl vous reste %d bombes\nVoulez-vous utiliser une bombe?(o/n)\n",*nbBombs);
      scanf("%c",&choice);
      if(choice=='o'||choice=='O')
	{
	  printf("Où voulez-vous lancer la bombe?\n");
	  scanf("%d",&target);
	  while(!ok)
	    {
	      if(target<0 || target>nbColumns) //si choix fantaisiste
		{
		  printf("Veuillez choisir une colonne entre 0 et %d\n",nbColumns-1);
		}
	      else
		  ok=1;
	    }
	  useBomb(grid,nbLines,nbColumns,target,Coord,log);
	  if(!noGui)
	    displayGrid(grid,nbLines,nbColumns);
	  *nbBombs=*nbBombs-1;
	}
    }
}
