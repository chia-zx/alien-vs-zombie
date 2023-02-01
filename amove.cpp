#include "h/other.h"
#include <iostream>
#include <vector>
using namespace std;

void checkAlien(int& y, int& x, vector < vector<char> >& boards)
{	
	for(int i = 0; i < boards.size(); ++i)
	{
		for (int j = 0; j < boards[i].size(); ++j)
		{
			if (boards[i][j] == 'A')
			{
				y = i;
				x = j;
				break;
			}
		}
	}
}

void addAttack(int (&attributesValue)[][3])
{
	int currentAttack, newAttack;
	currentAttack = attributesValue[0][1];
	newAttack = currentAttack + 20;
	attributesValue[0][1] = newAttack;
}

bool Game::hitBorder(int x, int y, vector < vector<char> >& boards)
{
	int nrow = boards.size();
	int ncolumn = boards[0].size();
	return (!((y > -1) && (y < nrow))) || (!((x > -1) && (x < ncolumn)));
}

char right(char &nextObject, int (&attributesValue)[][3], vector < vector<char> >& boards)
{
	Game game;

	int y, x;
	checkAlien(y, x, boards);
	int newX = x + 1;

	if (game.hitBorder(newX, y, boards))
	{
		nextObject = '\0';		// set to null
	}
	else
	{
		boards[y][x] = '.';
		nextObject = boards[y][newX];
		boards[y][newX] = 'A';
	}

	return nextObject;
}

char left(char &nextObject, int (&attributesValue)[][3], vector < vector<char> >& boards)
{
	Game game;

	int y, x;
	checkAlien(y, x, boards);
	int newX = x - 1;
	
	if (game.hitBorder(newX, y, boards))
	{
		nextObject = '\0';		// set to null
	}
	else
	{
		boards[y][x] = '.';
		nextObject = boards[y][newX];
		boards[y][newX] = 'A';
	}

	return nextObject;
}

char down(char &nextObject, int (&attributesValue)[][3], vector < vector<char> >& boards)
{
	Game game;

	int y, x;
	checkAlien(y, x, boards);
	int newY = y + 1;
	
	if (game.hitBorder(x, newY, boards))
	{
		nextObject = '\0';		// set to null
	}
	else
	{
		boards[y][x] = '.';
		nextObject = boards[newY][x];
		boards[newY][x] = 'A';
	}

	return nextObject;
}

char up(char &nextObject, int (&attributesValue)[][3], vector < vector<char> >& boards)
{
	Game game;

	int y, x;
	checkAlien(y, x, boards);
	int newY = y - 1;
	
	if (game.hitBorder(x, newY, boards))
	{
		nextObject = '\0';		// set to null
	}
	else
	{
		boards[y][x] = '.';
		nextObject = boards[newY][x];
		boards[newY][x] = 'A';
	}
	return nextObject;
}

void checkObject(char& storeArrow, char &nextObject, int (&attributesValue)[][3], vector < vector<char> >& boards)
{
	Game game;

	do 
	{
		if (nextObject == '^')
		{
			cout << "Alien finds an ^ arrow " << endl;
			cout << "Alien's attack is increased by 20 " << endl;
			addAttack(attributesValue);
			nextObject = up(nextObject, attributesValue, boards);
			if (nextObject == ' ' || nextObject == '.' || nextObject == 'h' || nextObject == 'p')
			{
				storeArrow = '^';
			}
		}
		else if (nextObject == 'v')
		{
			cout << "Alien finds an v arrow " << endl;
			cout << "Alien's attack is increased by 20 " << endl;
			addAttack(attributesValue);
			nextObject = down(nextObject, attributesValue, boards);
			if (nextObject == ' ' || nextObject == '.' || nextObject == 'h' || nextObject == 'p')
			{
				storeArrow = 'v';
			}
		}
		else if (nextObject == '<')
		{
			cout << "Alien finds an < arrow " << endl;
			cout << "Alien's attack is increased by 20 " << endl;
			addAttack(attributesValue);
			nextObject = left(nextObject, attributesValue, boards);
			if (nextObject == ' ' || nextObject == '.' || nextObject == 'h' || nextObject == 'p')
			{
				storeArrow = '<';
			}
		}
		else if (nextObject == '>')
		{
			cout << "Alien finds an > arrow " << endl;
			cout << "Alien's attack is increased by 20 " << endl;
			addAttack(attributesValue);
			nextObject = right(nextObject, attributesValue, boards);
			if (nextObject == ' ' || nextObject == '.' || nextObject == 'h' || nextObject == 'p' || nextObject == '\0')
			{
				storeArrow = '>';
			}
		}

		else if (nextObject == ' ' || nextObject == '.')
		{
            if (nextObject == ' ')
			{
				cout << "Alien finds an empty space" << endl;
			}
			else if (nextObject == '.')
			{
				cout << "Nothing here..." << endl;
			}

			if (storeArrow == '^')
			{
				nextObject = up(nextObject, attributesValue, boards);
			}
			else if (storeArrow == 'v')
			{
				nextObject = down(nextObject, attributesValue, boards);
			}
			else if (storeArrow == '<')
			{
				nextObject = left(nextObject, attributesValue, boards);
			}
			else if (storeArrow == '>')
			{
				nextObject = right(nextObject, attributesValue, boards);
			}
		}

		Pause();
		cout << endl;

        if (nextObject == 'r' || nextObject == 'h' || nextObject == 'p' || isdigit(nextObject))
        {
            cout << "Alien finds a new objects !" << endl;
            Pause();
            break;
        }

		if (nextObject == '\0')
		{
			cout << "Alien hits the border !" << endl;
			Pause();
            break;
		}
	}while (nextObject != '\0');
}

void commandDirection(char& storeArrow, char nextObject, string kcommand, int (&attributesValue)[][3], vector < vector<char> >& boards)
{
	if (kcommand == "up")
    {
		storeArrow = '^';
		nextObject = up(nextObject, attributesValue, boards);
    }
    else if (kcommand == "down")
    {
		storeArrow = 'v';
		nextObject = down(nextObject, attributesValue, boards);
    }
    else if (kcommand == "left")
    {
		storeArrow = '<';
		nextObject = left(nextObject, attributesValue, boards);
    }
    else if (kcommand == "right")
    {
		storeArrow = '>';
		nextObject = right(nextObject, attributesValue, boards);
    }
	
	checkObject(storeArrow, nextObject, attributesValue, boards);
}