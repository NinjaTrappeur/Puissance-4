#ifndef ENGINE_H
#define ENGINE_H
struct Coord
{
  int x;
  int y;
  char pion;
};

int placeBawn(char** grille, int nbLignes, int nbColonnes, int colonneCible,struct Coord* Coord);
void playerInterface(char** tab, int nbColumns, int nbLines);
int winner(char** tab, int nbLines, int nbColumns, struct Coord* Coord);
int checkDiagonalL(char** tab,int nbLines,int nbColumns,struct Coord* Coord);
int defineMin(int min, int value);
int defineMax(int max, int value);
int checkLine(char** tab, int nbLines, int nbColumns, struct Coord* Coord);
int checkColumn(char** tab, int nbLines, int nbColumns, struct Coord* Coord);
int checkDiagonalR(char** tab,int nbLines,int nbColumns,struct Coord* Coord);
#endif //ENGINE_H
