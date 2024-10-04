//
// Created by Keshav Bhandari on 2/8/24.
// Commented by Braydon Reid on 2/20/24. 

#ifndef SUDOKUPROJECT_GENERATOR_H
#define SUDOKUPROJECT_GENERATOR_H
// List of functions that are included on the generator.cpp file
int** generateBoard();
void swapValues(int values[], int index0, int index1);
void shuffleArray(int values[], int size);
void getRandomValuesArray(int values[], int size);
int** getEmptyBoard();
int** getCopyOfBoard(int** board);
int** obscureBoard(int** board, int removeAmount = 55);
int** getRandomBoard();
int** getRandomBoardBoxed();


#endif //SUDOKUPROJECT_GENERATOR_H
