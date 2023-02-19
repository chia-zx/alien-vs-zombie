#include "h/other.h"
#include <iostream>
using namespace std;

void Game::command()
{
  while (!pass && win == false && lose == false)
  {
    cout << "Command > "; cin >> kcommand;
    cout << endl;

    if (kcommand == "up" || kcommand == "down" || kcommand == "left" || kcommand == "right")
    {
      if (attributesValue[0][2] >= 1)
      {
        attributesValue[0][2] = attributesValue[0][2] - 1;
        cout << "Moving... Move -1." << endl;
        cout << endl;
        commandDirection();
      }
      else
      {
        cout << "You have not enough move to move " << kcommand << " !" << endl;
        lose = true;
        break;
      }
    }

    else if (kcommand == "arrow")
    {
      if (attributesValue[0][2] >= 1)
      {
        attributesValue[0][2] = attributesValue[0][2] - 1;
        cout << "Changing Arrow... Move -1." << endl;
        cout << endl;
        changeDirection();
      }
      else
      {
        cout << "You have not enough move to change arrow !" << endl;
        lose = true;
        break;
      }
    }

    else if (kcommand == "shuffle")
    {
      if (attributesValue[0][2] >= 5)
      {
        attributesValue[0][2] = attributesValue[0][2] - 5;
        cout << "Shuffling... Move -5." << endl;
        shuffle();
      }
      else
      {
        cout << "You have not enough move to shuffle the board !" << endl;
      }
      newScreen();
    }

    else if (kcommand == "freeze")
    {
      if (attributesValue[0][2] >= 5)
      {
        attributesValue[0][2] = attributesValue[0][2] - 5;
        freeze = true;
        cout << "Freezing... Move -5." << endl;
      }
      else
      {
        cout << "You have not enough move to freeze the zombie !" << endl;
      }
      newScreen();
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
      load();
    }
    else if (kcommand == "quit")
    {
      cout << "Are you sure you want to quit game ? (enter 'y' to quit) -> ";
      char confirm;
      cin >> confirm;
      if (confirm == 'y' || confirm == 'Y')
      {
        cout << endl;
        cout << "You have quit the game." << endl;
        exit(0);
      }
      newScreen();
    }
    else
    {
      cout << "Invalid input! Refer to command list below." << endl;
      help();
    }
  } 
}