/**
@file Executive.h
@author Warren Scipio */

#ifndef _Executive_
#define _Executive_

#include <string>
#include "GeneralTree.h"
#include <iostream>
#include <fstream>

using namespace std;
template <typename T>
class Executive{


public:
	//constructor
	Executive();
	Executive(istream& file );
	// tells users the correct commands to use
	void menu() ;
	
	
private:

	GeneralTree<T>* tree;
  	

};
#include "Executive.cpp"
#endif

