/**
@Filename Board.cpp
@Author Warren Scipio
*/

#include "Board.h"



Board::Board(){
	
}
//recursive method to find the "Knight's Tour"
bool Board::moveKnight(int initialKnightrow, int initialKnightcol,  int rows, int cols, int array[], int movesMade, int maxMoves){
		
		// check if on board first
		if((initialKnightrow>=rows)||(initialKnightcol>=cols)||(initialKnightrow< 0)||(initialKnightcol<0)){
			// not on board
			return false;
			}
			

			//check if already passed over						
						if (array[initialKnightrow*rows+initialKnightcol]!=-1){
							//was not -1 go back
							return false;
							}
					//add to value to the array
					array[initialKnightrow*rows+initialKnightcol] = movesMade; 
					movesMade++;
					 
					 //if moves made ever reaches maxMoves we know we're done
					 if(movesMade >= maxMoves){
						return true;

					}
	
					bool inBoard = false;
					int x=1;				 
		//while loop to hold different moves
		while (!inBoard && x < 8){ 
			switch (x){
				// different moves calls the method recursivly checking each move
				case (1):
					inBoard =moveKnight( initialKnightrow-2, initialKnightcol-1, rows, cols, array, movesMade, maxMoves);
					break;
				case (2):
					inBoard =moveKnight( initialKnightrow-2, initialKnightcol+1, rows, cols, array, movesMade, maxMoves);
					break;
				case (3):
					inBoard =moveKnight( initialKnightrow-1, initialKnightcol-2, rows,  cols, array, movesMade, maxMoves);
					break;
				case (4):
					inBoard =moveKnight( initialKnightrow-1, initialKnightcol+2, rows,  cols, array, movesMade, maxMoves);
					break;
				case (5):
					inBoard =moveKnight( initialKnightrow+1, initialKnightcol-2, rows,  cols, array, movesMade, maxMoves);
					break;
				case (6):
					inBoard =moveKnight( initialKnightrow+1, initialKnightcol+2, rows,  cols, array, movesMade, maxMoves);
					break;
				case (7):
					inBoard =moveKnight( initialKnightrow+2, initialKnightcol-1, rows, cols, array, movesMade, maxMoves); 
					break;
				default:
					inBoard =moveKnight( initialKnightrow+2, initialKnightcol+1, rows, cols, array, movesMade, maxMoves);
					break;
					

			}
			//if a move returns false go to next move
			x++;
		}
			
						// if failed change number back to -1
						if (!inBoard && array[initialKnightrow*rows +initialKnightcol] > 0)
							array[initialKnightrow*rows +initialKnightcol] = -1;
		
				return inBoard;			

	
				}	