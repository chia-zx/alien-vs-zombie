#include "h/other.h"
#include <iostream>
using namespace std;

int checkOdd(int x)
{
	return (x % 2 != 0);
}

void Game::changeSetting()
{
	ClearScreen();
	
	char yn;
	int srow, scolumn, szombie;
	
	rows = 5;
	columns = 17;
	numOfZombie = 3;
	
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
		
		cout << endl;
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
		while (szombie < 1 || szombie > 9)
		{
			cout << "Invalid input! Please enter number between 1 to 9!" << endl;
			cout << "Enter zombie number -> "; cin >> szombie;
		}
		numOfZombie = szombie;
		
		cout << endl;
		Pause();
	}	
}
