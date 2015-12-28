/**
@Filename Board.h
@Author Warren Scipio
*/

#ifndef _BOARD_
#define _BOARD_




using namespace std;
 
class Board{


public:
	Board();
	bool moveKnight(int initialKnightrow, int initialKnightcol, int rows, int cols, int* array, int movesMade, int maxMoves);
		
private:
	
};

#endif