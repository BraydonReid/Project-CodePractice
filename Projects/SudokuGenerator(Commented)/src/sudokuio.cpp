//
// Created by Keshav Bhandari on 2/7/24.
// Commented by Braydon Reid on 2/20/24.
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include "../include/sudokuio.h"
#include "../include/sudoku.h"

using namespace std;

//function used to create folders to store data in
void createFolder(const std::string& folderPath) {
    if (!filesystem::exists(folderPath)) {  /// checks if the folder path exists or not
        if (filesystem::create_directory(folderPath)) { /// if not it creates the directory
            std::cout << "Folder created successfully: " << folderPath << std::endl;
        } else {   
            std::cerr << "Failed to create folder: " << folderPath << std::endl;
        }
    } else {
        std::cout << "Folder already exists: " << folderPath << std::endl;
    }
}

// function creates data folder
void initDataFolder(){
    createFolder("data/");      /// creates the actual data folder
    createFolder("data/puzzles/");      /// creates puzzle folder within data folder
    createFolder("data/solutions/");    /// creates solution folder within data folder
}


// function that converts the board into a string
void boardToString(int** BOARD, string &content){
    // for loops used to go through the 2d array
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            string board_piece;     /// creates the string variable for the board piece 

            if (BOARD[i][j] == 0) content += "-";       /// the value of the board is 0 than it replaces it with '-'
            else content += to_string(BOARD[i][j]);     /// otherwise it converts the board value into a string

            if (j == 2 || j == 5)  content += " | ";    /// creates a divider in the columns to separate them into 3
            else content += " ";        /// otherwise it only creates a space between the values 
        }
        if (i == 2 || i == 5)       /// separates the rows into 3
        {
            content += "\n";    /// ends the line 
            for (int l = 0; l < 21; l++) content += ".";    /// creates divider in rows to make 3x3 blocks
        }
        content += "\n";
    }
}

// function prints sudoku onto the files
bool writeSudokuToFile(int** BOARD, const string& filename) {

    string content;
    boardToString(BOARD, content);  /// converts board to string and stores it in contents variable
    ofstream outFile(filename); /// Open file for writing
    if (outFile.is_open()) {    /// confirms if file is open
        outFile << content; /// Write content to file
        outFile.close(); /// Close the file
        cout << "Content has been written to the file: " << filename << endl;
        return true;
    } else {    /// runs if file is not capable of opening
        cerr << "Unable to open file: " << filename << endl;
        return false;
    }
}

// function that is used to replace the 0 in the array to a -
void replaceCharacter(std::string& str, char oldChar, char newChar) {
    for (char &ch: str) {
        if (ch == oldChar) {
            ch = newChar;
        }
    }
}

// function finds matches and extracts them as integers
void extractNumbers(const string& input, vector<int>& numbers) {

    // '(\\d)' will look for a digit in the range of 0-9
    // the + at the end means that the element before will occur one or more times
    regex regex("\\d+");    ///searches for a sequence of digits

    auto iterator = sregex_iterator(input.begin(), input.end(), regex);     /// searches for matches within the input string
    auto end = sregex_iterator();   /// ends the iterator

    for (; iterator != end; ++iterator) {   /// will continue until the iterator is ended
        // stoi converts into intenger
        // iterator->str() extracts string from the iterator
        // push_back asigns the matches to the end of the numbers vector
        numbers.push_back(stoi(iterator->str()));      /// converts the matches to integers
    }
}

// functions fills the board array using the numbers from the array
void fillBoard(const vector<int>& numbers, int **BOARD){
    for(int i = 0; i < 9; i++) {
        BOARD[i] = new int[9];  /// creates 2d array
        for(int j = 0; j < 9; j++){
            // 'i * 9 + j' is used because the vector is 1d and needs to assign values to the 2d array
            BOARD[i][j] = numbers[i * 9 + j]; /// assigns the values from the vector to the array
        }
    }
}


int** readSudokuFromFile(const string& filename){
    int** BOARD = new int*[9];  /// creates 2d array
    vector<int> numbers;    /// creates vector
    string sudoku;

    ifstream file(filename);    /// opens the file 
    sudoku = string(istreambuf_iterator<char>(file), istreambuf_iterator<char>());  /// reads the contents of the file and stores it in the sudoku string 

    replaceCharacter(sudoku, '-', '0');     /// replaces any values from '-' to '0'
    extractNumbers(sudoku, numbers);    /// converts the sudoku string into integers
    fillBoard(numbers, BOARD);     /// fills the board with the contents stored in numbers
    return BOARD;   /// returns the filled board
}

// function that checks if the solution provided is valid 
bool checkIfSolutionIsValid(int** BOARD){
    // goes through the 2d array
    for(int r = 0; r < 9; r++) {
        for(int c = 0; c < 9; c++) {
            int k = BOARD[r][c]; /// temporarly stores the value from the board into k 
            BOARD[r][c] = 0;    /// asigns board the value of 0
            if(!isValid(BOARD, r, c, k)){   /// checks if the key is invalid
                BOARD[r][c] = k;    /// if true then it reassigns k back to board and then states test failed and returns false
                cout << "!!!!!!!!!!!!!!!! TEST FAILED !!!!!!!!!!!!!!!!" << endl;
                return false;
            }
            BOARD[r][c] = k;    /// if valid it reassigns k back to the board and states test passed and returns true.
        }
    }
    cout << "--------------- TEST PASSED ---------------" << endl;
    return true;
}

// creates a vector function that will be used to get the sudoku into the folder
vector<string> getAllSudokuInFolder(const string& folderPath){
    vector<std::string> sudokus;    /// creates a vector with the data type string
    for (const auto& entry : filesystem::directory_iterator(folderPath)) {
        if (filesystem::is_regular_file(entry)) {   /// checks if the file being entered is a regular file and not another directory
            sudokus.push_back(entry.path().string());   /// if it is a regular file than it assigns the path into the sudokus vector
        }
    }

    cout << sudokus.size() << " Sudoku Puzzle found @ " << folderPath << endl;
    cout << setfill('-') << setw(55)<< "" << setfill(' ') <<endl;
    cout << setw(5) << "Index" << setw(50) << "File Name" << endl;
    cout << setfill('-') << setw(55)<< "" << setfill(' ') <<endl;
    for(int i = 0; i < sudokus.size(); i++)
        cout << setw(5) << i << setw(50) << sudokus[i] << endl;
    cout << setfill('-') << setw(55)<< "" << setfill(' ') <<endl;
    return sudokus;
}
