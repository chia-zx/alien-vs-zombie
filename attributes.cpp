#include "h/other.h"
#include <iostream>
#include <iomanip>
using namespace std;

void setAttributes(const int& numOfZombie, int (&attributesValue)[][3])
{
	int n = numOfZombie + 1;
	
	for (int i = 0; i < n; ++i)
	{
		int life = rand() % 31 * 50;
		int attack = rand() % 6 * 10;
		int range = rand() % 10;
		
		if (i == 0)
		{
			attack = 0;
			range = 0;
			
			attributesValue[i][0] = life;
			attributesValue[i][1] = attack;
			attributesValue[i][2] = range;
		}
		else if(attack < attributesValue[0][0] && range > 0 && attack > 0 && life > attack)
		{
			attributesValue[i][0] = life;
			attributesValue[i][1] = attack;
			attributesValue[i][2] = range;
		}
		else
		{
			--i;
			continue;
		}
	}
}

void attributes(const int& numOfZombie, const int attributesValue[][3])
{
	int n = numOfZombie + 1;
	
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			cout << left << setw(9) << "Alien" << " : " << " Life " << attributesValue[i][0] << ", Attack " << attributesValue[i][1] << endl;
		}
		else
		{
			cout << left << setw(8) << "Zombie " << i << " : " << 
									   " Life " << attributesValue[i][0] << 
									   ", Attack " << attributesValue[i][1] << 
									   ", Range " << attributesValue[i][2] << endl;
		}
	}
	cout << endl;
}