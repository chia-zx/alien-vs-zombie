#include "h/other.h"
#include <iostream>
#include <vector>
using namespace std;

void command(char& storeArrow,char &nextObject, int (&attributesValue)[][3], vector < vector<char> >& boards)
{
	Game game;
	string kcommand;
	game.kcommand = kcommand;
    cout << "Command > "; cin >> kcommand;

    if (kcommand == "up" || kcommand == "down" || kcommand == "left" || kcommand == "right")
    {
		commandDirection(storeArrow, nextObject, kcommand, attributesValue, boards);
    }
    else if (kcommand == "arrow")
    {
		game.changeDirection(boards);
    }
    else if (kcommand == "help")
    {
        help();
    }
    else if (kcommand == "save")
    {
		save();
    }
    else if (kcommand == "load")
    {
		stillImplementing();
    }
    else if (kcommand == "quit")
    {
		cout << "You have quit the game." << endl;
		exit(0);
    }
    else
    {
		cout << "Invalid input! Refer to command list below." << endl;
		help();
    }
}
