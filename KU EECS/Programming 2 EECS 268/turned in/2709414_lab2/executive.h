#ifndef _EXECUTIVE_
#define _EXECUTIVE_
#
#include "matrix.h"
#include <string>


using namespace std;
 
class executive{
/** 
*set up executive file so that it reads similar to lab1 so 
*that it could read multiple matrices and multiple 
*operations at a single time. Should collect up to 10 matrices if the space is there I
*tryed 20 but I got a segmentation fault at the very end of my code every time.
*Should be able to do any number of operations to the matrices. 
*/

public:
	executive();
	executive(char s1[], char s2[]);
	
	int rows[10];
	int cols[10];
	int n;
	int matrices[10][10][10];		
	void print(int i) ;
	void transpose(int i) ;
	void add(int i, int j) ;
	void subtract(int i, int j) ;
	void multiply(int i, int j) ;
	void scalar(int i, int s);
	
	
	
private:
	
	
	


};

#endif
