/**
 * sudokuSolver.cpp
 * Implements the sudokuSolver class using backtracking
 * Includes methods for board management and validation
 */

#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <random>
#include "sudokuSolver.h"

// Constructor: Initializes all cells to 0
sudokuSolver::sudokuSolver() {
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            board[i][j] = 0;
}

// Loads an input puzzle into the board
void sudokuSolver::loadBoard(int input[9][9]) {
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            board[i][j] = input[i][j];
}

void sudokuSolver::displayBoard() {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i != 0)
            std::cout << "------+-------+------\n";
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0 && j != 0)
                std::cout << "| ";
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool sudokuSolver::findEmpty(int &row, int &col) {
    for (row = 0; row < 9; ++row)
        for (col = 0; col < 9; ++col)
            if (board[row][col] == 0)
                return true;
    return false;
}

// Checks if placing 'num' at board[row][col] is safe
bool sudokuSolver::isSafe(int row, int col, int num) {
    for (int i = 0; i < 9; ++i)
        if (board[row][i] == num || board[i][col] == num)
            return false;
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Backtracking algorithm to solve the puzzle
bool sudokuSolver::solve() {
    int row, col;
    if (!findEmpty(row, col))
        return true;
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(row, col, num)) {
            board[row][col] = num;
            if (solve())
                return true;
            // Backtrack
            board[row][col] = 0;
        }
    }
    // Triggerbacktrack
    return false;
}

bool sudokuSolver::fillBoard() {
    int row, col;
    if (!findEmpty(row, col))
        return true;
    std::vector<int> nums{1,2,3,4,5,6,7,8,9};
    std::shuffle(nums.begin(), nums.end(), std::default_random_engine(std::random_device{}()));
    for (int num : nums) {
        if (isSafe(row, col, num)) {
            board[row][col] = num;
            if (fillBoard())
                return true;
            board[row][col] = 0;
        }
    }

    return false;
}

// Creates a playable puzzle by removing cells from a valid board
void sudokuSolver::generatePuzzle(int emptyCells) {
    std::srand(static_cast<unsigned>(std::time(0)));
    // First fill the board completely
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            board[i][j] = 0;
    fillBoard();
    // Randomly remove cells
    int removed = 0;
    while (removed < emptyCells) {
        int i = rand() % 9;
        int j = rand() % 9;
        if (board[i][j] != 0) {
            int backup = board[i][j];
            board[i][j] = 0;
            // Copy and test solvability
            sudokuSolver temp;
            temp.loadBoard(board);
            if (!temp.solve()) {
                board[i][j] = backup;
                continue;
            }
            ++removed;
        }
    }
}