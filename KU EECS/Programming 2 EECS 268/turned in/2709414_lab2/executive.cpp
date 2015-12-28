
#include "executive.h"
#include "matrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#define MAX_NUM_MATRICES 10
using namespace std;

executive::executive(){//1

}//1

executive::executive ( char s1[], char s2[] ) {//1
	std:: string line;
	std::string srow;
	std::string scol;
	int row=0;
	int col=0;
	int numOfMats =-1;

	
	ifstream inp(s1);


	
//get number of matrices
while (!inp.eof() ){
	getline(inp, line);
	numOfMats++;
	
}

	inp.close();

	ifstream inp2(s1);

	
	
	for(int i=0; i<numOfMats; i++){

		getline(inp2, srow, 'x');
		getline(inp2, scol, ' ');
		//string to ints
		row = atoi(srow.c_str());
		col = atoi(scol.c_str());
		//collects rows and cols of each matrix
		rows[i]=row;
		cols[i]=col;

		

		//place numbers in matrices
		for(int j=0; j<row; j++){

			for(int k=0; k<col;k++){

				 inp2 >> matrices[i][j][k]; 
}
 

		}
		
		
	}
	
	n = numOfMats;

cout << "POKEMON" <<endl;
	
	
	inp2.close();
//open new file to read instructions
	ifstream inputB(s2);
	string str;
while(inputB >> str){//3
	
	//if statements to read in strings to know what operation to perform
	if ( str =="print"){
	int num=0;
	inputB >> num;
	print(num);
	}else if(str == "multiply"){
	int num1=0;
	int num2=0;
	inputB >> num1;
	inputB >> num2;
	multiply(num1,num2);
	}else if (str == "transpose") {
	int num3=0;
	inputB >> num3;
	transpose(num3);
	}else if (str == "add") {
	int num4=0;
	int num5=0;
	inputB >> num4;
	inputB >> num5;
	add(num4,num5);
	}else if (str == "subtract") {
	int num6=0;
	int num7=0;
	inputB >> num6;
	inputB >> num7;
	subtract(num6,num7);
	}else if (str =="scalar"){
	int num8=0;
	int num9=0;
	inputB >> num8;
	inputB >> num9;
	scalar(num8,num9);
	}else{cout<<"sorry not a command"<< endl;
	}
}

inputB.close();
}
	





void executive::print(int i){
cout  <<"---------------------Print Matrix---------------------"<< endl;
	cout << endl;

// creats instant of matrix class
matrix matrixPrint(n, rows, cols, matrices);
//calls appropriate meathod
matrixPrint.print(i);
cout<<endl;



}



void executive::subtract(int i, int j){

cout  <<"------------------Subtract Matrices-------------------"<< endl;
	cout << endl;

//if statement to make sure matrices are the same size
  if(rows[i]==rows[j] && cols[i]==cols[j]){
	
	matrix matrixSub( n, rows, cols, matrices);	

	matrixSub.print(i);
	cout << "-"<< endl;
	matrixSub.print(j);
	cout << "=" << endl;
	
	matrixSub.subtract(i,j);

	
	
	}else{
	cout <<" Matrices can NOT be subtracted by one another (need to be same dimensions)" << endl;
	
	
	}
cout << endl;
}


void executive::add(int i, int j) {

cout  <<"----------------------Add Matrices--------------------"<< endl;
	cout << endl;

	//statement to make sure matrices are the same size
	if(rows[i]==rows[j] && cols[i]==cols[j]){
	
	matrix matrixAdd( n, rows, cols, matrices);	

	matrixAdd.print(i);
	cout << "+"<< endl;
	matrixAdd.print(j);
	cout << "=" << endl;
	
	matrixAdd.add(i,j);
	
	
	
	}else{
	cout <<" Matrices can NOT be added together (need to be same dimensions)" << endl;
	
	
	}
	cout << endl;
	

}

void executive::multiply(int i, int j) {

cout  <<"------------------Multiply Matrices-------------------"<< endl;
	cout << endl;

//statement to see if matrices meet the requirements to be multipled
if(cols[i]==rows[j]){
	matrix matrixMult(n, rows, cols, matrices);
	matrixMult.print(i);
	cout<<"X"<<endl;
	matrixMult.print(j);
	cout<<"="<<endl;
	matrixMult.multiply(i,j);
//if matrices are just entered in the wrong order
}else if(cols[j]==rows[i]){
cout << " can NOT be multipled in this order make sure to check that the columns of the first"<<endl;
cout << "matrix equals the rows of the second matrix (matrix multiplacation is not communitive)"<<endl;
}else{
cout << "matrices can NOT be multiplied" << endl;
}
cout<<endl;
}


void executive::scalar(int i, int s) {

cout  <<"------------------Multiply by scalar------------------"<< endl;
	cout << endl;

	matrix matrixS(n, rows, cols, matrices);
	matrixS.print(i);
	cout<<endl;
	cout << "multiplied by the scalar " << s << " equals" <<endl;
	cout<<endl;
	matrixS.multiplyS(i,s);

	cout<<endl;

	
  
  

}


void executive::transpose(int i){

cout  <<"------------------------Transpose---------------------"<< endl;
	cout << endl;



	matrix matrixTrans(n, rows, cols, matrices);
	matrixTrans.print(i);
	cout<<endl;
	cout<<" transposed equals " <<endl;
	cout<<endl;
	matrixTrans.transpose(i);
	cout<<endl;

	

}



