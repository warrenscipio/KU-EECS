#ifndef _EXECUTIVE_
#define _EXECUTIVE_
#include "polynomial.h"
#include <string>
#define MAX_NUM_POLYNOMAILS 10
using namespace std;
 
class executive{


public:
	executive();
	executive(char s1[], char s2[]);	
	void print(int i) const;
	void differentiate(int i) const;
	void add(int i, int j) const;
	void evaluate(int i, double x) const;
	
private:
	
	polynomial polys[MAX_NUM_POLYNOMAILS];


};

#endif