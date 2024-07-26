#include <iostream>

void drawGrid(char* grid);
void playerChoice(int &currentPlayer, char* grid, int &player, char &symbol);
bool checkWinner(char* grid, char &symbol, int &player);
bool playAgain();
bool isDraw(char* grid);
void switchPlayer(int &currentPlayer, char &symbol);
void resetGame(char* grid, int& startPlayer, int& currentPlayer, char& symbol);


int main()
{
	//grid
	char markers[9] = {'1','2','3','4','5','6','7','8','9'};

	//playerinfo
	int currentPlayer = 1;
	char symbol = 'X';
	bool playing = true;
	int startPlayer = currentPlayer;

	//game loop
	while (playing)
	{
		drawGrid(markers);
		playerChoice(currentPlayer, markers, currentPlayer, symbol);

		if (checkWinner(markers, symbol, currentPlayer))
		{
			if (playAgain())
			{
				resetGame(markers, startPlayer, currentPlayer, symbol);
			}
			else
			{
				break;
			}
		}
		else
		{
			switchPlayer(currentPlayer, symbol);
		}
	}

	return 0;
}

void drawGrid(char* grid)
{
	system("cls");
	std::cout << "+-----+-----+-----+" << std::endl;
	std::cout << "|  " << grid[0] << "  |  " << grid[1] << "  |  " << grid[2] << "  |" << std::endl;
	std::cout << "+-----+-----+-----+" << std::endl;
	std::cout << "|  " << grid[3] << "  |  " << grid[4] << "  |  " << grid[5] << "  |" << std::endl;
	std::cout << "+-----+-----+-----+" << std::endl;
	std::cout << "|  " << grid[6] << "  |  " << grid[7] << "  |  " << grid[8] << "  |" << std::endl;
	std::cout << "+-----+-----+-----+" << std::endl;
}

void playerChoice(int &currentPlayer, char* grid, int &player, char &symbol)
{
	int input = -1;
	do
	{
		std::cout << "Player: " << currentPlayer << " Type a number to make a choice!" << std::endl;
		std::cin >> input;

		if (input >= 1 && input <= 9)
		{
			if (grid[input - 1] == 'X' || grid[input - 1] == 'Y')
			{
				std::cout << "Cell already picked, please choose again! " << std::endl;
			}
			else
			{
				break;
			}
		}
		else
		{
			std::cout << "Please choose a number between 1-9 " << std::endl;
			std::cin.clear();
		}
	} while (true);

	grid[input-1] = symbol;
}

bool checkWinner(char* grid, char &symbol, int &player)
{
	if (grid[0] == symbol && grid[1] == symbol && grid[2] == symbol
		|| grid[3] == symbol && grid[4] == symbol && grid[5] == symbol
		|| grid[6] == symbol && grid[7] == symbol && grid[8] == symbol
		|| grid[0] == symbol && grid[3] == symbol && grid[6] == symbol
		|| grid[1] == symbol && grid[4] == symbol && grid[7] == symbol
		|| grid[2] == symbol && grid[5] == symbol && grid[8] == symbol)
	{
		drawGrid(grid);
		std::cout << "Player: " << player << " WINS!" << std::endl;
		return true;
	}
	else if (isDraw(grid))
	{
		drawGrid(grid);
		std::cout << "Its a draw! " << std::endl;
		return true;
	}
	return false;
}

bool playAgain()
{
	char input;
	do
	{
		std::cout << "Do you want to play again? Y/N: " << std::endl;
		std::cin >> input;

		if (input != 'Y' && input != 'N')
		{
			std::cin.clear();
			std::cout << "Please input Y or N " << std::endl;
		}
		if (input == 'Y')
		{
			return true;
		}
		if (input == 'N')
		{
			return false;
		}

	} while (true);
}

bool isDraw(char* grid)
{
	for (int i = 0; i < 9; i++)
	{
		if (grid[i] != 'X' && grid[i] != 'Y')
		{
			return false;
		}
	}
	return true;
}

void switchPlayer(int &currentPlayer, char &symbol)
{
	if (currentPlayer == 1)
	{
		currentPlayer = 2;
		symbol = 'Y';
	}
	else if (currentPlayer == 2)
	{
		currentPlayer = 1;
		symbol = 'X';
	}
}

void resetGame(char* grid, int &startPlayer, int &currentPlayer, char &symbol)
{
	for (int i = 0; i < 9; i++)
	{
		grid[i] = char(i + 49);
	}

	if (startPlayer == 1)
	{
		currentPlayer = 2;
		symbol = 'Y';
	}
	else if (startPlayer == 2)
	{
		currentPlayer = 1;
		symbol = 'X';
	}

	startPlayer = currentPlayer;
}
