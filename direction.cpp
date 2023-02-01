#include "h/other.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void Game::changeDirection(vector < vector<char> >& boards)
{
    int changeRow;
    int changeColumn;
	char currentArrow;
    char changeArrow;

    cout << "Enter row -> "; cin >> changeRow;
    cout << "Enter column -> "; cin >> changeColumn;
    cout << "Enter direction -> "; cin >> changeArrow;
    
    int y = changeRow - 1;
	int x = changeColumn - 1;
	currentArrow = boards[y][x];
	boards[y][x] = changeArrow;

    cout << "Arrow " << currentArrow << " is changed to " << changeArrow << endl;

    Pause();    // press any to continue
}