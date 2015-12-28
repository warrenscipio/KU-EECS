/**
@file Executive.cpp
@author Zach Brachtenbach */
#include "Executive.h"
#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

Executive::Executive() {
	//used to read the first txt file
	ifstream input1("matrix1.txt");
	int r1 = 0;
	int c1 = 0;
	input1 >> r1;
	input1 >> c1;
	double m [r1][MAX_COLS];
	for (int i = 0; i < r1; i++) {
	for (int j = 0; j < c1; j++) {
	//assigns the input in the txt file to the matrix m
	input1 >> m[i][j];
	}
	for (int j = c1; j < MAX_COLS; j++) {
	m[i][j] = 0.0;
	}
	}
	//sets the first matrix A to contain the info from the first txt file
	A = Matrix(r1,c1,m);
	input1.close();
	
	//used to read the second txt file
	ifstream input2("matrix2.txt");
	int r2 = 0;
	int c2 = 0;
	input2 >> r2;
	input2 >> c2;
	double n [r2][MAX_COLS];
	for (int i = 0; i < r2; i++) {
	for (int j = 0; j < c2; j++) {
	//assigns the input in the txt file to the matrix n
	input2 >> n[i][j];
	}
	for (int j = c2; j < MAX_COLS; j++) {
	n[i][j] = 0.0;
	}
	}
	//sets the first matrix B to contain the info from the second txt 		file
	B = Matrix(r2,c2,n);
	input2.close();
	
	//these five lines add the methods so the methods can be executed 		with the two read matrices
	addMats();
	subtractMats();
	multipleMats();
	transpose();
	scalar();
	
}

void Executive::addMats() {
	Matrix H = A.add(B);
	cout << "The addition of the matrices " << endl;
	A.print(cout);
	cout << " and " << endl;
	B.print(cout);
	cout << " is " << endl;
	H.print(cout);
	cout << endl;
}

void Executive::subtractMats() {
	Matrix I = A.subtract(B);
	cout << "The subraction of the matrices " << endl;
	A.print(cout);
	cout << " and " << endl;
	B.print(cout);
	cout << " is " << endl;
	I.print(cout);
	cout << endl;
}

void Executive::multipleMats() {
	Matrix E = A.multiple(B);
	cout << "The multiplication of the matrices " << endl;
	A.print(cout);
	cout << " and " << endl;
	B.print(cout);
	cout  << " is " << endl;
	E.print(cout);
	cout << endl;
}

void Executive::transpose() {
	Matrix F = A.transpose();
	cout << "This matrix " << endl;
	A.print(cout);
	cout << " transposed is " << endl;
	F.print(cout);
	cout << endl;
}

void Executive::scalar() {
	Matrix G = A.scalar(5.0);
	cout << "This matrix " << endl;
	A.print(cout);
	cout << " with a scalar of 5 will become " << endl;
	G.print(cout);
	cout << endl;
}
