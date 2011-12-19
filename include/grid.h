///@file grid.h
///@brief Grid utils functions
///@author Félix Baylac-Jacqué

#ifndef GRID_H
#define GRID_H

/// @fn createGrid(int nbLines, int nbColumns)
/// @brief Create the grid
/// @param nbLines number of lines
/// @param nbColumns numbers of columns
/// @return a pointer to the new tab (the tab represents the grid)
char** createGrid(int nbLines, int nbColumns);

/// @fn freeGrid(char** grid, int nbLines, int nbColumns)
/// @brief Delete the grid from the memory
/// @param grid pointer to the grid
/// @param nbLines number of lines
/// @param nbColumns numbers of columns
void freeGrid(char**,int,int);

/// @fn displayGrid(char** grid, int nbLines, int nbColumns)
/// @brief Displays the grid with ascii caracters
/// @param grid pointer to the grid
/// @param nbLines number of lines
/// @param nbColumns numbers of columns
void displayGrid(char** grid, int nbLines, int nbColumns);
#endif
