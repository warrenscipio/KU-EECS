#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
//#include <main.cpp>
#include "main2.cpp"
#include "Two3tree.h"
using namespace std;

class Timer {
private:

	timeval startTime;
        timeval endTime;

public:

	void start(){
		gettimeofday(&startTime, NULL);
	}

	double stop(){
	        long seconds, nseconds;
		double duration;

		gettimeofday(&endTime, NULL);

		seconds  = endTime.tv_sec  - startTime.tv_sec;
		nseconds = endTime.tv_usec - startTime.tv_usec;

		duration = seconds + nseconds/1000000.0;

		return duration;
	}

	void printTime(double duration){
		printf("%5.6f seconds\n", duration);
	}
	
	
};

int main(int argc, char* argv[]) {
    
    Timer timer;
    int size;
    long n[4] = {50000, 100000, 200000, 400000};
    long numbers;
    
    for(int i = 0; i < 4; i++) {
   	double averageBST;
   	double average23;
	    for(int j =1; j <= 5; j++){
	   	 Timer t;
	    	srand(j);
	   
	   	//cout << "2-3 BST insert for n: " << i << " and seed: " << j <<" time: ";
	    	numbers = n[i];
	    	Two3tree<long>* tree = new Two3tree<long>();
	    
	    	t.start();
	    	
	    	for (int k = 0; k < n[i]; k++) {
	    	
			long x = rand() % n[0];
			if(tree->checkDublicate(x));
		
		}
		average23 += t.stop();
		//t.printTime(t.stop());
		delete tree;
		//cout<<endl;
		
		
		//--------------------------------------------------------------
		//--------------------------------------------------------------
		
	    
	   	//cout << "BST insert for n: " << i << " and seed: " << j <<" time: ";
	    	numbers = n[i];
	
	    	t.start();
	    	int count=0;
	    	BSTree * root = buildTree(rand() % n[i]);
	    	for (int k = 0; k < n[i]; k++) {
	    	
			long x = rand() % n[i];
			++count;
			insertNode(root, x);
		
		}
		averageBST += t.stop();
		//t.printTime(t.stop());
		
		//cout<<count;
		delete root;
		//cout<<endl;
		
	     
    
    }
    
    cout<< "average for BST at" << n[i] << ": " << averageBST/5<<endl;
    cout<< "average for 2-3 at" << n[i] << ": " << average23/5<<endl;
    
    
    
}

}


