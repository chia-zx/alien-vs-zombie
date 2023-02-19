#include "h/other.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Game::setAttributes()
{
	int n = numOfZombie + 1;
	int sum;
	
	for (int i = 0; i < n; ++i)
	{
		int life = rand() % ((rows * columns) / numOfZombie) * 20; 		// more zombie, value will be lower
		int attack = rand() % ((rows * columns) / numOfZombie) * 10;
		int range = rand() % ((rows + columns) / 2);
		
		if (i == 0)
		{
			attack = 0;		// initial attack for alien
			
			attributesValue[i][0] = life;
			attributesValue[i][1] = attack;
			attributesValue[i][2] = numOfMove;
		}
		else if(attack < attributesValue[0][0] && range > 0 && attack > 0 && life > attack)
		{
			attributesValue[i][0] = life;
			attributesValue[i][1] = attack;
			attributesValue[i][2] = range;

			sum += attack;
		}
		else
		{
			--i;
			continue;
		}
	}

	if (attributesValue[0][0] <= sum)
	{
		attributesValue[0][0] = attributesValue[0][0] * 2;  	// alien' life will not be 0 at the first round
	}
}

void Game::attributes()
{
	int n = numOfZombie + 1;
	
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			if (turn == 'A')
			{
				cout << " ~> ";
			}
			else
			{
				cout << "    ";
			}
			cout << std::left << setw(9)  << "Alien" << " : " <<
				    						 " Life " << std::right << setw(5) << attributesValue[i][0] <<
				    						 ", Attack " << std::right << setw(4) << attributesValue[i][1] <<
				    						 ", Move " << std::right << setw(4) << attributesValue[i][2] << endl;
		}
		else
		{
			if (turn == i + '0')
			{
				cout << " ~> ";
			}
			else
			{
				cout << "    ";
			}
			cout << std::left << setw(8) << "Zombie " << i << " : " << 
				    						" Life " << std::right << setw(5) << attributesValue[i][0] << 
				    						", Attack " << std::right<< setw(4) << attributesValue[i][1] << 
				    						", Range " << std::right << setw(3) << attributesValue[i][2];
			if (freeze)
			{
				cout << "  " << " (freezed) ";
			}
			cout << endl;
		}
	}
	cout << endl;
}