/**
 * main.cpp
 * MainFile of the Sudoku Solver program
 * Loads a sample puzzle and displays the initial board
 * Attempts to solve it using backtracking, and displays the result
 */

#include <iostream>
#include "SudokuSolver.h"

int main() {
    sudokuSolver solver;
    // Generates random solvable board with 40 empty cells
    solver.generatePuzzle(40);
    std::cout << "Initial Sudoku Board:\n";
    std::cout << "---------------------\n";
    solver.displayBoard();
    if (solver.solve()) {
        std::cout << "\nSolved Sudoku Board:\n";
        std::cout << "---------------------\n";
        solver.displayBoard();
    } else {
        std::cout << "\nNo solution exists for this board!\n";
    }
    // Press any key to exit
    std::cout << "\n";
    system("pause");
    return 0;
}