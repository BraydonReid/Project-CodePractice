//
// Created by Keshav Bhandari on 2/8/24.
// Commented by Braydon Reid on 2/20/24.
#include <iostream>
#include <string>
#include <vector>
#include "../include/generator.h"
#include "../include/sudokuio.h"
#include "../include/sudoku.h"
using namespace std;
string getFileName(int index, const string &destination, const string &prefix){
    string index_str = to_string(index);    /// converts the index into a string
    string index_fill = string(4 - index_str.length(), '0');    /// creates the leading 0s in front of the index (makes it look pretty)
    string filename = destination + index_fill + index_str + prefix + ".txt";   /// creates the file name 
    return filename;
}
// function that creates the file for the unsolved board and writes the unsolved board to the file
void createAndSaveNPuzzles(const int& num_puzzles, const string& destination, const string& prefix){
    int total_success = 0;  /// counter for number of successful files written 
    for(int i=0; i < num_puzzles; i++){
        int** BOARD = generateBoard();  /// generates board and assigns it to 'BOARD'
        string filename = getFileName(i, destination, prefix);  /// creates the file name for each of the puzzles
        if(writeSudokuToFile(BOARD, filename)){ /// if successfully written to file
            total_success++;    /// increments total success attempts by + 1
            cout << "Successfully written(" << filename << ") "<< total_success << "of " << num_puzzles << endl;
        }else{
            cout << "!! Failed to write(" << filename << ") "<< total_success << "of " << num_puzzles << endl;
        }
    }
    cout << total_success << " files written out of " << num_puzzles <<endl;    /// states total number of successful files written
}

// function that creates the file for the solved board and writes the solved board to the file 
void solveAndSaveNPuzzles(const int &num_puzzles, const string& source, const string& destination, const string& prefix){
    int total_success_solve = 0;    // counter for number of boards successfully solved
    int total_success_write = 0;    /// counter for number of successful files written
    vector<string> path_to_sudokus = getAllSudokuInFolder(source);  /// assigns regular files into the path_to_sudokus vector not included any added directories

    cout << "Number of loaded puzzles:" << path_to_sudokus.size() << "/" << num_puzzles << endl;        /// displays total number of loaded puzzles
    for(int i = 0; i < path_to_sudokus.size(); i++){    
        int** sudoku = readSudokuFromFile(path_to_sudokus[i]);      /// Reads the sudoku from the folder
        if(solveBoard(sudoku, 0, 0)){       /// attempts to solve the sudoku board
            if(checkIfSolutionIsValid(sudoku)){     /// checks if the solution is valid
                total_success_solve++;      /// increments successful solves by + 1
                string filename = getFileName(i, destination, prefix);  /// creates the solved boards file name
                cout << "Puzzle Solved(over available): " << total_success_solve << "/" << path_to_sudokus.size() << " | ";
                cout << "Puzzle Solved(over total): " << total_success_solve << "/" << num_puzzles << endl;
                if(writeSudokuToFile(sudoku, filename)){    /// writes the solved sudoku into the file
                    total_success_write++;  /// increments the total_success_write by + 1 
                }
                cout << "Puzzle Solved Written(over available): " << total_success_write << "/" << path_to_sudokus.size() << " | ";
                cout << "Puzzle Solved Written(over total): " << total_success_write << "/" << num_puzzles << endl;
            }
        }
    }
}
