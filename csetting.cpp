#include "h/other.h"
#include <iostream>
using namespace std;

int checkOdd(int x)
{
	return (x % 2 != 0);
}

void Game::changeSetting(int& numOfZombie)
{
	ClearScreen();
	
	char yn;
	int srow;
	int scolumn;
	int szombie;
	
	rows = 3;
	columns = 19;
	numOfZombie = 2;
	
	cout << "Default Game Setting" << endl;
	cout << "------------------------" << endl;
	cout << "Number of Rows = " << rows << endl;
	cout << "Number of Columns = " << columns << endl;
	cout << "Number of Zombie = " << numOfZombie << endl;
	cout << endl;
	
	cout << "Do you want to change the default setting (enter 'y' to change) ?  -> "; cin >> yn;
	if (yn == 'y' || yn == 'Y')
	{
		cout << endl;
		cout << "Board Settings" << endl;
		cout << "------------------" << endl;
		cout << "Enter rows -> "; cin >> srow;
		while (!checkOdd(srow) )
		{
			cout << "Invalid input! Please enter an odd number!" << endl;
			cout << "Enter rows -> "; cin >> srow;
		}
		rows = srow;
		
		cout << "Enter columns -> "; cin >> scolumn;
		while (!checkOdd(scolumn))
		{
			cout << "Invalid input! Please enter an odd number!" << endl;
			cout << "Enter columns -> "; cin >> scolumn;
		}
		columns = scolumn;

		cout << endl;
		cout << "Zombie Settings" << endl;
		cout << "------------------" << endl;
		cout << "Enter Zombie -> "; cin >> szombie;
		numOfZombie = szombie;
		
		Pause();
	}	
}