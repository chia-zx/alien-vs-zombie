#include "h/other.h"
#include <iostream>
#include <iomanip>
using namespace std;


void help()
{
    cout << endl;
    cout << left << setw(9) << " // command // " << endl;
    cout << left << setw(9) << " up" << ":  Move up" << endl;
    cout << left << setw(9) << " down" << ":  Move down" << endl;
    cout << left << setw(9) << " left" << ":  Move left" << endl;
    cout << left << setw(9) << " right" << ":  Move right" << endl;
    cout << left << setw(9) << " arrow" << ":  Change direction of an arrow" << endl;
    cout << left << setw(9) << " help" << ":  Display command list" << endl;
    cout << left << setw(9) << " save" << ":  Save game" << " [still implementing] " << endl;
    cout << left << setw(9) << " load" << ":  Load previous game" << " [still implementing] " << endl;
    cout << left << setw(9) << " quit" << ":  Quit game" << endl;
	cout << endl;
	
	Pause();
}