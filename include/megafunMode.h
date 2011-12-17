#ifndef MEGAFUN_MODE_H
#define MEGAFUN_MODE_H
void switchBawns(char** grid,int nbnLines, int nbColumns,int log);
void criticalStrike(int* i,int log);
void useBomb(char** grid, int nbLines, int nbColumns, int target,struct Coord* Coord,int log);
void megafunMode(char** grid,int nbLines, int nbColumns,int* i,int log);
void bombInterface(char** grid,int nbColumns,int nbLines,struct Coord* Coord, int *nbBombs,int log, int noGui);
#endif
