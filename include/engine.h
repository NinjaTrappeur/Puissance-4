///@file megafunMode.h
///@brief Grid utils functions
///@author Félix Baylac-Jacqué

#ifndef ENGINE_H
#define ENGINE_H

/// @struct Coord
/// @brief contains the grid
struct Coord
{
  int x;
  int y;
  char bawn;
};

///@fn int placeBawn(char** grille, int nbLignes, int nbColonnes, int colonneCible,struct Coord* Coord)
///@brief Place a bawn in the grid
///@param grid pointer to he grid
///@param nbLines number of lines
///@param nbColumns number of columns
///@param target column target
///@param Coord Coordonees of the last bawn placed
///@return 1 when bawn placed
int placeBawn(char** grid, int nbLines, int nbColumns, int target,struct Coord* Coord);

///@fn void playerInterface(char** tab, int nbColumns, int nbLines, int noGui, int log,int megafunMode)
///@brief Player main interface
///@param tab pointer to he grid
///@param nbLines number of lines
///@param nbColumns number of columns
///@param noGui boolean egals 1 if we won't a graphic interface else 0
///@param log boolean egals 1 if we want to save moves in a log file
///@param megafunMode boolean egal 1 if we are in the megafunMode
void playerInterface(char** tab, int nbColumns, int nbLines, int noGui, int log,int megafunMode);

///@fn int draw(char**grid, int nblines, int nbColumns)
///@brief if the game finished witch a draw? (boolean)
///@param grid pointer to he grid
///@param nbLines number of lines
///@param nbColumns number of columns
///@param noGui boolean egals 1 if we won't a graphic interface else 0
///@param return 1 in case of draw, else  0
int draw(char**grid, int nblines, int nbColumns);

///@fn int winner(char** tab, int nbLines, int nbColumns, struct Coord* Coord)
///@brief Checks if the player has won
///@param tab pointer to he grid
///@param nbLines number of lines
///@param nbColumns number of columns
///@param Coord struct who contains bawn, and coordonees of the last move
///@param return 1 in case of draw, else  0
///@return 1 if the player won, else 0
int winner(char** tab, int nbLines, int nbColumns, struct Coord* Coord) ;

///@fn int checkDiagonalL(char** tab,int nbLines,int nbColumns,struct Coord* Coord)
///@brief Check left diagonal
///@param tab pointer to he grid
///@param nbLines number of lines
///@param nbColumns number of columns
///@param Coord struct who contains bawn, and coordonees of the last move
///@return 1 if 4 bawns are in the diagonal, else 0
int checkDiagonalL(char** tab,int nbLines,int nbColumns,struct Coord* Coord);

///@fn int defineMin(int min, int value)
///@brief Define minimum value betwin min and value
///@param min value 1
///@param value value 1
///@return minimal value
int defineMin(int min, int value);

///@fn int defineMax(int max, int value)
///@brief Define maximum value betwin max and value
///@param max value 1
///@param value value 1
///@return maximal value
int defineMax(int max, int value);

///@fn int checkLine(char** tab,int nbLines,int nbColumns,struct Coord* Coord)
///@brief Check horizontal series of bawn
///@param tab pointer to he grid
///@param nbLines number of lines
///@param nbColumns number of columns
///@param Coord struct who contains bawn, and coordonees of the last move
///@return 1 if 4 bawns are horizontally aligned, else 0
int checkLine(char** tab, int nbLines, int nbColumns, struct Coord* Coord);

///@fn int checkColumns(char** tab,int nbLines,int nbColumns,struct Coord* Coord)
///@brief Check vertical series of bawn
///@param tab pointer to he grid
///@param nbLines number of lines
///@param nbColumns number of columns
///@param Coord struct who contains bawn, and coordonees of the last move
///@return 1 if 4 bawns are vertically aligned, else 0
int checkColumn(char** tab, int nbLines, int nbColumns, struct Coord* Coord);

///@fn int checkDiagonalR(char** tab,int nbLines,int nbColumns,struct Coord* Coord)
///@brief Check right diagonal
///@param tab pointer to he grid
///@param nbLines number of lines
///@param nbColumns number of columns
///@param Coord struct who contains bawn, and coordonees of the last move
///@return 1 if 4 bawns are in the diagonal, else 0
int checkDiagonalR(char** tab,int nbLines,int nbColumns,struct Coord* Coord);

///@fn void defineParameters(int argc, char** argv, int* noGui, int* magafunMode, int* log,int* quit,int* megafunMode)
///@brief Parse data from argv and define parameters of execution
///@param argc number of parameters
///@param argv parameters
///@param noGui noGui pointer, boolean 1 if we won't a gui else 0
///@param megafunMode megafunMode pointer, boolean: 1 if enabled else 0
///@param log log pointer, boolean: 1 if enabled, else 0
///@param quit quit pointer, 1 if one parameter is unknown, else 0.
void defineParameters(int argc, char** argv, int* noGui, int* megafunMode, int* log,int* quit);

///@fn void logFunction(struct Coord* Coord,int i,int win,int player,int x);
///@brief Function that read moves in a log file
///@param Coord struct who contain position and type of bawn
///@param i egals 0 if it's the first round
///@param win boolean egals 1 if a player has won
///@param megafunMode megafunMode pointer, boolean: 1 if enabled else 0
///@param x boolean egal -1 if the bawn has not been placed
void logFunction(struct Coord* Coord,int i,int win,int player,int x);

///@fn int read(char *string, int lenght, int* number)
///@brief read a string or an integer from the keyboard 
///@param string string where entry goes to be saved
///@param lenght lenght of the string
///@param number integer captured by the keyboard
///@return 0 in case of error
int read(char *string, int lenght, int* number);

///@fn void cleanBuffer()
///@brief util function for read function. Cleans buffer of stdin
void cleanBuffer();
#endif //ENGINE_H
