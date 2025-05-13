/**
 * sudokuSolver.h
 * Header file for the SudokuSolver class
 * Declares methods for solving a 9x9 Sudoku puzzle using backtracking
 */

#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

class sudokuSolver {
private:
    int board[9][9];                              // Internal 9x9 Sudoku grid
    bool isSafe(int row, int col, int num);       // Checks if number placement is valid
    bool findEmpty(int &row, int &col);

public:
    sudokuSolver();                               // Constructor initializes the board
    void loadBoard(int input[9][9]);
    void generatePuzzle(int emptyCells = 40);
    bool fillBoard();
    void displayBoard();
    bool solve();
};

#endif