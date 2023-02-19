#ifndef OTHER_H
#define OTHER_H

#include <vector>
#include <string>

class Game 
{
	private:
		std::vector< std::vector<char> > boards;
		int rows, columns, numOfZombie, numOfMove;
		int corY, corX, newY, newX, zombieY, zombieX;
		int numberRemain;
		std::string kcommand;
		char nextObject, storeArrow, turn;
		bool pass = false;
		bool win = false;
		bool lose = false;
		bool replay = false;
		bool freeze = false;
		int attributesValue[][3];		// life 0, attack 1, range 2

	public:	
		void run();
		void result();
		void newScreen();
		void objects();
		void displayBoard();
		void changeDirection();
		bool validRow(int changeRow);
		bool validColumn(int changeColumn);
		bool isArrow(int changeRow, int changeColumn);
		void changeSetting();
		bool hitBorder();
		void checkObject();
		void commandDirection();
		void command();
		void setAttributes();
		void attributes();
		void up();
		void down();
		void left();
		void right();
		void movingAlien();
		void movingZombie();
		void addAttack();
		void addHealth();
		void rock();
		void pod();
		int nearest();
		void alienLocate();
		void checkZombie(int (&zombieCoordinate)[][3]);
		void zombieMove();
		void alienAttack();
		void zombieAttack();
		void zombieLocate();
		void trail();
		void attackReset();
		void removeZombie(char zombieToRemove);
		void zombieRemain();
		void victory();
		void gameEnd();
		void shuffle();
		void calculateMove();
		void help();
		void save();
		void load();
};

int ClearScreen();
int Pause();
int checkOdd(int x);


#endif
