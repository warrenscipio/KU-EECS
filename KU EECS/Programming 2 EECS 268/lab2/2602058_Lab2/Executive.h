/**
@file Executive.h
@author Zach Brachtenbach */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#define MAX 10
#include "Matrix.h"
#include <iostream>
#include <cmath>
using namespace std;

class Executive {

public:
	/** Executive()
	@param Default constructor for the executive class
	@pre None
	@post Will read from two files and assign the dimensions and values 		of the matrix to two different Matrices
	@return None */
	Executive();
	/** void addMats()
	@param basic call of the add method
	@pre None
	@post Will be used to set the format of two matrices added together
	@return None */
	void addMats();
	/** void subtractMats()
	@param basic call of the subtract method
	@pre None
	@post Will be used to set the format of two matrices subtracted from 		each other
	@return None */
	void subtractMats();
	/** void multipleMats()
	@param basic call of the multiple method
	@pre None
	@post Will be used to set the format of two matrices multiplied 	together
	@return None */
	void multipleMats();
	/** void transpose()
	@param basic call of the transpose method
	@pre None
	@post Will be used to set the format of a matrice with converted 		dimensions
	@return None */
	void transpose();
	/** void scalar()
	@param basic call of the scalar method
	@pre None
	@post Will be used to set the format of a matrice scaled by a double
	@return None */
	void scalar();


private:
	Matrix A, B;

};

#endif
