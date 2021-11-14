#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

char board[9] = { '-','-', '-', '-', '-', '-', '-', '-', '-' };
bool machineIsFirst = false;

void printField();
void getFirstMove();
void Xor0choiceChecker(char firstMove);
void firstMachineMove();
int makeMove(int counter);
void playingGame();
void machineMove();
void startCheckingMoves(char y);
void horizontalCheckForWin(char y);
void verticalCheckForWin(char y);
void checkForDefeat(char y);
void horizontalCheckForDefeat(char y);
void verticalCheckForDefeat(char y);
void twoEmptyFields(char y);
void priorityMove(char y);
void randomMove(char y);
bool hasWon(char player);
void printGameResult();
bool drawChecker(char arr[9]);
void clearBoard();


int main()
{
	srand(time(NULL));

	getFirstMove();
	playingGame();

	return 0;
}

void printField()
{
	system("cls");
	cout << "Move option" << endl << endl;
	cout << "-1-|-2-|-3-" << endl;
	cout << "-4-|-5-|-6-" << endl;
	cout << "-7-|-8-|-9-" << endl;

	cout << endl << "Game board" << endl << endl;
	cout << "-" << board[0] << "-|-" << board[1] << "-|-" << board[2] << "-" << endl;
	cout << "-" << board[3] << "-|-" << board[4] << "-|-" << board[5] << "-" << endl;
	cout << "-" << board[6] << "-|-" << board[7] << "-|-" << board[8] << "-" << endl;
}

void getFirstMove()
{
	char firstMove;
	cout << "Will you play noughts or crosses? (0 or x): ";
	cin >> firstMove;

	Xor0choiceChecker(firstMove);
}

void Xor0choiceChecker(char firstMove)
{
	machineIsFirst = false;
	while (firstMove != 'x' and firstMove != '0') {
		cout << "Please, enter your choice - 0 or x: ";
		cin >> firstMove;
	}
	if (firstMove == 'x')
	{
		playingGame();
	}
	else if (firstMove == '0')
	{
		firstMachineMove();
	}
}

void firstMachineMove()
{
	machineIsFirst = true;
	char move = (rand() % 7);
	while (move == 1 or move == 3 or move == 5)
	{
		move = (rand() % 7);
	}
	board[move] = 'X';
	playingGame();
}

int makeMove(int counter)
{
	int move = 0;

	if (counter % 2 == 0) {
		cout << endl << "Your move 'X' is ";
		cin >> move;
	}
	else {
		cout << endl << "Your move '0' is ";
		cin >> move;
	}

	while (move > 9 || move < 1 || board[move - 1] != '-') {
		cout << "Please, enter a legal move [1..9]: ";
		cin >> move;
	}
	return move;
}

void playingGame()
{
	if (machineIsFirst)
	{
		for (int i = 1; i <= 9; i += 2)
		{
			if (drawChecker(board))
			{
				printGameResult();
			}
			printField();
			int humanMove = makeMove(i);
			board[humanMove - 1] = '0';
			if (hasWon('0'))
			{
				printGameResult();
			}
			machineMove();
			if (hasWon('X'))
			{
				printGameResult();
			}
		}
	}
	else
	{
		for (int i = 0; i <= 10; i += 2)
		{
			printField();
			int humanMove = makeMove(i);
			board[humanMove - 1] = 'X';
			if (hasWon('X'))
			{
				printGameResult();
			}
			if (drawChecker(board))
			{
				printGameResult();
			}
			machineMove();
			if (hasWon('0'))
			{
				printGameResult();
			}
		}
	}
}

void machineMove()
{
	if (machineIsFirst)
	{
		startCheckingMoves('X');
	}
	else
	{
		startCheckingMoves('0');
	}
}

void startCheckingMoves(char y)
{
	if (board[0] == y and board[4] == y and board[8] == '-')
	{
		board[8] = y;
	}
	else if (board[4] == y and board[8] == y and board[0] == '-')
	{
		board[0] = y;
	}
	else if (board[0] == y and board[8] == y and board[4] == '-')
	{
		board[4] = y;
	}
	else if (board[2] == y and board[4] == y and board[6] == '-')
	{
		board[6] = y;
	}
	else if (board[4] == y and board[6] == y and board[2] == '-')
	{
		board[2] = y;
	}
	else if (board[2] == y and board[6] == y and board[4] == '-')
	{
		board[4] = y;
	}
	else
	{
		horizontalCheckForWin(y);
	}
}

void horizontalCheckForWin(char y)
{
	if (board[0] == y and board[1] == 1 and board[2] == '-')
	{
		board[2] = y;
	}
	else if (board[1] == y and board[2] == y and board[0] == '-')
	{
		board[0] = y;
	}
	else if (board[0] == y and board[2] == y and board[1] == '-')
	{
		board[1] = y;
	}
	else if (board[3] == y and board[4] == y and board[5] == '-')
	{
		board[5] = y;
	}
	else if (board[4] == y and board[5] == y and board[3] == '-')
	{
		board[3] = y;
	}
	else if (board[3] == y and board[5] == y and board[4] == '-')
	{
		board[4] = y;
	}
	else if (board[6] == y and board[7] == y and board[8] == '-')
	{
		board[8] = y;
	}
	else if (board[7] == y and board[8] == y and board[6] == '-')
	{
		board[6] = y;
	}
	else if (board[6] == y and board[8] == y and board[7] == '-')
	{
		board[7] = y;
	}
	else
	{
		verticalCheckForWin(y);
	}
}

void verticalCheckForWin(char y)
{
	if (board[0] == y and board[3] == y and board[6] == '-')
	{
		board[6] = y;
	}
	else if (board[3] == y and board[6] == y and board[0] == '-')
	{
		board[0] = y;
	}
	else if (board[0] == y and board[6] == y and board[3] == '-')
	{
		board[3] = y;
	}
	else if (board[1] == y and board[4] == y and board[7] == '-')
	{
		board[7] = y;
	}
	else if (board[4] == y and board[7] == y and board[1] == '-')
	{
		board[1] = y;
	}
	else if (board[1] == y and board[7] == y and board[4] == '-')
	{
		board[4] = y;
	}
	else if (board[2] == y and board[5] == y and board[8] == '-')
	{
		board[8] = y;
	}
	else if (board[5] == y and board[8] == y and board[2] == '-')
	{
		board[2] = y;
	}
	else if (board[2] == y and board[8] == y and board[5] == '-')
	{
		board[5] = y;
	}
	else
	{
		checkForDefeat(y);
	}
}

void checkForDefeat(char y)
{
	if ((board[0] == board[4]) and board[0] != '-' and board[8] == '-')
	{
		board[8] = y;
	}
	else if ((board[4] == board[8]) and board[4] != '-' and board[0] == '-')
	{
		board[0] = y;
	}
	else if ((board[0] == board[8]) and board[0] != '-' and board[4] == '-')
	{
		board[4] = y;
	}
	else if ((board[2] == board[4]) and board[2] != '-' and board[6] == '-')
	{
		board[6] = y;
	}
	else if ((board[4] == board[6]) and board[4] != '-' and board[2] == '-')
	{
		board[2] = y;
	}
	else if ((board[2] == board[6]) and board[2] != '-' and board[4] == '-')
	{
		board[4] = y;
	}
	else
	{
		horizontalCheckForDefeat(y);
	}
}

void horizontalCheckForDefeat(char y)
{
	if ((board[0] == board[1]) and board[0] != '-' and board[2] == '-')
	{
		board[2] = y;
	}
	else if ((board[1] == board[2]) and board[1] != '-' and board[0] == '-')
	{
		board[0] = y;
	}
	else if ((board[0] == board[2]) and board[0] != '-' and board[1] == '-')
	{
		board[1] = y;
	}
	else if ((board[3] == board[4]) and board[3] != '-' and board[5] == '-')
	{
		board[5] = y;
	}
	else if ((board[4] == board[5]) and board[4] != '-' and board[3] == '-')
	{
		board[3] = y;
	}
	else if ((board[3] == board[5]) and board[3] != '-' and board[4] == '-')
	{
		board[4] = y;
	}
	else if ((board[6] == board[7]) and board[6] != '-' and board[8] == '-')
	{
		board[8] = y;
	}
	else if ((board[7] == board[8]) and board[7] != '-' and board[6] == '-')
	{
		board[6] = y;
	}
	else if ((board[6] == board[8]) and board[6] != '-' and board[7] == '-')
	{
		board[7] = y;
	}
	else
	{
		verticalCheckForDefeat(y);
	}
}

void verticalCheckForDefeat(char y)
{
	if ((board[0] == board[3]) and board[0] != '-' and board[6] == '-')
	{
		board[6] = y;
	}
	else if ((board[3] == board[6]) and board[3] != '-' and board[0] == '-')
	{
		board[0] = y;
	}
	else if ((board[0] == board[6]) and board[0] != '-' and board[3] == '-')
	{
		board[3] = y;
	}
	else if ((board[1] == board[4]) and board[1] != '-' and board[7] == '-')
	{
		board[7] = y;
	}
	else if ((board[4] == board[7]) and board[4] != '-' and board[1] == '-')
	{
		board[1] = y;
	}
	else if ((board[1] == board[7]) and board[1] != '-' and board[4] == '-')
	{
		board[4] = y;
	}
	else if ((board[2] == board[5]) and board[2] != '-' and board[8] == '-')
	{
		board[8] = y;
	}
	else if ((board[5] == board[8]) and board[5] != '-' and board[2] == '-')
	{
		board[2] = y;
	}
	else if ((board[2] == board[8]) and board[2] != '-' and board[5] == '-')
	{
		board[5] = y;
	}
	else
	{
		twoEmptyFields(y);
	}
}

void twoEmptyFields(char y)
{
	if (board[0] == y and (board[4] == '-' or board[8] == '-'))
	{
		if (board[4] == '-')
		{
			board[4] = y;
		}
		else if (board[8] == '-')
		{
			board[8] = y;
		}
	}
	else if (board[4] == y and (board[0] == '-' or board[8] == '-'))
	{
		if (board[0] == '-')
		{
			board[0] = y;
		}
		else if (board[8] == '-')
		{
			board[8] = y;
		}
	}
	else if (board[8] == y and (board[0] == '-' or board[4] == '-'))
	{
		if (board[4] == '-')
		{
			board[4] = y;
		}
		else if (board[0] == '-')
		{
			board[0] = y;
		}
	}
	else if (board[2] == y and (board[4] == '-' or board[6] == '-'))
	{
		if (board[4] == '-')
		{
			board[4] = y;
		}
		else if (board[6] == '-')
		{
			board[6] = y;
		}
	}
	else if (board[4] == y and (board[2] == '-' or board[6] == '-'))
	{
		if (board[2] == '-')
		{
			board[2] = y;
		}
		else if (board[6] == '-')
		{
			board[6] = y;
		}
	}
	else if (board[6] == y and (board[2] == '-' or board[4] == '-'))
	{
		if (board[2] == '-')
		{
			board[2] = y;
		}
		else if (board[4] == '-')
		{
			board[4] = y;
		}
	}
	else if (board[0] == y and (board[1] == '-' or board[2] == '-'))
	{
		if (board[2] == '-')
		{
			board[2] = y;
		}
		else if (board[1] == '-')
		{
			board[1] = y;
		}
	}
	else if (board[1] == y and (board[0] == '-' or board[2] == '-'))
	{
		if (board[0] == '-')
		{
			board[0] = y;
		}
		else if (board[2] == '-')
		{
			board[2] = y;
		}
	}
	else if (board[2] == y and (board[0] == '-' or board[1] == '-'))
	{
		if (board[0] == '-')
		{
			board[0] = y;
		}
		else if (board[1] == '-')
		{
			board[1] = y;
		}
	}
	else if (board[3] == y and (board[4] == '-' or board[5] == '-'))
	{
		if (board[5] == '-')
		{
			board[5] = y;
		}
		else if (board[4] == '-')
		{
			board[4] = y;
		}
	}
	else if (board[4] == y and (board[3] == '-' or board[5] == '-'))
	{
		if (board[3] == '-')
		{
			board[3] = y;
		}
		else if (board[5] == '-')
		{
			board[5] = y;
		}
	}
	else if (board[5] == y and (board[3] == '-' or board[4] == '-'))
	{
		if (board[3] == '-')
		{
			board[3] = y;
		}
		else if (board[4] == '-')
		{
			board[4] = y;
		}
	}
	else if (board[6] == y and (board[7] == '-' or board[8] == '-'))
	{
		if (board[8] == '-')
		{
			board[8] = y;
		}
		else if (board[7] == '-')
		{
			board[7] = y;
		}
	}
	else if (board[7] == y and (board[6] == '-' or board[8] == '-'))
	{
		if (board[6] == '-')
		{
			board[6] = y;
		}
		else if (board[8] == '-')
		{
			board[8] = y;
		}
	}
	else if (board[8] == y and (board[6] == '-' or board[7] == '-'))
	{
		if (board[6] == '-')
		{
			board[6] = y;
		}
		else if (board[7] == '-')
		{
			board[7] = y;
		}
	}
	else if (board[0] == y and (board[3] == '-' or board[6] == '-'))
	{
		if (board[6] == '-')
		{
			board[6] = y;
		}
		else if (board[3] == '-')
		{
			board[3] = y;
		}
	}
	else if (board[3] == y and (board[0] == '-' or board[6] == '-'))
	{
		if (board[0] == '-')
		{
			board[0] = y;
		}
		else if (board[6] == '-')
		{
			board[6] = y;
		}
	}
	else if (board[6] == y and (board[0] == '-' or board[3] == '-'))
	{
		if (board[0] == '-')
		{
			board[0] = y;
		}
		else if (board[3] == '-')
		{
			board[3] = y;
		}
	}
	else if (board[1] == y and (board[4] == '-' or board[7] == '-'))
	{
		if (board[4] == '-')
		{
			board[4] = y;
		}
		else if (board[7] == '-')
		{
			board[7] = y;
		}
	}
	else if (board[4] == y and (board[1] == '-' or board[7] == '-'))
	{
		if (board[1] == '-')
		{
			board[1] = y;
		}
		else if (board[7] == '-')
		{
			board[7] = y;
		}
	}
	else if (board[7] == y and (board[1] == '-' or board[4] == '-'))
	{
		if (board[1] == '-')
		{
			board[1] = y;
		}
		else if (board[4] == '-')
		{
			board[4] = y;
		}
	}
	else if (board[2] == y and (board[5] == '-' or board[8] == '-'))
	{
		if (board[8] == '-')
		{
			board[8] = y;
		}
		else if (board[5] == '-')
		{
			board[5] = y;
		}
	}
	else if (board[5] == y and (board[2] == '-' or board[8] == '-'))
	{
		if (board[2] == '-')
		{
			board[2] = y;
		}
		else if (board[8] == '-')
		{
			board[8] = y;
		}
	}
	else if (board[8] == y and (board[2] == '-' or board[5] == '-'))
	{
		if (board[2] == '-')
		{
			board[2] = y;
		}
		else if (board[5] == '-')
		{
			board[5] = y;
		}
	}
	else
	{
		priorityMove(y);
	}
}

void priorityMove(char y)
{
	if (board[4] == '-')
	{
		board[4] = y;
	}
	else if (board[0] == '-' or board[2] == '-' or board[6] == '-' or board[8] == '-')
	{
		char move = rand() % 9;
		while (board[move] != '-' and (move == 1 or move == 3 or move == 5 or move == 7 or move == 4))
		{
			move = rand() % 9;
		}
		board[move] = y;
	}
	else
	{
		randomMove(y);
	}
}

void randomMove(char y)
{
	char move = (rand() % 9);
	while (board[move] != '-')
	{
		move = (rand() % 9);
	}
	board[move] = y;
}

bool hasWon(char player)
{
	int wins[][3] =
	{
		{0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{2,4,6},
		{0,4,8}
	};

	for (int i = 0; i < 8; i++) {
		int count = 0;
		for (int j = 0; j < 3; j++) {
			if (board[wins[i][j]] == player) {
				count++;
			}
		}
		if (count == 3) {
			return true;
		}
	}
	return false;
}

void printGameResult()
{
	printField();

	int x = 0;
	if (hasWon('X'))
	{
		cout << endl << "Congratulations, player X! You have won!" << endl;
	}
	else if (hasWon('0'))
	{
		cout << endl << "Congratulations, player 0! You have won!" << endl;
	}
	else
	{
		cout << endl << "It's a draw!";
	}
	cout << endl << endl << "One more time? (1 - yes; any other digit - stop): ";
	cin >> x;

	if (x == 1)
	{
		clearBoard();
		getFirstMove();
	}
	else
	{
		exit(0);
	}
}

bool drawChecker(char arr[9])
{
	for (int i = 0; i < 9; i++)
	{
		if (arr[i] == '-')
		{
			return false;
		}
	}
	return true;
}

void clearBoard()
{
	for (int i = 0; i < 9; i++) {
		board[i] = '-';
	}
}
