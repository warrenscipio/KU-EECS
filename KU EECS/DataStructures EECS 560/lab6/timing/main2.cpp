#include <iostream>
#include <cstdlib>
#include <sstream>
#include "BSTree.cpp"



using namespace std;

void insertNode(BSTree * root, int value);
bool searchTree(BSTree * root, int value);
void deleteNode(BSTree * root, int value);
BSTree * buildTree(long  n);
void inOrderTraversal(BSTree * root);
void menu();

void insertNode(BSTree * root, int value){
  
    if(value == root->getValue())
        return;

    if(value > root->getValue()){
        if(root->getRight() == NULL)
            root->setRight(new BSTree(value));
        else
            insertNode(root->getRight(), value); 
    }
    else {
        if(root->getLeft() == NULL)
            root->setLeft(new BSTree(value));
        else
            insertNode(root->getLeft(), value);
    }
}


bool searchTree(BSTree* root, int value){
  
    if(root == NULL)
        return false;
    
    if(value == root->getValue())
        return true;
    
    if(root->getLeft() == NULL && root->getRight() == NULL)
        return false;

    if(value > root->getValue())
        return searchTree(root->getRight(), value);
    else 
        return searchTree(root->getLeft(), value);
}


BSTree * buildTree(long  n){

  

    BSTree * root = NULL;
    
       
    root = new BSTree(n); 


    return root;
}


void inOrderTraversal(BSTree * root){
    if(root != NULL){
        inOrderTraversal(root->getLeft());
        cout << root->getValue()  << " " ;
        inOrderTraversal(root->getRight());
    }
}

void preOrderTraversal(BSTree * root){
    if(root != NULL){
        cout << root->getValue()  << " " ;
        preOrderTraversal(root->getLeft());
        preOrderTraversal(root->getRight());
    }
}

void postOrderTraversal(BSTree * root){
    if(root != NULL){
        postOrderTraversal(root->getLeft());
        postOrderTraversal(root->getRight());
        cout << root->getValue()  << " " ;
    }
}


void menu(){
    
    cout <<"----------------------------" << endl;
    cout << "Main Menu" << endl;
    cout << "1. Inorder traversal" << endl;
    cout << "2. Preorder traversal" << endl;
    cout << "3. Postorder traversal" << endl;
    cout << "4. Search item in tree" << endl;
    cout << "5. Insert item in tree" << endl;
    cout << "6. Quit" << endl;
    cout <<"----------------------------" << endl;
}

int dummy(){
 /*
    string line;
    int option;
    int item;
 
    cout << "Enter values for the BST: " << endl;
    getline(cin, line);
   
    // Creates the tree 
   

    
    // If root returns null that means the tree built was unsuccessful
   
    
   



	while(option!=6){
	
	menu();
	cin >> option;
	
		switch(option) {
	
			case 1:
				 cout << "Values inside the tree: " << endl;
           			 inOrderTraversal(root);
           			 cout << endl;
				
				break;
			case 2:
				cout << "Values inside the tree: " << endl;
           			 preOrderTraversal(root);
          			 cout << endl;
				break;
			case 3:
				cout << "Values inside the tree: " << endl;
           			 postOrderTraversal(root);
           			 cout << endl;
				
				break;
			case 4:
				
            			cout << "Enter value to search: ";
            			cin >> item;
            			
            			if(searchTree(root, item))
               			 	cout << item << " is inside the tree" << endl;
           			 else
               				 cout << item << " is not inside the tree" << endl;
            			
				break;
			case 5:
				
           			 cout << "Enter value to insert: ";
            			cin >> item;

            			insertNode(root, item);
				break;
			case 6:
				cout<< "good-bye" << endl;
				break;
			default:
				cout<< "not an option" <<endl;
				break;
		
	
	
		}
	}
	

    delete root;
    return 0;
    */
}
