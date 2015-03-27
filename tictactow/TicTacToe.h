#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>  

class Coords
{
public:
	int get_x(){return x;}
	int get_y(){return y;}
	void set_x(int x){this-> x = x;}
	void set_y(int y){this-> y = y;}

	Coords();
	Coords(int x, int y);
private:
	int x, y;
};

Coords::Coords()
{
	x = y = 0;
}

Coords::Coords(int x, int y)
{
	this-> x = x;
	this-> y = y;
}


class GameBoard
{
public:
	bool valid_coords(int x, int y, bool player);
	char get_space(Coords c);
	int has_winner();
	
	void set_space(Coords c, char value);
	void print_self();
	void reset();
	void auto_fill();
	bool has_tie();


	GameBoard();

protected:
	char spaces[3][3];
};

char GameBoard::get_space(Coords c)
{
	return spaces[c.get_x()][c.get_y()];
}

void GameBoard::set_space(Coords c, char value)
{
	spaces[c.get_x()][c.get_y()] = value;
}

void GameBoard::print_self()
{
	std::cout << "   0   1   2" << std::endl << std::endl;
	for(int x = 0; x < 3; x++)
	{
		std::cout << x << "  ";
		for(int y = 0; y < 3; y++)
		{
			std::cout << spaces[x][y] << " | ";
		}
		std::cout << std::endl << "  -----------" << std::endl;
	}
}

bool GameBoard::valid_coords(int x, int y, bool player)
{
	return ((x >= 0 && x <= 2 && y >= 0 && y <= 2) && (spaces[x][y] == '*'));
}

int GameBoard::has_winner()
{
	for(int x = 0; x < 3 ; x++)
	{
		if(spaces[x][0] == spaces[x][1] && spaces[x][2] == spaces[x][0])
		{
			//Horizontal winner
			if(spaces[x][0] == 'X') return 1;
			if(spaces[x][0] == 'O') return 2;
		}
	}

	for(int y = 0; y < 3; y++)
	{
		if(spaces[0][y] == spaces[1][y] && spaces[2][y] == spaces[0][y])
		{
			//Verticle winner.
			if(spaces[0][y] == 'X') return 1;
			if(spaces[0][y] == 'O') return 2;
		}
	}

	//Diagonal winner.
	if(spaces[0][0] == spaces[1][1] && spaces[0][0] == spaces[2][2] ||
	   spaces[0][2] == spaces[1][1] && spaces[0][2] == spaces[2][0])
	{
		if(spaces[1][1] == 'X') return 1;
		if(spaces[1][1] == 'O') return 2;
	}

	//No winner.
	return 0;
}

bool GameBoard::has_tie()
{
	int filled_spaces = 0;
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if(spaces[x][y] != '*')
				filled_spaces++;
		}
	}

	return filled_spaces >= 9;
}

void GameBoard::reset()
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			spaces[x][y] = '*';
		}
	}
}

void GameBoard::auto_fill()
{
	//Find all free_spaces.
	std::vector<Coords> free_spaces;
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if(spaces[x][y] == '*')
				free_spaces.push_back(Coords(x, y));
		}
	}

	//Choose one randomly
	srand(time(NULL));
	int coord = rand() % free_spaces.size();
	int x = free_spaces[coord].get_x();
	int y = free_spaces[coord].get_y();
	//Fill it in.
	std::cout << "BOT: " << x << " " << y << std::endl;
	spaces[x][y] = 'O';
}

GameBoard::GameBoard()
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			spaces[x][y] = '*';
		}
	}
}
