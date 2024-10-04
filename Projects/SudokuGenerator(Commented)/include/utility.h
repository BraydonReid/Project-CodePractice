//
// Created by Keshav Bhandari on 2/8/24.
// Commented by Braydon Reid on 2/20/24. 

#ifndef SUDOKUPROJECT_UTILITY_H
#define SUDOKUPROJECT_UTILITY_H
#include <iostream>
using namespace std;
// List of functions that are included on the utility.cpp file
string getFileName(int, const string &, const string &);
void createAndSaveNPuzzles(const int&, const string&, const string&);
void solveAndSaveNPuzzles(const int &, const string&, const string&, const string&);
#endif //SUDOKUPROJECT_UTILITY_H
