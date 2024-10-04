#include <iostream>
#include "include/sudoku.h"
#include "include/sudokuio.h"
#include "include/utility.h"
#include "include/generator.h"
#include <time.h>

string PATH_TO_PUZZLES = "data/puzzles/";
string PATH_TO_SOLUTIONS = "data/solutions/";

string PUZZLE_PREFIX = "PUZZLE";
string SOLUTION_PREFIX = "SOLUTION";

int NUM_PUZZLE_TO_GENERATE = 1000;
// EDITED BY RICHARD WELCH 2/20/24
// Commented by Braydon Reid on 2/20/24.
int main()
{
    
    clock_t clkStart; ///  declares start timer
    clock_t clkFinish; /// declares end timer

    clkStart = clock(); /// starts timer

    //for (int i = 0; i < NUM_PUZZLE_TO_GENERATE; i++);
    initDataFolder();   /// creates data folder
    createAndSaveNPuzzles(NUM_PUZZLE_TO_GENERATE, PATH_TO_PUZZLES, PUZZLE_PREFIX); // creates the puzzle files and stores them in puzzle folder
    solveAndSaveNPuzzles(NUM_PUZZLE_TO_GENERATE, PATH_TO_PUZZLES, PATH_TO_SOLUTIONS, SOLUTION_PREFIX); /// creates the solution files and stores them in solution folder

    clkFinish = clock();  /// ends timer
    //Gives runtime in seconds
    cout << "Runtime in seconds: " << (clkFinish - clkStart) / CLOCKS_PER_SEC << endl;

    return 0;
}
