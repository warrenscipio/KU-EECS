/**
@Filename Executive.h
@Author Warren Scipio
*/

#ifndef _EXECUTIVE_
#define _EXECUTIVE_

#include <string>


using namespace std;
 
class Executive{


public:

	Executive();
	Executive( char rowsIn[], char colsIn[], char ikrowIn[]);
	void printBoard(bool worked);
	int* array;
	int movesMade;
	int rows;
	int cols;
	int maxMoves;
	int initialKnightrow;
	int initialKnightcol;
	
			

	
	
	
private:
	//Board b;	
	
	


};

#endif