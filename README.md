Sudoku Game (C++)

A console-based Sudoku game built in C++ using 2D arrays and modular functions.
It allows the user to play Sudoku, get hints, check mistakes, erase entries, clear the board, and auto-solve the puzzle while keeping track of the score.

Team Members:
Hassaan Ali Khoso (Logic Designer & Documenter)
Hassan Ghazi (Programmer & Documenter)

Overview:
This project produces a fully interactive Sudoku game in the console.
The player selects difficulty then makes moves one by one if he wants he can receive hints as well. The program checks mistakes, resets the board and autocompletes the entire board if prompted. The program uses a scoring system and ensures all moves follow Sudoku rules.
Sudoku is not only an enjoyable hobby, it also has many proven cognitive and psychological benefits. It improves logical thinking and enhances problem solving ability.

Features:
•	Difficulty selection: Easy, Medium, Hard
•	Visualize the Sudoku board with 2D arrays
•	Make a move by entering row, column, and the value per empty place
•	Full move validation: row, column and 3×3 grid
•	Hint system which reveals one correct empty cell
•	Mistake checker - compares board to solution
•	Clear filled cells (except original ones)
•	Clear board to reset the puzzle
•	Autocomplete the puzzle (full solve)
•	Scoring System:
o	+10 correct move
o	-5 illegal move
o	-10 hint
o	-5 delete
o	-10 clear board
o	−20 autocomplete
•	The score never goes below zero
•	Victory screen/prompt to play again
•	Color-coded board for readability

Program Design and Logic:
Grid:
	The program uses the following 2D arrays:
- board
- orgboard
- solution
along with the following hardcoded arrays for different difficulty levels:
- easyboard and easysolution
- mediumboard and mediumsolution
- hardboard and hardsolution
the general arrays are let equal to the respective difficulty-wise arrays depending upon the difficulty chosen.
The grid is colour coded for readibility.
Functions Used:
PrintGrid = prints the board
IsValid = validates moves and checks if it follows Sudoku rules
CompletionCheck = verifies if the board is completed
GiveHint = prints one empty square
Checker = counts and displays errors
Erase = clears one entry
ClearBoard = clears the whole board
AutoComplete = fills the entire board
DiffSelector = loads a board based on three difficulty levels
SetColour = colors the output
TypeText = animates output text

Hint Approach:
The program will display the correct input for the first unfilled square (the square having the smallest row first and then the smallest column, starting from 1). The hint will last for 3 seconds.

Execution Instructions:
Compiling and Running
Retrieve the source code from github and run the code on any suitable compiler.
Game Instructions:
1. Choose difficulty level
2. Solve the puzzle using the following provided featuers:
- Make a move:
Choose row(1-9), column (1-9) and input(1-9)
- Hint
- Check for mistakes
- Erase
Choose row(1-9) and column (1-9)
- Clear board
- Autocomplete
3.	After completing the puzzle and winning, choose wether to play again or to exit the game. If the game is played again, the same instructions will be followed.

AI Tool Reflection:
AI was used at a few instances to help in debugging.

Future Improvements:
• Graphical User Interface
• Random Board generator
• Timer based scoring
• Save and load feature for solving the board in multiple sittings
• More level based progressions
