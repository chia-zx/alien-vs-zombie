#include "h/other.h"
#include <iostream>
using namespace std;

void Game::newScreen()
{
	cout << endl;
	Pause();
	displayBoard();
	attributes();
}

void Game::result()
{
    if (win || lose)
    {
        if (win)
        {
            cout << "Alien win !" << endl;
        }
        if (lose)
        {
            displayBoard();
            attributes();
            if (attributesValue[0][2] == 0)
            {
                cout << "ALien have no more move !" << endl;
            }
            cout << "Alien lose !  Game over !" << endl;
        }

        cout << endl;
        cout << "Do you want to replay ? (enter 'y' to replay) -> ";
        char ans;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            replay = true;
        }
        else
        {
        	exit(0);
        }
    }
}

void Game::gameEnd()
{
	if (attributesValue[0][0] == 0 || attributesValue[0][2] == 0)
	{
		lose = true;
	}
}

void Game::victory()
{
	if (numberRemain == 0)
	{
		win = true;
	}
}

void Game::run()
{
	do
	{
		changeSetting();	
		objects();
		calculateMove();
		setAttributes();
		replay = false;			// not always replay
		win = false;
		lose = false;

		do 
		{
			for (int i = 0; i < numOfZombie + 1; ++i)
			{
				if (freeze)
				{
					displayBoard();
					attributes();
					i = 0;
					cout << "All Zombie has been freezed for one round." << endl;
					cout << "Alien's turn now." << endl;
					cout << endl;
					Pause();
					freeze = false;
				}

				if (lose || win)	// stop when alien win or loss
				{
					break;
				}

				else
				{
					if (i == 0)
					{
						turn = 'A';
						displayBoard();
						attributes();
						command();
						pass = false;
					}
					else
					{
						if (attributesValue[i][0] == 0)		// pass for the defeated zombie
						{
							continue;
						}
						else
						{
							turn = i + '0';
							displayBoard();
							attributes();
							zombieMove();
							gameEnd();
						}
					}
				}
			}
		} while(!win && !lose);	

        result();
	} while (replay);
}