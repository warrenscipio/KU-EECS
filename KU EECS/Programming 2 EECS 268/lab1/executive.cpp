
#include "executive.h"
#include "polynomial.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

executive::executive(){//1

}//1

executive::executive ( char s1[], char s2[] ) {//1
	int p=0;
	int k=0;
	ifstream inp(s1);
while (inp >> p) {//2
	double a[MAX_DEGREE + 1];
	for( int i=0; i <= p; i++)
	inp >> a[i];

	polynomial x(p,a);
	polys[k] = x;
	k++;
}//2
	inp.close();

	ifstream inputB(s2);
	string str;
while(inputB >> str){//3

	if ( str =="print"){//4
	int num1=0;
	inputB >> num1;
	print(num1);
	}//4
	
	else if (str == "evaluate") {//5
	int num2=0;
	double num3=0;
	inputB >> num2;
	inputB >> num3;
	evaluate(num2,num3);
	}//5
	else if (str == "add") {//6
	int num4=0;
	int num5=0;
	inputB >> num4;
	inputB >> num5;
	add(num4,num5);
	}//6
	else if (str == "differentiate") {//7
	int num6=0;
	inputB >> num6;
	differentiate(num6);
	}//7
}//3

inputB.close();
}//1
	


void executive::print(int i)const{
polys[i].print(cout);
cout << endl;

}

void executive::differentiate(int i) const{

  polynomial p = polys[i].differentiate();
  cout << endl;
  cout << "The first derivative of the polynomial";
  polys[i].print(cout);
  cout << " is ";
  p.print(cout);
  cout << "." << endl;

}


void executive::add(int i, int j) const{
  polynomial p2 = polys[i].add(polys[j]);
  cout << endl;
  cout << "The addition of the polynomials " ;
  polys[i].print(cout);
  cout << " and ";
  polys[j].print(cout);
  cout << " become ";
  p2.print(cout);
  cout << " . " << endl;
}




void executive::evaluate(int i, double x) const{

  double polySum = polys[i].evaluate(x);

  cout << endl;
  cout <<"The polynomial ";
  polys[i].print(cout);
  cout << " eveluated at " << x << " is " << polySum << "." <<endl;

}

