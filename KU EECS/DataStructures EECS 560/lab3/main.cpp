#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>  
//I couldnt find out how to run this in gdb to find out when and how all the zeros get at the
//beginning of each of my linked lists
using namespace std;

struct Node {
  int data;
  Node* next;

};


int hash(int key, int hashSize, int i){
	int value;
	value = (key+(i*i))%hashSize;

return value; 
} 

bool contains(int array[], int size, int n){

  for (int i=0; i<size; i++){
    if(array[i] == n)
      return true;

  }
  return false;

}

int search(int array[], int size, int n){
  
  int i=0;

  while(contains(array, size, n) && i<1000 ){
    
    if(array[hash(n,size,i)] == n){
      return hash(n,size,i);
    }
    i +=1;

  }
  return -1;
}


bool isFull(int array[], int size){
	
	for(int i=0; i<size; i++){
		if (array[i]==-1)
			return false;
	}
		
	return true; 
}

// apending 
void insert(int array[],int size, int newNumber){
 int index; 
  index = search(array,size,-1);

  if(index !=-1){

    array[index] = newNumber;

  }else if(isFull(array,size)){

    cout << "hash is full"<< endl;

  }else{
    cout << "I guess couldnt find the open spot" <<endl;
  }
  
}


void remove(int array[],int size, int n) {
    int index; 
    index = search(array, size, n);
    
    if (index!=-1){
      array[index]=-1;
      cout << n << " was deleted" << endl;
      
    }else if(contains(array, size,n)){
      cout << " could not delete" <<endl;

    }else 
      cout << n << " is not in the array " << endl;

}

void print(int array[], int size ) {
  
  for(int i=0; i<size; i++){
  	cout<<i<<": "<< array[i] <<endl; 
  }
   
}
 


int main(){
  
  int hashSize;
  
  const char* inname = "data.txt";
  ifstream infile(inname);

  if(!infile){
    cout<< "messed up somewhere" << endl;
    return 0;
  }
 int numbers=0;  
 infile >> hashSize;
 
 int array[hashSize];
 
 
  for(int i=0; i < hashSize; i++){
  	array[i]=-1;
  	
  }

  int key;
  int index;
  int trys;
  while(infile >> key){
  	trys=0;
  	//index = hash(key,hashSize,trys);
  	insert(array,hashSize,key);
  		
  }
 
  print(array,hashSize);

  int val, numDel, ch; 
  char yes='y';

  while(yes=='y'){ 

	   cout<<"1.Insert new item\n";
	   cout<<"2.Delete an item\n";
	   cout<<"3.Print all items\n";
  	 cout<<"4.Exit program\n";
     cout<<"Enter your choice:";
     cin>>ch;

    switch(ch){

    case 1: cout<<"Value:";
            cin>>val;
          
            insert(array,hashSize, val);
            break;
    case 2: cout<<"Value:";
            cin>>numDel;
          
           remove(array,hashSize,numDel);
           if(contains(array, hashSize,numDel))  
              cout<< numDel << " deleted" << endl;
            
            break;
    
    case 3: 
            print(array,hashSize);
            break;

    case 4:
           cout<<"have a good day" <<endl;
           exit(0);
           break;
    
    default: cout<<"Invalid choice\n";
             exit(0);
    }
   
    
  }
 cout << "have a good day" << endl;

}
