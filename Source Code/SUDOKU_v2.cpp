#include<iostream>
#include<chrono>
#include<thread>
#include<windows.h>
using namespace std;

// Variable declaration

int row;
int col;
int input;
int score = 0;
int diff = 0;
int choice = 0;
int endchoice = 1;

bool BoardComplete = false;

// INITIALIZATION OF GRIDS

int board[9][9] =     { {0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},

						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},

						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0} };

int easyboard[9][9] =	  { {5,3,0, 0,7,0, 0,0,0},
						    {6,0,0, 1,9,5, 0,0,0},
						    {0,9,8, 0,0,0, 0,6,0},

						    {8,0,0, 0,6,0, 0,0,3},
						    {4,0,0, 8,0,3, 0,0,1},
						    {7,0,0, 0,2,0, 0,0,6},

						    {0,6,0, 0,0,0, 2,8,0},
						    {0,0,0, 4,1,9, 0,0,5},
						    {0,0,0, 0,8,0, 0,7,9} };

int mediumboard[9][9] = { {0,2,0, 6,0,8, 0,0,0},
						  {5,8,0, 0,0,9, 7,0,0},
						  {0,0,0, 0,4,0, 0,0,0},

						  {3,7,0, 0,0,0, 5,0,0},
						  {6,0,0, 0,0,0, 0,0,4},
						  {0,0,8, 0,0,0, 0,1,3},

						  {0,0,0, 0,2,0, 0,0,0},
						  {0,0,9, 8,0,0, 0,3,6},
						  {0,0,0, 3,0,6, 0,9,0} };

int hardboard[9][9] = {
							{0,0,0, 2,6,0, 7,0,1},
							{6,8,0, 0,7,0, 0,9,0},
							{1,9,0, 0,0,4, 5,0,0},

							{8,2,0, 1,0,0, 0,4,0},
							{0,0,4, 6,0,2, 9,0,0},
							{0,5,0, 0,0,3, 0,2,8},

							{0,0,9, 3,0,0, 0,7,4},
							{0,4,0, 0,5,0, 0,3,6},
							{7,0,3, 0,1,8, 0,0,0}};

int orgboard[9][9] =  { {0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},

						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},

						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0} };

 
int solution[9][9] = { {0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},

						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},

						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0},
						{0,0,0, 0,0,0, 0,0,0} };

int easysolution[9][9] = { {5,3,4, 6,7,8, 9,1,2},
					       {6,7,2, 1,9,5, 3,4,8},
					       {1,9,8, 3,4,2, 5,6,7},

					       {8,5,9, 7,6,1, 4,2,3},
					       {4,2,6, 8,5,3, 7,9,1},
					       {7,1,3, 9,2,4, 8,5,6},

					       {9,6,1, 5,3,7, 2,8,4},
					       {2,8,7, 4,1,9, 6,3,5},
					       {3,4,5, 2,8,6, 1,7,9} };
int mediumsolution[9][9] = {
							{1,2,3, 6,7,8, 9,4,5},
							{5,8,4, 2,3,9, 7,6,1},
							{9,6,7, 1,4,5, 3,2,8},

							{3,7,2, 4,6,1, 5,8,9},
							{6,9,1, 5,8,3, 2,7,4},
							{4,5,8, 7,9,2, 6,1,3},

							{8,3,6, 9,2,4, 1,5,7},
							{2,1,9, 8,5,7, 4,3,6},
							{7,4,5, 3,1,6, 8,9,2} };
int hardsolution[9][9] = {
							{4,3,5, 2,6,9, 7,8,1},
							{6,8,2, 5,7,1, 4,9,3},
							{1,9,7, 8,3,4, 5,6,2},

							{8,2,6, 1,9,5, 3,4,7},
							{3,7,4, 6,8,2, 9,1,5},
							{9,5,1, 7,4,3, 6,2,8},

							{5,1,9, 3,2,6, 8,7,4},
							{2,4,8, 9,5,7, 1,3,6},
							{7,6,3, 4,1,8, 2,5,9}};

// Function declaration

void PrintGrid();
void IsValid();
void CompletionCheck();
void AutoComplete();
void GiveHint();
void Checker();
void Erase();
void ClearBoard();
void DiffSelector();
void SetColour(int);
void TypeText(string);

int main()
{	
	// Welcome Message

	TypeText("Welcome to Sudoku");
	cout << endl;

	// Game Loop

	while (endchoice == 1)
	{
		// Difficulty Selection

		while (diff > 3 || diff < 1)
		{	
			cout << "Choose difficulty level:\n1.Easy\n2.Medium\n3.Hard\n";
			cin >> diff;
			if (diff > 3 || diff < 1)
			{
				cout << "Invalid Input" << endl;
				cout << endl;
			}
		}

		DiffSelector();
		system("cls");


		while (BoardComplete == false)
		{
			PrintGrid();
			choice = 0;

			while (choice > 6 || choice < 1)
			{
				cout << "1.Make a move\n2.Hint\n3.Check for Mistakes\n4.Erase\n5.Clear Board\n6.Autocomplete\n";
				cin >> choice;

				if (choice == 1)
				{
					row = 0;
					col = 0;
					input = 0;

					while (row < 1 || row > 9)
					{
						cout << "Enter row (1-9): ";
						cin >> row;
						if (row < 1 || row > 9)
						{
							cout << "Invalid Input" << endl;
							cout << endl;
						}
					}
					while (col < 1 || col > 9)
					{
						cout << "Enter column (1-9): ";
						cin >> col;
						if (col < 1 || col > 9)
						{
							cout << "Invalid Input" << endl;
							cout << endl;
						}
					}
					while (input < 1 || input > 9)
					{
						cout << "Enter input (1-9): ";
						cin >> input;
						if (input < 1 || input > 9)
						{
							cout << "Invalid Input" << endl;
							cout << endl;
						}
					}

					IsValid();
					system("cls");
				}
				else if (choice == 2)
				{
					GiveHint();
					this_thread::sleep_for(chrono::milliseconds(3000));
					system("cls");
				}
				else if (choice == 3)
				{
					Checker();
					system("cls");
				}
				else if (choice == 4)
				{
					row = 0;
					col = 0;
					input = 0;

					while (row < 1 || row > 9)
					{
						cout << "Enter row (1-9): ";
						cin >> row;
						if (row < 1 || row > 9)
						{
							cout << "Invalid Input" << endl;
							cout << endl;
						};
					}
					while (col < 1 || col > 9)
					{
						cout << "Enter column (1-9): ";
						cin >> col;
						if (col < 1 || col > 9)
						{
							cout << "Invalid Input" << endl;
							cout << endl;
						}
					}
					Erase();
					system("cls");
				}
				else if (choice == 5)
				{
					ClearBoard();
					system("cls");
				}
				else if (choice == 6)
				{
					AutoComplete();
					system("cls");
					PrintGrid();
				}
				CompletionCheck();

				if (choice > 6 || choice < 1)
				{
					cout << "Invalid Input" << endl;
					cout << endl;
				}
			}

		}

		cout << "You win!" << endl << "Your score: " << score << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "1.Play Again\n2.Exit Sudoku\n";
		cin >> endchoice;
		BoardComplete = false;
		diff = 0;
		score = 0;
		system("cls");

	}
	TypeText("Have a nice day!");


	return 0;
}

// Definition of Functions

void PrintGrid()
{
	SetColour(10);
	cout << "   1  2  3     4  5  6     7  8  9" << endl << endl;
	SetColour(7);

	for (int i = 0; i < 9; i++)
	{
		SetColour(10);
		cout << i + 1 << " ";
		SetColour(7);
		int j = 0;
		for (; j < 3; j++)
		{
			if (board[i][j] == orgboard[i][j] && board[i][j] != 0)
			{
				SetColour(9);
				cout << " " << board[i][j] << " ";
				SetColour(7);
			}
			else
			{
				cout << " " << board[i][j] << " ";
			}
			
		}
		SetColour(10);
		cout << " | ";
		SetColour(7);
		for (; j < 6; j++)
		{
			if (board[i][j] == orgboard[i][j] && board[i][j] != 0)
			{
				SetColour(9);
				cout << " " << board[i][j] << " ";
				SetColour(7);
			}
			else
			{
				cout << " " << board[i][j] << " ";
			}
		}
		SetColour(10);
		cout << " | ";
		SetColour(7);
		for (; j < 9; j++)
		{
			if (board[i][j] == orgboard[i][j] && board[i][j] != 0)
			{
				SetColour(9);
				cout << " " << board[i][j] << " ";
				SetColour(7);
			}
			else
			{
				cout << " " << board[i][j] << " ";
			}
			if (i == 0 && j == 8)
			{
				cout << "			Score: " << score;
			}
		}
		cout << endl;
		if (i == 2 || i == 5)
		{
			SetColour(10);
			cout << "   ---------------------------------" << endl;
			SetColour(7);
		}
	}
	cout << endl;

}


void IsValid()
{
	bool ColValid = true;
	bool RowValid = true;
	bool BoxValid = true;

	if (orgboard[row - 1][col - 1] != 0)
	{
		cout << "You cannot change a fixed square" << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
		return;
	}

	//ROWVALID

	for (int i = 0; i < 9; i++)
	{
		if (board[row - 1][i] == input)
		{
			RowValid = false;
		}
	}

	//COLUMNVALID

	for (int i = 0; i < 9; i++)
	{
		if (board[i][col - 1] == input)
		{
			ColValid = false;
		}
	}

	//BOXVALID

	//BOX1
	if (row > 0 && row < 4 && col > 0 && col < 4)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == input)
				{
					BoxValid = false;
				}
			}
		}
	}
	//BOX2
	if (row > 0 && row < 4 && col > 3 && col < 7)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (board[i][j] == input)
				{
					BoxValid = false;
				}
			}
		}
	}
	//BOX3
	if (row > 0 && row < 4 && col > 6 && col < 10)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (board[i][j] == input)
				{
					BoxValid = false;
				}
			}
		}
	}
	//BOX4
	if (row > 3 && row < 7 && col > 0 && col < 4)
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == input)
				{
					BoxValid = false;
				}
			}
		}
	}
	//BOX5
	if (row > 3 && row < 7 && col > 3 && col < 7)
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (board[i][j] == input)
				{
					BoxValid = false;
				}
			}
		}
	}
	//BOX6
	if (row > 3 && row < 7 && col > 6 && col < 10)
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (board[i][j] == input)
				{
					BoxValid = false;
				}
			}
		}
	}
	//BOX7
	if (row > 6 && row < 10 && col > 0 && col < 4)
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == input)
				{
					BoxValid = false;
				}
			}
		}
	}
	//BOX8
	if (row > 6 && row < 10 && col > 3 && col < 7)
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				if (board[i][j] == input)
				{
					BoxValid = false;
				}
			}
		}
	}
	//BOX9
	if (row > 6 && row < 10 && col > 6 && col < 10)
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				if (board[i][j] == input)
				{
					BoxValid = false;
				}
			}
		}
	}

	// FINAL CHECK

	if (RowValid && ColValid && BoxValid)
	{
		board[row - 1][col - 1] = input;
		score = score + 10;
		if (score < 0)
		{
			score = 0;
		}
	}
	else
	{
		cout << "Incorrect" << endl;
		score = score - 5;
		if (score < 0)
		{
			score = 0;
		}
		this_thread::sleep_for(chrono::milliseconds(3000));
	}
	
}

void CompletionCheck()
{
	BoardComplete = true;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)
			{
				BoardComplete = false;
				return;
			}
		}
	}

} 
void AutoComplete()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			score = score - 20;
			if (score < 0)
			{
				score = 0;
			}
			board[i][j] = solution[i][j];
		}
	}
	
}

void GiveHint()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)
			{
				score = score - 10;
				if (score < 0)
				{
					score = 0;
				}
				cout << "row " << i + 1 << ",column " << j + 1 << ": " << solution[i][j];
				return;
			}
		}
	}
}

void Erase()
{
	if (orgboard[row - 1][col - 1] != 0)
	{
		cout << "You cannot erase a fixed square" << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
		return;
	}
	score = score - 5;
	if (score < 0)
	{
		score = 0;
	}
	board[row - 1][col - 1] = 0;
}

void ClearBoard()
{
	for (int i= 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			score = score - 10;
			if (score < 0)
			{
				score = 0;
			}
			board[i][j] = orgboard[i][j];

		}
	}

}

void Checker()
{
	int mistakes = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != solution[i][j] && board[i][j] != 0)
			{
				score = score - 5;
				if (score < 0)
				{
					score = 0;
				}
				mistakes++;
			}
		}
	}
	cout << "You have made " << mistakes << " mistakes (incorrectly filled squares)";
	this_thread::sleep_for(chrono::milliseconds(3000));
}

void DiffSelector()
{
	if (diff == 1)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				board[i][j] = easyboard[i][j];
				orgboard[i][j] = easyboard[i][j];
				solution[i][j] = easysolution[i][j];
			}
		}
	}
	if (diff == 2)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				board[i][j] = mediumboard[i][j];
				orgboard[i][j] = mediumboard[i][j];
				solution[i][j] = mediumsolution[i][j];
			}
		}
	}
	if (diff == 3)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				board[i][j] = hardboard[i][j];
				orgboard[i][j] = hardboard[i][j];
				solution[i][j] = hardsolution[i][j];
			}
		}
	}
}

void SetColour(int colour)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
}

void TypeText(string x)
{
	for (int i = 0; i < x.length(); i++)
	{
		cout << x[i];
		this_thread::sleep_for(chrono::milliseconds(50));
	}
}