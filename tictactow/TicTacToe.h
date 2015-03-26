#include <iostream>

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
	void set_space(Coords c, char value);
	char get_space(Coords c);
	void print_self();
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
