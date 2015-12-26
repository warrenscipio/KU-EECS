#include "matrix.h"
#include <iostream>
#include <cmath>



matrix::matrix(){
	
}


matrix::matrix(int numOfMats, int rSend[], int cSend[], int aSend[][10][10]){
//two loops two assign rows and cols of each array within the matrix class
for(int i=0;i<10; i++)
r[i]=rSend[i];

for(int i=0;i<10; i++)
c[i]=cSend[i];
//sets all matrices read in by executive class to matrix class
for(int i=0;i<numOfMats; i++)
	for(int j=0;j<rSend[i]; j++)
		for(int k=0;k<cSend[i];k++)
		a[i][j][k]=aSend[i][j][k];

}







void matrix::transpose(int mat1) {
//create a new array to act as the transposed matrix
int t[10][10];
for(int j=0; j< c[mat1];j++)
		for (int k=0; k< r[mat1];k++)
			 t[j][k]=a[mat1][k][j];

// prints matrix
for(int j=0; j< c[mat1];j++){
	cout << "| ";
		for (int k=0; k< r[mat1];k++){
			 cout << t[j][k] << " ";
			if(k==(r[mat1]-1))
				cout << "|" << endl;
		
		}
}


}

void matrix::add(int mat1, int mat2) {
// prints two added matrices
for(int j=0; j< r[mat1];j++){

	cout << "| ";

		for (int k=0; k< c[mat1];k++){
			//adds each value of the array(matrix)
			cout << a[mat1][j][k]+a[mat2][j][k] << " " ;
			if(k==(c[mat1]-1))
				cout << "|" << endl;	
		}
}


}

void matrix::print (int i) {
	

// prints matrix
	for(int j=0; j< r[i];j++){

	cout << "| ";

		for (int k=0; k< c[i];k++){
			cout << a[i][j][k] << " " ;
			if(k==(c[i]-1))
				cout << "|" << endl;	
		}
	
	}
	


}



void matrix::subtract(int mat1, int mat2) {
// prints two subtracted matrices
for(int j=0; j< r[mat1];j++){

	cout << "| ";

		for (int k=0; k< c[mat1];k++){
			//subtracts each value of the array(matrix)
			cout << a[mat1][j][k]-a[mat2][j][k] << " " ;
			if(k==(c[mat1]-1))
				cout << "|" << endl;	
		}
}




}

void matrix::multiply(int mat1, int mat2) {
//creates new array to act as the product matrix
int m[10][10];
for(int i=0; i< r[mat1]; i++){
	for(int j=0; j< c[mat2];j++){
		//creates value to store added numbers from mat1 and mat2
		int value=0;
		for (int k=0; k< c[mat1];k++){
			 value += (a[mat1][i][k]*a[mat2][k][j]) ;
				
		}
//thorws numbers into the new product matrix
m[i][j]=value;

	}	
}


//prints product matrix
for(int j=0; j< r[mat1];j++){

	cout << "| ";

		for (int k=0; k< c[mat2];k++){
			cout << m[j][k] << " " ;
			if(k==(c[mat2]-1))
				cout << "|" << endl;	
		}
}


}


void matrix::multiplyS(int mat1, int s) {
// prints matrix
for(int j=0; j< r[mat1];j++){

	cout << "| ";

		for (int k=0; k< c[mat1];k++){
			//multiplys every number by scalar
			cout << a[mat1][j][k]*s << " " ;
			if(k==(c[mat1]-1))
				cout << "|" << endl;	
		}
}	

}











