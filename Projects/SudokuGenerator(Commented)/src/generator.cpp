#include <random>               //Allows use of random functions
#include "../include/sudoku.h"  //Allows us to use the isValid and other functions from sudoku.cpp

//Alec G 2/13/24
//Used to swap values of input int array values
//Used in other functions to randomize array order
void swapValues(int values[], int index0, int index1)
{
    //Store value in temp and swap at input indices
    int temp = values[index0];
    values[index0] = values[index1];
    values[index1] = temp;
}

//Alec G 2/13/24
//Used to randomly shuffle the input array's values




/*void shuffleArray(int values[], int size)
{
    //For each integer in the values array
    //Randomly choose two indices and swap the values
    //of the array at those indices
    for (int i = 0; i < size; i++)
    {
        swapValues(values, rand() % size, rand() % size);
    }
}*/

//Alec G 2/13/24
//Used to get an array with values 1 to size
//Used to randomly fill board and randomly obscure board
void getRandomValuesArray(int values[], int size)
{
    //Set values of values array to 1 through 9
    for (int i = 1; i <= size; i++)
    {
        values[i - 1] = i;
    }

    //Shuffle order of array
    shuffleArray(values, size);
}

//Alec G 2/13/24
//Returns a new 2D array with values all being zero
int** getEmptyBoard()
{
    int** board = new int* [9];
    for (int i = 0; i < 9; i++)
    {
        board[i] = new int[9] {0, 0, 0, 0, 0, 0, 0, 0, 0};
    }

    return board;
}

//Alec G 2/13/24
//Returns new 2D array (board) with a copy of the input board's values
int** getCopyOfBoard(int** board)
{
    int** newBoard = getEmptyBoard();
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            newBoard[r][c] = board[r][c];
        }

    }

    return newBoard;
}

//Alec G 2/13/24
//Used to obscure values within the board
//Returns new 2D array (board) with values
int** obscureBoard(int** board, int removeAmount = 55)
{
    //81 = 9 * 9 -> total number of cells in board
    //Get array with shuffled indices of values within the array
    int indices[81];
    getRandomValuesArray(indices, 81);

    //Used to loop over rows and columns
    int r, c;

    //Take the board and copy it into a new 2D array
    int** obscuredBoard = getCopyOfBoard(board);


    //Loop through indices array until the remove amount has been reached
    //or the max value of 81 removals has been reached
    for (int i = 0; i < 81 && i < removeAmount; i++)
    {
        //Calculate the row and column from the index
        //indices[i] - 1 is used here because indices will contain values 1 to 81
        int index = indices[i] - 1;
        r = index / 9;
        c = index % 9;

        //Set the value at the row and column to zero
        obscuredBoard[r][c] = 0;
    }

    return obscuredBoard;
}

//Alec G 2/13/24
//Returns a solved board filled with random values
int** getRandomBoard()
{
    //Create empty board
    int** board = getEmptyBoard();
    int values[9];

    //Fill diagonal of the board with random values
    for (int r = 0; r < 9; r++)
    {
        //Get random values 1 to 9 in random order
        getRandomValuesArray(values, 9);

        for (int i = 0; i < 9; i++)
        {
            //Check if the value is valid
            if (isValid(board, r, r, values[i]))
            {
                //Set the value
                board[r][r] = values[i];
                break;
            }
        }
    }

    //Fill diagonal of the board with random values
    for (int r = 0; r < 9; r++)
    {
        //Get random values 1 to 9 in random order
        getRandomValuesArray(values, 9);

        for (int i = 0; i < 9; i++)
        {
            //Check if the value is valid
            if (isValid(board, r, 8 - r, values[i]))
            {
                //Set the value
                board[r][8 - r] = values[i];
                break;
            }
        }
    }

    //Solve all other values of the board
    solveBoard(board, 0, 0);

    return board;
}

//Alec G 2/13/24
//Returns a solved board filled with random values
int** getRandomBoardBoxed()
{
    //Create empty board
    int** board = getEmptyBoard();
    int values[9];

    //Fill First diagonal box
    //Get random values 1 to 9 in random order
    getRandomValuesArray(values, 9);
    
        getRandomValuesArray(values, 9);
        for (int i = 0; i < 9; i++)
        {
            int r = i / 3;
            int c = i % 3;

            board[r][c] = values[i];
        }

        //Fill Second diagonal box
        //Get random values 1 to 9 in random order
       getRandomValuesArray(values, 9);
       for (int i = 0; i < 9; i++)
        {
            int r = i / 3 + 3;
            int c = i % 3 + 3;

            board[r][c] = values[i];
        }

        //Fill Third diagonal box
        //Get random values 1 to 9 in random order
       getRandomValuesArray(values, 9);
       for (int i = 0; i < 9; i++)
        {
            int r = i / 3 + 6;
            int c = i % 3 + 6;

            board[r][c] = values[i];
        }
    

    //Solve all other values of the board
    solveBoard(board, 0, 0);

    return board;
}

//Created by Keshav Bhandari on 2/8/24.
//Updated by Alec G 2/12
int** generateBoard()
{
    // Following initialization is important
    //int** board = getRandomBoard();
    int** board = getRandomBoardBoxed();

    //Obscure the values of the board
    int** obscuredBoard = obscureBoard(board);

    return obscuredBoard;
}
