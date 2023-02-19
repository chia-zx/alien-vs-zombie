#include "h/other.h"
#include <iostream>
using namespace std;

bool Game::hitBorder()
{
	return (!((newY > -1) && (newY < rows))) || (!((newX > -1) && (newX < columns)));
}

void Game::alienLocate()
{	
	for(int i = 0; i < boards.size(); ++i)
	{
		for (int j = 0; j < boards[i].size(); ++j)
		{
			if (boards[i][j] == 'A')
			{
				corY = i;
				corX = j;
				break;
			}
		}
	}
}

void Game::movingZombie()
{
	if (hitBorder())
	{
		nextObject = '!';		// set to !
		newScreen();
		cout << "Zombie " << turn << " hits the border !" << endl;
	}
	else
	{
		nextObject = boards[newY][newX];
		if (isdigit(nextObject))
		{
			newScreen();
			cout << "Zombie " << nextObject << " already there !" << endl;
		}
		else if (nextObject == 'A')
		{
			newScreen();
			cout << "Alien there !" << endl;
		}
		else	
		{
			boards[zombieY][zombieX] = ' ';
			boards[newY][newX] = turn;
		}
	}
	
	zombieAttack();
	newScreen();
	cout << "Zombie " << turn << "'s turn end." << endl;
	cout << endl; 
	Pause();
}

void Game::movingAlien()
{
	if (hitBorder())
	{
		nextObject = '!';		// set to !
	}
	else
	{
		nextObject = boards[newY][newX];
		if (nextObject == 'r')
		{
			rock();
		}
		else if (isdigit(nextObject))
		{
			alienAttack();
		}
		else
		{
			boards[corY][corX] = '.';
			boards[newY][newX] = 'A';
		}
	}
	
}

void Game::right()
{
	if (turn == 'A')
	{
		alienLocate();
		newY = corY;
		newX = corX + 1;
		movingAlien();
	}
	else
	{
		zombieLocate();
		newY = zombieY;
		newX = zombieX + 1;
		movingZombie();
	}
}

void Game::left()
{
	if (turn == 'A')
	{
		alienLocate();
		newY = corY;
		newX = corX - 1;
		movingAlien();
	}
	else
	{
		zombieLocate();
		newY = zombieY;
		newX = zombieX - 1;
		movingZombie();
	}
}

void Game::down()
{
	if (turn == 'A')
	{
		alienLocate();
		newY = corY + 1;
		newX = corX;
		movingAlien();
	}
	else
	{
		zombieLocate();
		newY = zombieY + 1;
		newX = zombieX;
		movingZombie();
	}
}

void Game::up()
{
	if (turn == 'A')
	{
		alienLocate();
		newY = corY - 1;
		newX = corX;
		movingAlien();
	}
	else
	{
		zombieLocate();
		newY = zombieY - 1;
		newX = zombieX;
		movingZombie();
	}
}

void Game::checkObject()
{
	do 
	{
		if (win || lose)
		{
			break;
		}
		
		if (nextObject == 'r' || nextObject == '!'  || isdigit(nextObject))
		{
			if (nextObject == 'r')
			{
				cout << "Alien hits the rock !" << endl;
				cout << "Hidden object under the rock !" << endl;
			}
			else if (nextObject == '!')
			{
				cout << "Alien hits the border !" << endl;
			}

			newScreen();
			cout << "Alien's turn end. Trail and attack reset." << endl;
			trail(); attackReset();
			pass = true;
			cout << endl; 
			Pause();
		}

		else if (nextObject == ' ' || nextObject == '.' || nextObject == 'h' || nextObject == 'p')
		{
            if (nextObject == ' ')
			{
				cout << "Alien finds an empty space" << endl;
			}
			else if (nextObject == '.')
			{
				cout << "Nothing here..." << endl;
			}
			else if (nextObject == 'h')
			{
				cout << "Alien finds a health pack !" << endl;
				cout << "Alien's health increase by 20." << endl;
				addHealth();
			}
			else if (nextObject == 'p')
			{
				cout << "Alien finds a pod !" << endl;
				cout << "Alien causes 10 damage to Zombie " << nearest() <<  endl;
				pod();
			}
			
			newScreen();

			if (storeArrow == '^')
			{
				up();
			}
			else if (storeArrow == 'v')
			{
				down();
			}
			else if (storeArrow == '<')
			{
				left();
			}
			else if (storeArrow == '>')
			{
				right();
			}
		}

		if (nextObject == '^' || nextObject == 'v' || nextObject == '<' || nextObject == '>')
		{
			cout << "Alien finds an " << nextObject << " arrow " << endl;
			cout << "Alien's attack is increased by 20 " << endl;
			addAttack();

			newScreen();

			if (nextObject == '^')
			{
				up();
				if (nextObject == ' ' || nextObject == '.' || nextObject == 'h' || nextObject == 'p')
				{
					storeArrow = '^';
				}
			}
			else if (nextObject == 'v')
			{
				down();
				if (nextObject == ' ' || nextObject == '.' || nextObject == 'h' || nextObject == 'p')
				{
					storeArrow = 'v';
				}
			}
			else if (nextObject == '<')
			{
				left();
				if (nextObject == ' ' || nextObject == '.' || nextObject == 'h' || nextObject == 'p')
				{
					storeArrow = '<';
				}
			}
			else if (nextObject == '>')
			{
				right();
				if (nextObject == ' ' || nextObject == '.' || nextObject == 'h' || nextObject == 'p' || nextObject == '!')
				{
					storeArrow = '>';
				}
			}
		}

	}while (!pass && win == false && lose == false);
}

void Game::commandDirection()
{
	if (kcommand == "up")
    {
		storeArrow = '^';	// use when 'h', 'p', ' ', '.'
		up();
    }
    else if (kcommand == "down")
    {
		storeArrow = 'v';
		down();
    }
    else if (kcommand == "left")
    {
		storeArrow = '<';
		left();
    }
    else if (kcommand == "right")
    {
		storeArrow = '>';
		right();
    }
	
	checkObject();
}
