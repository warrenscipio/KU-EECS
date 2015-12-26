#ifndef _EXECUTIVE_
#define _EXECUTIVE_

#include "Queue.h"
#include "Stack.h"
#include <string>
/*
*What you should do for this lab is for the VIPs aka the Stack one should implement this using 
*arrays simply beacuse its easiest to do and probably quickest and we are given the max number of *VIPs that could enter. However for the Queue since we are not given the amount of non-VIPs that
*will enter we should use linked list with nodes here, using this allows us to create a list with
*out needing to know how many people are coming.
*/

using namespace std;
 
class Executive{


public:
	Executive();
	//take in char[] and read file
	Executive( char file[]);
	
	//add word to either stack or queue
	void addWord(string word);

	//show what is on top of the stack and front of the queue
	// must be something to show
	void show();
	
	// must be something in queue or stack
	// finish the last thing put on the stack/finish the first thing put in the queue
	void done();
	
	//add word to queue
	void addToQueue(string w); 
	
	// stack must not be full
	//maybe add to stack
	void addToStack(string w);
	//prints out the statements for done()
	void printDone(string name, string name2, int n);
	//prints out statements for show()
	void printShow(string name, string name2);


			
	
	
	
	
private:
	Stack<string> vips;
	Queue<string> people;
	
	


};

#endif
/*
*HOWEVER as you can see I did not use linked list using nodes instead I used an array. Why? because 
*one it seemed easier at the time, and two the way that my program can read multiple files at a time 
*allows I just thought using nodes would mess something up...
*/
