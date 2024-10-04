//
// Created by Keshav Bhandari on 2/7/24.
// Commented by Braydon Reid on 2/20/24.	 

#ifndef SUDOKUPROJECT_SUDOKU_H
#define SUDOKUPROJECT_SUDOKU_H
// List of functions that are included on the sudoku.cpp file
void printBoard(int**, int, int, int);
bool isValid(int**, int, int, int);
bool solveBoard(int**, int, int);
int** generateBoard();
int random(int, int);
void shuffleArray(int*, int);
#endif //SUDOKUPROJECT_SUDOKU_H
