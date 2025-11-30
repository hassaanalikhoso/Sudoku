Sudoku Game (C++)

A console-based Sudoku game built in C++ using 2D arrays and modular functions.
It allows the user to play Sudoku, get hints, check mistakes, erase entries, clear the board, and auto-solve the puzzle while keeping track of the score.

Team Members

Hassaan Ali Khoso (Logic Designer & Documenter)
Hassan Ghazi (Programmer & Documenter)

Overview

This project implements a fully interactive Sudoku game in the terminal.
The player selects difficulty, makes moves, receives hints, checks mistakes, and can even autocomplete the entire board.
The program uses a scoring system and ensures all moves follow Sudoku rules.

Features

• Difficulty selection: Easy, Medium, Hard
• Display of Sudoku board using 2D arrays
• Make a move by entering row, column, and value
• Full move validation: row, column, and 3×3 subgrid
• Hint system that reveals one correct empty cell
• Mistake checker comparing the board with the solution
• Erase filled cells (except original ones)
• Clear board to reset the puzzle
• Autocomplete the puzzle (full solve)
• Score system:
+10 correct move
−5 invalid move
−10 hint
−5 erase
−10 clear board
−20 autocomplete
• Score never goes below zero
• Winning screen + option to play again
• Color-coded board for readability

Program Logic (Summary)

The program uses multiple functions for clarity and modularity:

PrintGrid — displays the board
IsValid — checks whether a move follows Sudoku rules
CompletionCheck — verifies if the puzzle is solved
GiveHint — prints one correct empty value
Checker — counts and displays mistakes
Erase — removes user-filled entries
ClearBoard — resets puzzle to original
AutoComplete — fills entire solution
DiffSelector — loads puzzle and solution based on difficulty
SetColour — colors the board
TypeText — prints text with animation effect

How to Compile and Run

Compile:
g++ sudoku.cpp -o sudoku

Run:
./sudoku

(Windows users may compile using MinGW.)

Test Cases (Summary)

Normal cases:
– Difficulty selection
– Making moves
– Hints
– Checking mistakes
– Erasing
– Clearing board
– Autocomplete
– Play again / exit

Edge cases:
– Invalid difficulty input
– Invalid menu choice
– Invalid row/column/value
– Trying to change fixed cells

GitHub Repository

https://github.com/hassaanalikhoso/Sudoku

AI Tool Usage

AI was used for structuring the documentation only (README writing), not for code writing.

Future Improvements

• GUI version
• Random puzzle generator
• Timer-based scoring
• Save and load feature
• More difficulty modes

