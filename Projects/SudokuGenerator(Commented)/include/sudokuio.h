//
// Created by Keshav Bhandari on 2/7/24.
// Commented by Braydon Reid on 2/20/24.
#ifndef SUDOKUPROJECT_SUDOKUIO_H
#define SUDOKUPROJECT_SUDOKUIO_H
#include<vector>
using namespace std;
// List of functions that are included on the sudokuio.cpp file
void createFolder(const std::string&);
void initDataFolder();
int random(int, int);
void boardToString(int**, string&);
bool writeSudokuToFile(int**, const string&);
void replaceCharacter(string&, char, char);
void extractNumbers(const string&, vector<int>&);
void fillBoard(const vector<int>&, int**);
int** readSudokuFromFile(const string&);
bool checkIfSolutionIsValid(int**);
vector<string> getAllSudokuInFolder(const string&);
#endif //SUDOKUPROJECT_SUDOKUIO_H
