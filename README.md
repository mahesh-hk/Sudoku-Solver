
# Sudoku Solver with Random Puzzle Generator

A C++ Sudoku solver that uses backtracking to solve puzzles that are randomly generated with a customizable number of empty cells.


## Features

- 🎲 Random puzzle generator (with solvability checking)
- 🖨 Clean ASCII board output with 3x3 box formatting
- ✔ Verifies all placements for Sudoku rules



## How it Works

- A full valid board is first generated with random values
- Then a number of cells are blanked out randomly (default: 40)
- The backtracking solver attempts to fill the blanks
- All generated puzzles are guaranteed to be solvable


## Build and Run

Clone the project:

```bash
  git clone https://github.com/mahesh-hk/Sudoku-Solver
```

Navigate to project directory:

```bash
  cd Sudoku-Solver
```

Compile using:

```bash
  g++ -std=c++17 main.cpp SudokuSolver.cpp -o sudoku
```

Run using:

```bash
  ./sudoku
```
Alternatively, run the .exe file if compiled on Windows.


When using an IDE like `CLion` or `Code::Blocks` import the project and run directly.
## Requirements

- C++ 17 compatible compiler (e.g., `g++`, `clang++`)
- CMake or g++ (for manual compilation)
- Windows, Linux, or macOS
- Terminal / Command Prompt
- Optional: CLion or `Code::Blocks` for an easier IDE-based experience


## Releases

[Download the latest Windows executable](https://github.com/mahesh-hk/Sudoku-Solver/releases/latest)
## Authors

- [@mahesh-hk](https://github.com/mahesh-hk)


## License

MIT License. See LICENSE file for details.

