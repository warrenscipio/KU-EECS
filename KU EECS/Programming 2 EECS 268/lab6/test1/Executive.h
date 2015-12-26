#ifndef _EXECUTIVE_
#define _EXECUTIVE_


#include <string>


using namespace std;
 
class Executive{


public:
	Executive();
	//take in char[] and read file
	Executive( char file[]);
	
	//add word to either stack or queue
	void addWord();

	//show what is on top of the stack and front of the queue
	void show();
	
	// finish the last thing put on the stack/finish the first thing put in the queue
	void done();
	
	//add word to queue
	void addToQueue(string w); 

	//maybe add to stack
	void addToStack(string w);


			
	
	
	
	
private:
	
	
	


};

#endif
