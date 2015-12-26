#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_
#include <iostream>
#include <cmath>
#define MAX_DEGREE 20


using namespace std;

class polynomial{




public:
	int degree;
	double polys[MAX_DEGREE +1];
	polynomial();
	polynomial(int d, double a[]);
	double evaluate(double x) const;
	void print(ostream &os) const;
	polynomial add(polynomial p2) const;
	polynomial differentiate() const;
	
private:
	


};



#endif