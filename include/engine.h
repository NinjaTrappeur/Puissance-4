#ifndef ENGINE_H
#define ENGINE_H
struct Coord
{
  int x;
  int y;
  char bawn;
};

int placeBawn(char** grille, int nbLignes, int nbColonnes, int colonneCible,struct Coord* Coord);
void playerInterface(char** tab, int nbColumns, int nbLines, int noGui, int log,int megafunMode);
int winner(char** tab, int nbLines, int nbColumns, struct Coord* Coord);
int checkDiagonalL(char** tab,int nbLines,int nbColumns,struct Coord* Coord);
int defineMin(int min, int value);
int defineMax(int max, int value);
int checkLine(char** tab, int nbLines, int nbColumns, struct Coord* Coord);
int checkColumn(char** tab, int nbLines, int nbColumns, struct Coord* Coord);
int checkDiagonalR(char** tab,int nbLines,int nbColumns,struct Coord* Coord);
void defineParameters(int argc, char** argv, int* noGui, int* armagedonMode, int* log,int* quit,int* megafunMode);
void logFunction(struct Coord* Coord,int i,int win,int player,int x);
int read(char *string, int lenght, int* number);
void cleanBuffer();
#endif //ENGINE_H
