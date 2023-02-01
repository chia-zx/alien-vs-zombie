#include "h/other.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void Game::objects(const int& numOfZombie, vector < vector<char> >& boards)
{
    char objects[] = {'^', 'v', '<', '>', 'h', 'p', 'r', ' ','Z'};
    int noOfObjects = sizeof(objects);

    boards.resize(rows);    // create empty row
    for (int i = 0; i < rows; ++i)
    {
        boards[i].resize(columns);   // resize each row
    }

    int centerRow = (rows + 1) / 2;
    int centerColumns = (columns + 1) / 2;

	int k = numOfZombie;
	char z = '1';
    // put random characters into vector array
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            int randomNum = rand() % noOfObjects;
            if ((i == centerRow - 1) && (j == centerColumns - 1))
            {
                boards[i][j] = 'A';
            }
            else if (randomNum == 8 && k == 0)
            {
                --j;
                continue;
            }
            else if (randomNum == 8 && k != 0)
            {
                boards[i][j] = z;
                --k; ++z;
            }
            else
            {
                boards[i][j] = objects[randomNum];
            }
        }
    }
}

void Game::displayBoard(vector < vector<char> >& boards)
{
    ClearScreen();

    // display first digit
	
    cout << endl << "   ";
    for (int n = 0; n < columns; ++n)
    {
        cout << " " << (n + 1) / 10; 
    }
    cout << endl;

    // second digit
    cout << "   ";
    for (int n = 0; n < columns; ++n)
    {
        cout << " " << (n + 1) % 10;
    }
    cout << endl;

    for (int i = 0; i < rows; ++i)
    {   
        cout << "   ";
        for (int j = 0; j < columns; ++j)   // upper border for each row
        {
            cout << "+-";
        }
        cout << "+" << endl;

        cout << left << setw(3) << i + 1;   // display row number

        for (int k = 0; k < columns; ++k)   // objects and border of each column
        {
            cout << "|" << boards[i][k];
        }
        cout << "|" << endl;
    }

    cout << "   ";
    for (int j = 0; j < columns; ++j)   // lowest row border 
    {
        cout << "+-";
    }
    cout << "+" << endl;

    cout << endl;
}