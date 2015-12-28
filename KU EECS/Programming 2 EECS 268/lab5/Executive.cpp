/**
@Filename Executive.cpp
@Author Warren Scipio
*/

#include "Executive.h"
#include "Board.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#define MAX_NUM_MATRICES 10
using namespace std;

Executive::Executive(){//1

}//1

Executive::Executive ( char size[], char colsIn[], char ikrowIn[]) {//1
	
	int movesMade=0;
		
	rows = atoi(size);
	
	initialKnightrow = atoi(ikrowIn);
	initialKnightcol = atoi(ikcolIn);
	
	maxMoves = rows*cols;
	// creating a single array to hold all values of the board
	array = new int[maxMoves];
	//setting everything in array to -1
	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++){			
			array[(i*rows)+ j]=-1;
		}
	
	

	Board b;
	//calls print method to print out the board, b is an instance of the class board to call the method doing the moving 
	printBoard( b.moveKnight(initialKnightrow, initialKnightcol, rows, cols, array, movesMade, maxMoves));
	

	}

//print method
void Executive::printBoard(bool worked){
	//if initial position is not in board
	if (initialKnightrow>=rows || initialKnightcol>=cols)
		cout << "initial position is not on the board" << endl;
//if a right answer was found, print out complete array
if (worked){
	cout << "Success!" << endl;
	for(int i=0; i< rows;i++){
	
		cout << "";

		for (int j=0; j< cols;j++){
			if (array[i*rows+j]<10)
				cout << "[ " << array[i*rows+j] <<"]";
			else	
				cout << "[" << array[i*rows+j] << "]" ;
			
			if(j==(cols-1)){
				cout << "" << endl;
			}	
		}
	
	}
	//if it failed print out only where the initial position was
}else{ 
	cout << "Failed!" <<endl;
		for(int i=0; i< rows;i++){
	
		cout << "";

		for (int j=0; j< cols;j++){
			if (i==initialKnightrow && j==initialKnightcol)
				cout << "[ 0]" ;
			else
				cout << "[  ]" ;
			
			if(j==(cols-1)){
				cout << "" << endl;
			}	
		}
	
	}
	/*extra work i decided to put this in if the user is 
	looking for another position only if their first choice failed
	I realized doing this I can not delete the array unless the user doesnt say yes
	*/
	string answer;
	cout << "Would you like to check the current sized board for another initial point? (yes/no)" << endl;
	cin >> answer;
	if (answer=="yes"|| answer=="Yes"|| answer=="yEs"|| answer=="yeS"|| answer=="YeS"|| answer=="YES"|| answer=="YEs"|| answer=="yES" ){
		Board b;
			cout << "Choose new starting position." << endl;
			cin >> initialKnightrow;
			cin >> initialKnightcol;
		printBoard( b.moveKnight(initialKnightrow, initialKnightcol, rows, cols, array, movesMade, maxMoves));
		
	}else{
		delete [] array;
		cout<< "Have good day!" << endl;
		
	}
 }

}	