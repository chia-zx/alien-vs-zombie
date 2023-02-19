#include "h/other.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool validArrow(char changeArrow)
{
    bool valid = false;
    char direction[] = {'^', 'v' , '<' , '>'};

    for (int i = 0; i < sizeof(direction); ++i)
    {
        if (direction[i] == changeArrow)
        {
            valid = true;
            break;
        }
    }
    return valid;
}

bool Game::isArrow(int changeRow, int changeColumn)
{
    bool arrow = false;
    char object = boards[changeRow - 1][changeColumn - 1];
    if (object == '^' || object == 'v' || object == '<' || object == '>')
    {
        arrow = true;
    }
    else
    {
        cout << "The row and column number entered is not matched to an arrow !" << endl;
    }
    return arrow;
}

bool Game::validColumn(int changeColumn)
{
    int x = changeColumn - 1;
	return ((x > -1) && (x < columns));
}

bool Game::validRow(int changeRow)
{
    int y = changeRow - 1;
	return ((y > -1) && (y < rows));
}

void Game::changeDirection()
{
    int changeRow, changeColumn;
	char currentArrow, changeArrow;

    while (true)
    {
        cout << "Enter row -> "; cin >> changeRow;
        while (!validRow(changeRow))
        {
            cout << "Invalid input! Please enter a valid row number!" << endl;
            cout << "Enter row -> "; cin >> changeRow;
        }
        cout << endl;

        cout << "Enter column -> "; cin >> changeColumn;
        while (!validColumn(changeColumn))
        {
            cout << "Invalid input! Please enter a valid column number!" << endl;
            cout << "Enter column -> "; cin >> changeColumn;
        }
        cout << endl;

        if (isArrow(changeRow, changeColumn))   // check whether the value is match to arrow
        {
            break;
        }
    } 

    cout << "Enter direction -> "; cin >> changeArrow;
	while (!validArrow(changeArrow))
    {
        cout << "Invalid input! Please enter a valid arrow !" << endl;
        cout << "Enter direction -> "; cin >> changeArrow;
    }
    cout << endl;
    
    int y = changeRow - 1;
	int x = changeColumn - 1;
	currentArrow = boards[y][x];
	boards[y][x] = changeArrow;

    cout << "Arrow " << currentArrow << " is changed to " << changeArrow << endl;

    newScreen();    // press any to continue
}
