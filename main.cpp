// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT8L 
// Names: CHIA ZHI XUAN | CHIN WEI LING | SALLY KHOR ZHI XUAN
// IDs: 1211104495 | 1211104398 | 1211104401
// Emails: 1211104495@STUDENT.MMU.EDU.MY | 1211104398@STUDENT.MMU.EDU.MY | 1211104401@STUDENT.MMU.EDU.MY
// Phones: 0166625337 | 01110988674 | 01152223888
// ********************************************************* 

#include "h/other.h"
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
    // srand(1);
    srand(time(NULL));
	
	vector < vector<char> > boards;

    Game game;
	
	int numOfZombie = game.numOfZombie;
	
	game.changeSetting(numOfZombie);	
	game.objects(numOfZombie, boards);
	
	int attributesValue[numOfZombie + 1][3];		// life 0, attack 1, range 2
	setAttributes(numOfZombie, attributesValue);
	char nextObject, storeArrow;
	
    do 
	{
		game.displayBoard(boards);
		if (nextObject != '\0' && nextObject != 'r' && nextObject != 'h' && nextObject != 'p' && !isdigit(nextObject))
		{
			checkObject(storeArrow, nextObject, attributesValue, boards);
		}
		else
		{
			attributes(numOfZombie, attributesValue);
			command(storeArrow, nextObject, attributesValue, boards);
		}
	} while(game.kcommand != "quit");	
}