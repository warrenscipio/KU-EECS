/**
@file Matrix.cpp
@author Zach Brachtenbach */
#include "Matrix.h"
#include <iostream>
#include <cmath>
using namespace std;

Matrix::Matrix() {
	row = MAX_ROWS;
	col = MAX_COLS;

	for (int i = 0; i < MAX_ROWS; i++) {
	for (int j = 0; j < MAX_COLS; j++) {
	matrix[i][j] = 0.0;
	}
	}

}

Matrix::Matrix(int r, int c, double mat[][MAX_COLS]) {
	row = r;
	col = c;
	for (int i = 0; i < r; i++) {
	for (int j = 0; j < MAX_COLS; j++) {
	matrix[i][j] = mat[i][j];
	}
	}
}

Matrix Matrix::add(Matrix matrix1) const {
	Matrix A;
	if (row == matrix1.row && col == matrix1.col) {
	double m[row][MAX_COLS];
	for (int i = 0; i < row; i++) {
	for (int j = 0; j < col; j++) {
	m[i][j] = matrix[i][j] + matrix1.matrix[i][j];
	}
	for (int j = col; j < MAX_COLS; j++) {
	m[i][j] = 0.0;
	}
	}
	A = Matrix(row,col,m);
	}
	return A;
}

Matrix Matrix::subtract(Matrix matrix1) const {
	Matrix A;
	if (row == matrix1.row && col == matrix1.col) {
	double m[row][MAX_COLS];
	for (int i = 0; i < row; i++) {
	for (int j = 0; j < col; j++) {
	m[i][j] = matrix[i][j] - matrix1.matrix[i][j];
	}
	for (int j = col; j < MAX_COLS; j++) {
	m[i][j] = 0.0;
	}
	}
	A = Matrix(row,col,m);
	}
	return A;
}

Matrix Matrix::multiple(Matrix matrix1) const {
	Matrix A;
	if (row == matrix1.row) {
	double m[row][MAX_COLS];
	for (int i = 0; i < row; i++) {
	for (int j = 0; j < matrix1.col; j++) {
	double db;
	db = 0.0;
	for (int k = 0; k < col; k++) {
	db = db + (matrix[i][k] * matrix1.matrix[k][j]);
	}
	m[i][j] = db;
	}
	for (int j = matrix1.col; j < MAX_COLS; j++)
	m[i][j] = 0.0;
	}
	A = Matrix(row,matrix1.col, m);
	}
	return A;
}

Matrix Matrix::transpose() const {
	double m[col][MAX_COLS];
	for (int i = 0; i < col; i++) {
	for (int j = 0; j < row; j++) {
	m[i][j] = matrix[j][i];
	}
	}
	Matrix A(col,row, m);
	return A;
}

Matrix Matrix::scalar(double s) const {
	double m[row][MAX_COLS];
	for (int i = 0; i < row; i++) {
	for (int j = 0; j < col; j++)
	m[i][j] = matrix[i][j] * s;
	for (int j = col; j < MAX_COLS; j++)
	m[i][j] = 0.0;
	}
	Matrix A(row,col,m);
	return A;
}

void Matrix::print(ostream &os) const {
	for (int i = 0; i < row; i++) {
	os << "[";
	for (int j = 0; j < col; j++) {
	os << " " << matrix[i][j];
	}
	os << " ]" << endl;
	}
}
