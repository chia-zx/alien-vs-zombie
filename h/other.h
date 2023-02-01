#ifndef OTHER_H
#define OTHER_H

#include <vector>
#include <string>

class Game 
{
public:
    int rows, columns, numOfZombie;
	std::string kcommand;
	char nextObject;
	
	void objects(const int& numOfZombie, std::vector< std::vector<char> >& boards);
    void displayBoard(std::vector< std::vector<char> >& boards);
    void changeDirection(std::vector< std::vector<char> >& boards);
	void changeSetting(int& numOfZombie);
	bool hitBorder(int x, int y, std::vector< std::vector<char> >& boards);

};

int ClearScreen();
int Pause();
void help();
void setAttributes(const int& numOfZombie, int (&attributesValue)[][3]);
void attributes(const int& numOfZombie, const int attributesValue[][3]);
int checkOdd(int x);
void command(char& storeArrow,char &nextObject, 
			 int (&attributesValue)[][3], std::vector< std::vector<char> >& boards);
void commandDirection(char& storeArrow, char nextObject, std::string kcommand, 
                      int (&attributesValue)[][3], std::vector< std::vector<char> >& boards);
void checkObject(char& storeArrow, char &nextObject, 
				 int (&attributesValue)[][3], std::vector< std::vector<char> >& boards);
void checkAlien(int& y, int& x, std::vector< std::vector<char> >& boards);
char up(char &nextObject, int (&attributesValue)[][3], std::vector< std::vector<char> >& boards);
char down(char &nextObject, int (&attributesValue)[][3], std::vector< std::vector<char> >& boards);
char left(char &nextObject, int (&attributesValue)[][3], std::vector< std::vector<char> >& boards);
char right(char &nextObject, int (&attributesValue)[][3], std::vector< std::vector<char> >& boards);
void addAttack(int (&attributesValue)[][3]);
void stillImplementing();


#endif