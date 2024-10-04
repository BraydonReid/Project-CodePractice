cmake_minimum_required(VERSION 3.27)
project(SudokuProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(SudokuProject main.cpp
        include/sudoku.h
        include/sudokuio.h
        src/sudoku.cpp
        src/sudokuio.cpp
        src/generator.cpp
        include/generator.h
        src/utility.cpp
        include/utility.h)
