#include "h/other.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void Game::load()
{
    ifstream displayFile;

    string openFile;
    cout << "Enter file name: ";
    getline(cin, openFile);
    openFile += ".txt";

    displayFile.open(openFile, ifstream::in);

    if (displayFile.good())
    {
        cout << (char)displayFile.get();
        displayFile.close();
    }

    else
    {
        cout << "No such file.";
    }
}

void Game::save()
{
    fstream saveFile;

    string filename;
    cout << "Enter file name: ";
    cin >> filename;
    filename += ".txt";

    saveFile.open(filename, ios::out | ios::trunc);

    saveFile << numOfZombie << "\n";
    saveFile << rows << "\n";
    saveFile << columns << "\n";

    for (int i = 0; i < boards.size(); ++i)
    {
        for (int j = 0; j < boards[i].size(); ++j)
        {
            saveFile << boards[i][j];
        }
        saveFile << "\n";
    }

    for (int i = 0; i < numOfZombie + 1; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            saveFile << attributesValue[i][j] << " | ";
        }
        saveFile << "\n";
    }

    saveFile.close();

    cout << "File has been created successfully." << endl;
    newScreen();
}
