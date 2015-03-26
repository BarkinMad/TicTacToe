#include "TicTacToe.h"
using namespace std;

void invalid_input()
{
	cout << "Invalid input. Coordinates must be 2 single space-seperated values between 0-2 inclusive and be an empty space." << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
	GameBoard board = GameBoard();
	bool turn = true;

	int p1x = 0, p1y = 0;
	int p2x = 0, p2y = 0; 

	while(1)
	{
		board.print_self();
		if(turn)
		{
			//Player 1 Turn.
			cout << "Player 1: ";
			if(cin >> p1x >> p1y && board.valid_coords(p1x, p1y, turn))
			{
				board.set_space(Coords(p1x, p1y), 'X');
				turn = !turn;
			}else
			{
				invalid_input();
			}
		}else
		{
			//Player 2 Turn.
			cout << "Player 2: ";
			if(cin >> p2x >> p2y && board.valid_coords(p2x, p2y, turn))
			{
				board.set_space(Coords(p2x, p2y), 'O');
				turn = !turn;
			}else
			{
				invalid_input();
			}
		}
	}

	return 0; 
}