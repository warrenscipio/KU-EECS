
#include <iostream>
#include <fstream>
#include <iomanip>

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


void menu(struct Node *head){
 
  struct Node *ptrDelete;
 
	cout<<"1.Insert new item\n";
	cout<<"2.Delete an item\n";
	cout<<"3.Print all items\n";

  int val, numDel, ch;
  char option;
   
    
    

    cout<<"Enter your choice:";
    cin>>ch;
    switch(ch){

    case 1: cout<<"Value:";
            cin>>val;
            addNode(head, val);
            break;
    case 2: cout<<"Value:";
            cin>>numDel;
            
            ptrDelete = searchNode(head,numDel);
            if(deleteNode(&head,ptrDelete))
            cout<< numDel << " deleted" << endl;
            break;
    
    case 3: 
            print(head);
            break;
    
    default: cout<<"Invalid choice\n";
    }

  
  cout<<"continue? (y/n)" <<endl;
  cin >> option;

  if(option == 'y')
    menu(head);
  else
    cout << "program done" << endl;





}


int main(){

  struct Node *newHead;
  struct Node *head = new Node;
  struct Node *ptrDelete;

  int i;
  const char* inname = "test.txt";
  ifstream infile(inname);

  if(!infile){
    cout<< "messed up somewhere" << endl;
    return 0;
  }
 int numbers=0;  
  while (infile >> i){
    cout << "from file to list" << i << endl;
    if(numbers=0)
      firstNode(head,i);
    else
    addNode (head, i);

    numbers++;

  }

  menu(head);

cout << "have a good day" << endl;

}