/**
@file Matrix.h
@author Zach Brachtenbach */
#ifndef MATRIX_H
#define MATRIX_H
#define MAX_ROWS 100
#define MAX_COLS 100
#include <cmath>
#include <iostream>
using namespace std;

class Matrix {

public:
	/** Matrix()
	@param Default constructor for the matrix class
	@pre None
	@post Will set all values in the matrix to zero
	@return None */
	Matrix();
	/** Matrix(int r, int c, double mat[][MAX_COLS])
	@param Basic constructor for the matrix class
	@param contains two ints and a double array
	@pre None
	@post Will set all values in the matrix to the ones read from a txt 		file
	@return None */
	Matrix(int r, int c, double mat[][MAX_COLS]);
	/** Matrix add(Matrix matrix1) const
	@param Method that will add matrices
	@param contains one matrix
	@pre None
	@post Will add two matrices together to create a new matrix
	@return Will return the new matrix */
	Matrix add(Matrix matrix1) const;
	/** Matrix subtract(Matrix matrix1) const
	@param Method that will subtract matrices
	@param contains one matrix
	@pre None
	@post Will subtract two matrices together to create a new matrix
	@return Will return the new matrix */
	Matrix subtract(Matrix matrix1) const;
	/** Matrix multiple(Matrix matrix1) const
	@param Method that will multiply matrices
	@param contains one matrix
	@pre None
	@post Will multiply two matrices together to create a new matrix
	@return Will return the new matrix */
	Matrix multiple(Matrix matrix1) const;
	/** Matrix transpose() const
	@param Method that will change the dimensions of a matrix
	@pre None
	@post Will switch the two dimensions of a matrix
	@return Will return the new matrix */
	Matrix transpose() const;
	/** Matrix scalar(double s) const
	@param Method that will take a matrix and multiply it by a double
	@param contains a double
	@pre None
	@post Will multiply a double by any given matrix to create a matrix 		scaled by that double
	@return Will return the new matrix */
	Matrix scalar(double s) const;
	/** void print(ostream &os) const
	@param Method that will print any given matrix
	@param contains ostream
	@pre None
	@post Will print out a matrix
	@return None */
	void print(ostream &os) const;


private:
	int row;
	int col;
	double matrix[MAX_ROWS][MAX_COLS];

};

#endif
