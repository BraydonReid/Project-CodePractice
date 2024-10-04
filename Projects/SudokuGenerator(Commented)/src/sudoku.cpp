//
// Created by Keshav Bhandari on 2/7/24.
// Commented by Braydon Reid on 2/20/24.
#include "../include/sudoku.h"
#include <iostream>
#include<random>
#include<string>
using namespace std;

// Created by Braydon Reid on 2/20/24
// function that shuffles an array (from 'random'libarary)
void shuffleArray(int values[], int size) {
    random_device rd;  /// accessing random_device class from 'random' library
    default_random_engine rng(rd());    /// initializes random number engine

    // values determines the starting range
    // values + size determines the end range
    // rng is the engine that is being used to shuffle the array
    shuffle(values, values + size, rng);    /// shuffles elements in designated range 
}

// function that prints the board
void printBoard(int** BOARD, int r, int c, int k)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            string board_piece;
            if (BOARD[i][j] == 0) board_piece = "\x1B[93m-\x1B[0m"; /// whenever the board value = 0 it is colored yellow
            else board_piece = to_string(BOARD[i][j]); // converts board to string and the color is White
            if ((i == r && j == c) && k != 0)
            {
                if (isValid(BOARD, r, c, k))
                    board_piece = "\x1B[32m" + to_string(k) + "\x1B[0m"; /// if value is valid it is colored Green
                else
                    board_piece = "\x1B[31m" + to_string(k) + "\x1B[0m"; /// if value is not valid then it is colored Red
            }
            cout << board_piece;    /// prints the value as string
            if (j == 2 || j == 5) cout << " | ";   /// creates a divider to separate the columns int groups of 3
            else cout << " ";   /// creates a space between every value otherwise
        }
        if (i == 2 || i == 5)   /// creates a divider between the rows to separate them into groups of 3 
        {
            cout << endl;
            for (int l = 0; l < 21; l++) cout << ".";
        }
        cout << endl;
    }
}

//function that checks if key placement is valid
bool isValid(int** BOARD, int r, int c, int k)
{
    for (int i = 0; i < 9; i++)
    {
        if (k == BOARD[r][i] || k == BOARD[i][c])   /// checks rows and column to see if the key is present and if so it returns false
            return false;
    }

    // checks in blocks of 3x3 to see if key is present and if so it returns false
    for (int i = 3 * (r / 3); i < 3 * (r / 3) + 3; i++)    
    {
        for (int j = 3 * (c / 3); j < 3 * (c / 3) + 3; j++)
        {
            if (k == BOARD[i][j])
                return false;
        }
    }
    return true;
}


bool solveBoard(int** BOARD, int r, int c){
    if(r == 9)  /// if the row = 9 then it returns true because the board is solved
        return true;
    else if(c == 9)     /// if column = 9 then it jumps to the next row and resets the column index
        return solveBoard(BOARD, r+1, 0);
    else if(BOARD[r][c] != 0)   /// jumps to next value if the value is not 0
        return solveBoard(BOARD, r, c+1);
    // finds valid value placement whenever the value of the board is 0
    else{
        for(int k=1; k<10; k++){
            if(isValid(BOARD, r, c, k)){
                BOARD[r][c] = k;
                if(solveBoard(BOARD, r, c+1))
                    return true;
                else
                    BOARD[r][c] = 0;
            }
        }
        return false;
    }
}