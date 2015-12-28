#include "polynomial.h"
#include <iostream>
#include <cmath>
#define MAX_DEGREE 20


polynomial::polynomial(){
degree = MAX_DEGREE;



}
/**
@pre constructed for the class 
@post set initial variables that are needed in certain conditions
@return */


polynomial::polynomial(int d, double a[]){
polys[MAX_DEGREE+1];
degree = d;
if ( degree > MAX_DEGREE){
 degree = MAX_DEGREE;
}

for(int i=0; i < degree+1; i++){
polys[i] = a[i];
}

}
/** 
@pre 
@post set initial variables that are needed
@return */
// method to evaluate the polynomial
double polynomial::evaluate(double x) const{
double anwser =0;
	for(int i=0; i<=degree; i++)
	anwser += pow(x,i)*polys[i];
	return anwser;


}
/**
@param polynomial is the type going in
@pre 
@post takes polynomial and uses the degree variable and the array from that polynomial
and adds and then sets them to a new polynomial polyAdd
@return */
// method to add up polynomails
polynomial polynomial::add(polynomial p2) const{
  int d;
  double a[MAX_DEGREE+1];
//if statement to keep degree at or below MAX_DEGREE
  if(degree > p2.degree){
  d=degree;
  }else{
  d=p2.degree;
  }

// to add coefs to a[]
 for(int i=0; i<=d ;i++){
  a[i] = polys[i] + p2.polys[i];
}
//set int and array to polynomial class
polynomial polyAdd(d,a);

return polyAdd;


}
/**
@param ostream
@pre up to this point we have at least read and set polys[] 
@post prints out correct form of polynomial
@return */
void polynomial::print (ostream &os) const{
	std::cout << std::endl;
	os << polys[0];

	if(degree >0)
	os << " + " << polys[1] << "x";

	for (int i=2; i<= degree; i++)
	os << " + " << polys[i] << "x^" << i;


}

/**
@pre set polys[]
@post mimics taking the derivitive of polynomial and returns derivitive
@return */

polynomial polynomial::differentiate() const{

int d;
double a[MAX_DEGREE+1];

for(int i=0; i<=degree; i++){

a[i] = polys[i+1]*(i+1);
}
d=degree-1;

polynomial polyDif(d,a);
return polyDif;

}











