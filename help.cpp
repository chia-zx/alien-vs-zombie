#include "h/other.h"
#include <iostream>
#include <iomanip>
using namespace std;


void Game::help()
{
    cout << endl;
    cout << std::left << setw(9) << " // command // " << endl;
    cout << std::left << setw(9) << " up" << ":  Move up" << endl;
    cout << std::left << setw(9) << " down" << ":  Move down" << endl;
    cout << std::left << setw(9) << " left" << ":  Move left" << endl;
    cout << std::left << setw(9) << " right" << ":  Move right" << endl;
    cout << std::left << setw(9) << " arrow" << ":  Change direction of an arrow" << endl;
    cout << std::left << setw(9) << " shuffle" << ":  Shuffle board" << endl;
    cout << std::left << setw(9) << " freeze" << ":  Freeze all Zombie" << endl;
    cout << std::left << setw(9) << " help" << ":  Display command list" << endl;
    cout << std::left << setw(9) << " save" << ":  Save game" << endl;
    cout << std::left << setw(9) << " load" << ":  Load previous game" << endl;
    cout << std::left << setw(9) << " quit" << ":  Quit game" << endl;
	cout << endl;
	
	newScreen();
}