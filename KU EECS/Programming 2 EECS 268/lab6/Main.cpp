#include "Executive.h" //defines class
#include <string>
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
 
	if(argc<1)
		cout << "please run program with at least one file" << endl;	

	for(int i=1;i<argc;i++)	{
		Executive e(argv[i]);
		cout << "-----------------file " << i << " is complete-------------------" << endl;
	}
  
  return 0;
}
