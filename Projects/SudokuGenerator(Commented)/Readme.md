## Read Instructions Before Carefully
    - C++17 or higher required
    - Recommended tool: CLion
    - You need to use CMake to build this project.
    - If you don't want to run into problems use CLion, otherwise follow the instructions
    - You need to create a private git(txstate) repository and add me(k_b459@txstate.edu) and DIA(k_m825@txstate.edu) as collaborators.
    - Your git repo must be: TeamNameSudokuProject, e.g., Team Name: Far Cry 6, Git Repo, FarCry6SudokuProject
    - You will submit a pdf file in canvas: including link to your repository, and description in each function that you have to write

Now do following (Non CLion, VSCode users)

  - Install CMake (If not install CMAKE min version 3.27)
  - Install Cmake extension for VS Code from Extension Manager
  - Create a directory named 'cmake-build-debug' inside the main project
  - Now from terminal run: cmake -B ./cmake-build-debug
  - Now from terminal run: cmake --build ./cmake-build-debug
  - Now you can find your executable inside the cmake-build-debug folder: "TeamNameSudokuProject"
  - Now you can run this executable from terminal(assuming you are in ProjectDir): ./cmake-build-debug/SudokuProject
  - Note windows user might need forward slash(\), instead of backward slash(/)
  - You will see your output in a new folder called as "TeamNameSudokuProject/data/", with subdirectories ("puzzles" and "solutions")
    
For CLION users only, this project might not run right away.
  
  - Go to File->Reload CMake Project; this will create a directory named cmake-build-debug
  - Now You can simply use play button to run this project
  - You can also use debug button to debug the project
  - You will see your output in a new folder called as "TeamNameSudokuProject/cmake-build-debug/data/", with subdirectories ("puzzles" and "solutions")

Grading Criteria
  - Total: 100 pts
  - 10 pts - GroupWork Photos
  - 10 pts - Being Nice
  - 20 pts - Generate 1000 Unique Sudoku Problem

      - Requirement no. 1: Must save this puzzle to data/puzzles folder 
      - Requirement no. 2: Must solve this puzzle
      - Requirement no. 3: Must save solved puzzle to data/solutions folder
      - No need to submit data folder
  
  - 20 pts - Documentation
    
      - Requirement no. 1: Every file must have header documentation /*doc...*/ on its top explaining the purpose of that file
      - Requirement no. 2: Every function(even those I provided) must have /*doc for function...*/, which should be the first thing in your function body explaining the purpose of that function

  - 40 pts - Coding
      - Complete source code @ src/generator.cpp. 
      - You need to re-write generateBoard which generates random numbers
      - You are allowed to write any helper functions you need within this source file
      - If you write any helper functions here you need to update your include/generator.h as well
      - If I were you.... [Warning::: I may be wrong!! you need to validate my idea, better work on your idea]
        - I would create an empty sudoku bord all filled with 0
            <pre>
            0   0   0   |   0   0   0   |   0   0   0
            0   0   0   |   0   0   0   |   0   0   0 
            0   0   0   |   0   0   0   |   0   0   0 
            .........................................
            0   0   0   |   0   0   0   |   0   0   0 
            0   0   0   |   0   0   0   |   0   0   0 
            0   0   0   |   0   0   0   |   0   0   0 
            .........................................
            0   0   0   |   0   0   0   |   0   0   0 
            0   0   0   |   0   0   0   |   0   0   0 
            0   0   0   |   0   0   0   |   0   0   0
            </pre>
        - Then I would select either diagonal from left to right or diagonal from right to left, lets say left-to-right
            <pre>
            x   x   x   |   0   0   0   |   0   0   0
            x   x   x   |   0   0   0   |   0   0   0 
            x   x   x   |   0   0   0   |   0   0   0 
            .........................................
            0   0   0   |   x   x   x   |   0   0   0 
            0   0   0   |   x   x   x   |   0   0   0 
            0   0   0   |   x   x   x   |   0   0   0 
            .........................................
            0   0   0   |   0   0   0   |   x   x   x 
            0   0   0   |   0   0   0   |   x   x   x 
            0   0   0   |   0   0   0   |   x   x   x
            </pre>
        - Then I would run three for loops
            - k -> 0 to <4, right after k loop I would define index = 0;
            - i -> k*3 to <k*3+3
            - j -> k*3 to <k*3+3
          - Inside the most inner loop define int vector with element 1, 2, 3, 4, 5, 6, 7, 8, and 9
          - Random shuffle that vector
          - now within the innermost loop I would grab that vector, say, numbers[index], 
          - I would assign numbers[index] to [i][j] th position of board
          - I would increment the index
          - This should yield something like this(note: this is just an example):
            <pre>
            1   4   5   |   0   0   0   |   0   0   0
            2   3   6   |   0   0   0   |   0   0   0 
            9   8   7   |   0   0   0   |   0   0   0 
            .........................................
            0   0   0   |   1   4   9   |   0   0   0 
            0   0   0   |   7   2   8   |   0   0   0 
            0   0   0   |   6   5   3   |   0   0   0 
            .........................................
            0   0   0   |   0   0   0   |   1   6   4 
            0   0   0   |   0   0   0   |   2   7   9 
            0   0   0   |   0   0   0   |   8   3   5
            </pre>
      - Now I would use solveBoard from sudoku to solve the board
      - Once the board is solved, I would run another 2 loops
          - i -> 0 to <9
          - j -> 0 to <9
        - Inside the most inner loop I would use random number generator
          - Option a, something like, int_random_number = ....???... // this should give you random number from 1 to 100, discrete value
            - If you choose this option I would make all [i][j] board piece 0 whenever random_number > 50, this way we eliminate 50% of the board piece
          - Option b, something like, float_random_number = ....???... // this should give you random number from 0 to 1, continuous value
            - If you choose this option I would make all [i][j] board piece 0 whenever random_number > 0.5, this way we eliminate 50% of the board
      - Once the board is created, I would return that board and I am done
