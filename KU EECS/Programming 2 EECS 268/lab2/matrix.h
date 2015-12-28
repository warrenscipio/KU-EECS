#ifndef _MATRIX_
#define _MATRIX_

#include <iostream>



using namespace std;

class matrix{


/**
*this matrix file is purely for doing the actual operations to
* the matrices sent from executive, and then printing them out.
*/

public:
	
	
	matrix();
	matrix(int numOfMat, int rSend[], int cSend[], int aSend[][10][10]);
	
	
	void transpose(int mat1) ;
	void multiplyS(int mat1, int s) ;
	void multiply(int mat1, int mat2) ;
	void print(int i) ;
	void add(int mat1, int mat2) ;
	void subtract(int mat1, int mat2) ;
	
private:
	//arrays to store the matrices sent from executive
	int r[10];
	int c[10];
 	int a[10][10][10];
	


};



#endif
