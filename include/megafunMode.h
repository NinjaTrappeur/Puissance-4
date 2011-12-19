///@file grid.h
///@brief Grid utils functions
///@author Félix Baylac-Jacqué

#ifndef MEGAFUN_MODE_H
#define MEGAFUN_MODE_H

/// @fn switchBawns(char** grid,int nbnLines, int nbColumns,int log)
/// @brief Switch all bawns of the grid
/// @param grid pointer to the grid
/// @param nbLines number of lines
/// @param nbColumns numbers of columns
/// @param log boolean 1 if we want to keep logs in a log file. Else 0.
void switchBawns(char** grid,int nbnLines, int nbColumns,int log);

/// @fn criticalStrike(int* i, int log
/// @brief Is a critical strike?
/// @param i number used to calculate what player have to play
/// @param
void criticalStrike(int* i,int log);

/// @fn void useBomb(char** grid, int nbLines, int nbColumns, int target,struct Coord* Coord,int log)
/// @brief Delete the upper bawn in the columns target
/// @param grid pointer to the grid
/// @param nbLines number of lines
/// @param nbColumns number of columns
/// @param target column where we want to place the bomb
/// @param log Boolean, record move in the log file is 1, do nt record if 0
void useBomb(char** grid, int nbLines, int nbColumns, int target,int log);

/// @fn void megafunMode(char** grid,int nbLines, int nbColumns,int* i,int log)
/// @brief Call criticalStrike and switchBawns functions
/// @param grid pointer to the grid
/// @param nbLines number of lines
/// @param nbColumns number of columns
/// @param i number used to calculate what player have to play
/// @param log Boolean, record move in the log file is 1, do nt record if 0
void megafunMode(char** grid,int nbLines, int nbColumns,int* i,int log);

/// @fn void bombInterface(char** grid,int nbColumns,int nbLines,struct Coord* Coord, int *nbBombs,int log, int noGui)
/// @brief User interface for useBomb function
/// @param grid pointer to the grid
/// @param nbColumns number of columns
/// @param nbLines number of lines
/// @param nbBombs pointer to the number of bomb owned by the player that is currently playing
/// @param log Boolean egals 1 if we want to keep moves in a log file else 0
/// @param noGui 1 if we won't a visual interface, 0 if we want one
void bombInterface(char** grid,int nbColumns,int nbLines, int *nbBombs,int log, int noGui);
#endif
