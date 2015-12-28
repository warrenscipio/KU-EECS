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

//only for the 1st Node
void firstNode(struct Node *head,int n){
  head->data =n;
  head->next = NULL;
}


// apending 
void addNode(struct Node *head, int n){
  
  
  if(head == NULL){
  head->data = n;
  head->next = NULL;
  }else{
  Node *newNode = new Node;
  newNode->data =n;
  newNode->next = NULL;
 
  Node *cur = head;
  while(cur) {
    if(cur->next == NULL) {
      cur->next = newNode;
      return;
    }
    cur = cur->next;
  }
  }
}

struct Node *searchNode(struct Node *head, int n){
  Node *cur = head;
  while(cur){
    if(cur->data == n) return cur;
    cur = cur->next;
  }
  cout << "No" << n << "found.\n";
}

bool deleteNode (struct Node **head, Node *ptrDel) {
  Node *cur = *head;
  if(ptrDel == *head) {
    *head = cur->next;
    delete ptrDel;
    return true;
  }

  while (cur){
    if(cur->next == ptrDel){
      cur->next = ptrDel->next;
      delete ptrDel;
      return true;
    }
    cur = cur->next;
  }
  return false;
}

void print(struct Node *head) {
  Node *list = head;
  while(list){
    cout << list->data <<" ";
    list = list->next;
  }
  cout<< endl;
  cout<< endl;

}

void hash(struct Node *head){
//didnt really need a whole method to create the hash, just kind of
//fit it into the building of the list to save memory so everything is done at
//the same time.

}


int start_open(int k){

  struct Node *newHead;
  struct Node *head = new Node;
  struct Node *ptrDelete;
  
  
  
 struct Node *ptr[k];
 
 
  for(int i=0; i < k; i++){
  	ptr[i]=new Node;
  	
  }


}
