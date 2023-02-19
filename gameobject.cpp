#include "h/other.h"
#include <iostream>
using namespace std;

void Game::calculateMove()
{
	numOfMove = (((rows * columns) / 10) + numOfZombie) * 10;
}

void Game::shuffle()
{
	char obj[] = {'^', 'v', '<', '>', 'h', 'p', ' ', 'r'};
	int num = sizeof(obj);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			int random = rand() % num;
			if (boards[i][j] != 'A' && !(isdigit(boards[i][j])))
			{
				boards[i][j] = obj[random];
			}
		}
	}
}

void Game::zombieRemain()
{
	numberRemain = numOfZombie;
	for (int i = 1; i < numOfZombie + 1; ++i) 	// start from 1 - Alien excluded
	{
		if (attributesValue[i][0] == 0)
		{
			-- numberRemain;
		}
	}
}

void Game::removeZombie(char zombieToRemove)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			if (boards[i][j] == zombieToRemove)
			{
				boards[i][j] = ' ';
				cout << "Zombie " << zombieToRemove << " has been defeated." << endl;
				break;
			}
		}
	}
}

void Game::attackReset()
{
	attributesValue[0][1] = 0;
}

void Game::trail()
{
    char obj[] = {'^', 'v', '<', '>', 'h', 'p', ' ', 'r'};
	int num = sizeof(obj);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
			int random = rand() % num;
            if (boards[i][j] == '.')
            {
                boards[i][j] = obj[random];
            }
        }
    }
}

void Game::zombieLocate()
{
    for (int i = 0; i < boards.size(); ++i)
    {
        for (int j = 0; j < boards[i].size(); ++ j)
        {
            if (boards[i][j] == turn)   // zombie turn
            {
                zombieY = i;
                zombieX = j;
            }
        }
    }
}

void Game::zombieAttack()
{
    alienLocate();
    zombieLocate();
    newScreen();

    int tempY, tempX;
    int diff, range, attack, life, newLife;
    tempY = abs(corY - zombieY);
    tempX = abs(corX - zombieX);
    diff = tempY + tempX;
    range = attributesValue[turn - '0'][2];     // zombie turn
    attack = attributesValue[turn - '0'][1];    
    life = attributesValue[0][0];
    if (range >= diff)
    {
        newLife = life - attack;
		if (newLife <= 0)
		{
			newLife = 0;
		}
        attributesValue[0][0] = newLife;
		cout << "Alien is in the attack range." << endl;
		cout << "Alien receives " << attack << " damages from Zombie " << turn  << "." << endl;
		
		gameEnd();
    }
	else
	{
		cout << "Alien is not in the attack range." << endl;
	}
}

void Game::alienAttack()
{
    int attack, life, newLife;

    attack = attributesValue[0][1]; 
	cout << "Zombie " << nextObject << " receives " << attack << " damages." << endl;

    life = attributesValue[nextObject - '0'][0];        // -'0 change char to int
	newLife = life - attack;
	if (newLife <= 0)
	{
		newLife = 0;
		attributesValue[nextObject - '0'][0] = newLife;
		removeZombie(nextObject);
		zombieRemain();
		victory();
	}
	else
	{
		attributesValue[nextObject - '0'][0] = newLife;
	}
}

void Game::zombieMove()
{
    char choice[] = {'^', 'v', '<', '>'};
    int total = sizeof(choice);

	int random = rand() % total;
    char move = choice[random];

    if (move == '^')
    {
        cout << "Zombie " << turn << " move up" << endl;
        up();
    }
    else if (move == 'v')
    {
        cout << "Zombie " << turn << " move down" << endl;
        down();
    }
    else if (move == '<')
    {
        cout << "Zombie " << turn << " move left" << endl;
        left();
    }
    else if (move == '>')
    {
        cout << "Zombie " << turn << " move right" << endl;
        right();
    }
}

void Game::checkZombie(int (&zombieCoordinate)[][3])
{
	for (int k = 0; k < numOfZombie; ++k)
	{
		for(int i = 0; i < boards.size(); ++i)
		{
			for (int j = 0; j < boards[i].size(); ++j)
			{
				if (boards[i][j] == (k + '1'))		// change k to char
				{
					zombieCoordinate[k][0] = i;		// 0 = y
					zombieCoordinate[k][1] = j;		// 1 = x  // 2 = diff with alien
				}
			}
		}
	}
}

int Game::nearest()
{
	alienLocate();

	int smallest, zombieCount;
	int zombieCoordinate[numOfZombie][3];
	checkZombie(zombieCoordinate);

	int tempY, tempX, diff;
	for (int i = 0; i < numOfZombie; ++i)
	{
		tempY = zombieCoordinate[i][0];
		tempX = zombieCoordinate[i][1];

		tempY = abs(corY - tempY);			// get positive value
		tempX = abs(corX - tempX);

		diff = tempY + tempX;
		zombieCoordinate[i][2] = diff;
	}

	smallest = zombieCoordinate[0][2];
	for (int i = 1; i < numOfZombie; ++i)
	{
		if (zombieCoordinate[i][2] < smallest)
		{
			smallest = zombieCoordinate[i][2];
		}
	}

	for (int i = 0; i < numOfZombie; ++i)
	{
		if (smallest == zombieCoordinate[i][2])
		{
			zombieCount = i + 1;
			break;
		}
	}

	return zombieCount;
}

void Game::pod()
{
	int lifeBefore, newLife;
	int zombieCount = nearest();

	lifeBefore = attributesValue[zombieCount][0];
	newLife = lifeBefore - 10;
	if (newLife <= 0)
	{
		newLife = 0;
		attributesValue[zombieCount][0] = newLife;
		removeZombie(zombieCount + '0');	 // change to char
		zombieRemain();
		victory();
	}
	else
	{
		attributesValue[zombieCount][0] = newLife;
	}
}

void Game::rock()
{
	char randomObj[] = {'^', 'v', '<', '>', 'h', 'p', ' '};
	int objNum = sizeof(randomObj);

	int randomNum = rand() % objNum;
	boards[newY][newX] = randomObj[randomNum];
}

void Game::addHealth()
{
	int currentHealth, newHealth;
	currentHealth = attributesValue[0][0];
	newHealth = currentHealth + 20;
	attributesValue[0][0] = newHealth;
}

void Game::addAttack()
{
	int currentAttack, newAttack;
	currentAttack = attributesValue[0][1];
	newAttack = currentAttack + 20;
	attributesValue[0][1] = newAttack;
}