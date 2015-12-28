#ifndef Two3tree_H_
#define Two3tree_H_
#include "Node.h"
#include <iostream>


//simple queue class
//------------------------------------------------------
template<typename T>
class Queue {

public:
	struct QNode {
		T data;
		QNode *next;
		QNode(T d, QNode *n) :data(d), next(n) {
		}
	};
	
	QNode *head;
	void add(T data, QNode*& n);
	bool searchQueue(T data, QNode* n);

	Queue();
	virtual ~Queue();
	void enqueue(T data);
	bool isEmpty();
	T dequeue();
	void print();
	bool find(T data);
};

template<typename T>
Queue<T>::Queue() {

	head = NULL;
}

template<typename T>
Queue<T>::~Queue() {
	QNode* iterator = head;
	while (iterator != NULL) {
		QNode* oldNode = iterator;
		iterator = iterator->next;
		delete oldNode;
	}
	head = NULL;
}

template<typename T>
void Queue<T>::add(T data, QNode*& n) {
	if (n == NULL) {
		n = new QNode(data, NULL);
	} else if (n->next == NULL) { // inserts if following queue node is empty
		n->next = new QNode(data, NULL);
	} else {
		add(data, n->next);
	}
}

template<typename T>
bool Queue<T>::searchQueue(T data, QNode* n) {
	if (n == NULL) {
		return false;
	} else if (n->data == data) {
		return true;
	}

	return searchQueue(data, n->next);
}

template<typename T>
void Queue<T>::enqueue(T data) {
	add(data, head);
}

template<typename T>
bool Queue<T>::isEmpty() {
	return head == NULL;
}

template<typename T>
T Queue<T>::dequeue() {
	if (isEmpty())
		return NULL;
	T returnPtr = head->data;
	QNode* delNode = head;
	head = head->next;
	delete delNode;
	return returnPtr;
}

template<typename T>
void Queue<T>::print() {
	QNode* iterator = head;
	while (iterator != NULL) {
		std::cout << iterator->data << " ";
		iterator = iterator->next;
	}
	delete iterator;
}

template<typename T>
bool Queue<T>::find(T data) {
	return searchQueue(data, head);
}




//------------------------------------------------------------------------
//tree structure
//------------------------------------------------------------------------
template<typename T>
class Two3tree {

public:
	Node<T>* head;
	void insert(T data, Node<T>*& node);
	void breakNode(Node<T>*& node, Node<T>*& leftChild,Node<T>*& rightChild);
	Node<T>* getMin(Node<T>*& node);
	Node<T>* getMax(Node<T>*& node);
	Node<T>* Build2Node(T data1, T data2, Node<T>* node);
	int getHeight(Node<T>* headNode, Node<T>* curNode, int height);
	Node<T>*& searchTree(Node<T>*& node, T data);
	


	Two3tree();
	virtual ~Two3tree();
	bool checkDublicate(T data);
	void levelOrder();//levelorder now
	
	//not happening
	//void delete();
	//void deletemin();
	//void deletemax();
};

template<typename T>
Two3tree<T>::Two3tree() :
		head(NULL) {
}

template<typename T>
Two3tree<T>::~Two3tree() {
	
}

template<typename T>
bool Two3tree<T>::checkDublicate(T data) {

	//check if data is already in the tree
	if (searchTree(head, data) == NULL){
		insert(data, head);
		return true;
	}
	
	return false;
}

//levelorder complete
//------------------------------------------------------------------------
template<typename T> 
void Two3tree<T>:: levelOrder(){


	std::cout << "Levelorder " <<std::endl;

	if (head == NULL){
		std::cout << "No stuff to print..." <<std::endl;
		return;
	}
	
	Queue<Node<T>*>* que = new Queue<Node<T>*>();
	Node<T>* curNode;
	int height = 0;
	
	curNode = head;
	que->enqueue(curNode);
	
	do{
	
		curNode = que->dequeue();
		int tempHeight = getHeight(head, curNode, 0); //height of curNode
		
		if (tempHeight != height) {
			std::cout << std::endl;
			height = tempHeight;
		}
		
		
		if(curNode->isLeaf())
			std::cout << curNode->key << " ";
		else
			std::cout << curNode->minSecond << " " << curNode->minThird << " ";
			
		//std::cout<< std::endl;
		
		if (curNode->first != NULL)
			que->enqueue(curNode->first);
			
		if (curNode->second != NULL)
			que->enqueue(curNode->second);
			
		if (curNode->third != NULL)
			que->enqueue(curNode->third);
			
		//else must be single node tree	
		
	}while(!que->isEmpty());
	
	
	
}
//I think this is working right
//------------------------------------------------------------------------
template<typename T>
void Two3tree<T>::insert(T data, Node<T>*& node) {
	//first node in the tree
	if (node == NULL)
		node = new Node<T>(data, NULL);
		
	//check if node doesnt have parent and its a leaf(only one value in tree)	
	else if (node->parent == NULL && node->isLeaf()) {
	
		//node->minSecond becomes which ever is greater
		if(node->key < data)
			node->minSecond = data;
		else
			node->minSecond = node->key;
		
		//smaller of the two becomes first
		if(node->key < data)
			node->first = new Node<T>(node->key, node);
		else
			node->first = new Node<T>(data, node);
		
		//larger of the two becomes second
		if(node->key > data)
			node->second = new Node<T>(node->key, node);
		else
			node->second = new Node<T>(data, node);
		
		
		//node becomes internal node
		node->key = -1;
		node->tag = 0;
		
		
	//if node is a leaf node, and has parent
	} else if (node->isLeaf()) {
		
		Node<T>* parent = node->parent;
		//check how many siblings
		if (node->parent->is2Node()) {
			//check where new node should be
			if (data >= parent->minSecond) {
				parent->minThird = data;
				parent->third = new Node<T>(data, parent);
				
			} else if (data < parent->minSecond) {
				parent->third = parent->second;
				parent->minThird = getMin(parent->third)->key;
				
				if (data >= node->key) {
					parent->second = new Node<T>(data, parent);
				} else {
					
					parent->second = parent->first;
					parent->first = new Node<T>(data, parent);
				}
				parent->minSecond = getMin(parent->second)->key;
			}
		//must be three interior node
		} else {
			Node<T>* rightChild;
			Node<T>* leftChild;
			//grandparent action
			Node<T>* parentParent = parent->parent;
			//build 2nodes for the children 
			if (data < parent->second->key) {
			
				leftChild = Build2Node(parent->first->key, data, parent);
				rightChild = Build2Node(parent->second->key,parent->third->key, parent);
			} else {
				leftChild = Build2Node(parent->first->key, parent->second->key,parent);
				rightChild = Build2Node(data, parent->third->key,parent);
			}
			//kill off non-needed parent
			delete parent;
			parent = NULL;
			// need to break apart node if possible, to many values
			breakNode(parentParent, leftChild, rightChild);
		}
		
	//recursively calling insert if not at leaf node for different cases
	} else if (data < node->minSecond) {
		node->first->parent = node;
		insert(data, node->first);
	} else if ((node->is2Node() && data >= node->minSecond) || (data >= node->minSecond && data < node->minThird)) {
		node->second->parent = node;
		insert(data, node->second);
	} else if (data >= node->minThird) {
		node->third->parent = node;
		insert(data, node->third);
	}
}

//tryed to fix tree up but I think this is where 
//my problem really is not the levelorder() 
//------------------------------------------------------------------------
template<typename T>
void Two3tree<T>::breakNode(Node<T>*& node, Node<T>*& leftChild,Node<T>*& rightChild) {

	//reached the head
	if (node == NULL) {
		// new head is changed to new node with no parent cause its the head duh
		head = new Node<T>(getMin(rightChild)->key, leftChild, rightChild,NULL);
		//set children to know who the boss is
		head->first->parent = head;
		head->second->parent = head;
		delete node;
	//node just needs to be set up as a 2node
	} else if (node->is2Node()) {
		if (node->minSecond > leftChild->minSecond) {
			if (node->first->minSecond == getMin(rightChild->first)->key || node->first->minSecond == getMin(leftChild->second)->key)
				node->third = node->second;
			else
				node->third = node->first;
			
			node->first = leftChild;
			node->first->parent = node;
			node->second = rightChild;
			node->second->parent = node;
			node->minThird = getMin(node->third)->key;
			node->minSecond = getMin(node->second)->key;
			
		} else {
		
			node->minThird = getMin(rightChild)->key;
			node->second = leftChild;
			node->second->parent = node;
			node->third = rightChild;
			node->third->parent = node;
		}
		
	//must create new children for node and then go back up tree
	} else {
		Node<T>* newLeftChild;
		Node<T>* newRightChild;
		Node<T>* tempNode = new Node<T>(node->minSecond,node->minThird,node->first,node->second,node->third,node->parent);
		
		//depending on case, set up new children accordingly 
		if (rightChild->minSecond < tempNode->second->minSecond) {
		
			newLeftChild = new Node<T>(getMin(rightChild)->key, leftChild,rightChild, tempNode->parent);
			leftChild->parent = newLeftChild;
			rightChild->parent = newLeftChild;
			
			newRightChild = new Node<T>(getMin(tempNode->third)->key,tempNode->second, tempNode->third, tempNode->parent);
			tempNode->second->parent = newRightChild;
			tempNode->third->parent = newRightChild;
			delete node;
			
		} else if (node->is2Node()|| rightChild->minSecond < node->third->minSecond) {
		
			newLeftChild = new Node<T>(getMin(leftChild)->key, tempNode->first,leftChild, node->parent);
			tempNode->first->parent = newLeftChild;
			leftChild->parent = newLeftChild;
			
			newRightChild = new Node<T>(getMin(node->third)->key, rightChild,tempNode->third, tempNode->parent);
			rightChild->parent = newRightChild;
			tempNode->third->parent = newRightChild;
			delete node;
			
		} else {
		
			newLeftChild = new Node<T>(getMin(tempNode->second)->key,node->first, node->second, node->parent);
			tempNode->first->parent = newLeftChild;
			tempNode->second->parent = newLeftChild;
			
			newRightChild = new Node<T>(getMin(rightChild)->key, leftChild,rightChild, tempNode->parent);
			leftChild->parent = newRightChild;
			rightChild->parent = newRightChild;
			delete node;
		}
		//recursive call to go up the tree correcting everything
		breakNode(tempNode->parent, newLeftChild, newRightChild);
	}

}
//find the min of a tree
template<typename T>
Node<T>* Two3tree<T>::getMin(Node<T>*& node) {
	if (node == NULL)
		return NULL;
	
	if(node->isLeaf())
		return node;
	else
		return getMin(node->first);
		
}
//find the max of a tree
template<typename T>
Node<T>* Two3tree<T>::getMax(Node<T>*& node) {
	if (node == NULL)
		return NULL;
		
	if(node->isLeaf()){
		return node;
	}else{
		if(node->is2Node())
			return getMax(node->second);
		else
			return getMax(node->third);
	
	}
		
}
//new 2node
template<typename T>
Node<T>* Two3tree<T>::Build2Node(T data1, T data2, Node<T>* node) {
	Node<T>* finalNode = NULL;
	//
	Node<T>* headPtr = new Node<T>(head->minSecond,head->minThird,head->first,head->second,head->third,NULL);
	Node<T>* leaf1 = new Node<T>(data1, finalNode);
	Node<T>* leaf2 = new Node<T>(data2, finalNode);
	if(headPtr->first != head->first) {
		head = headPtr;
	}
	if (data1 > data2) {
		finalNode = new Node<T>(data1, leaf2, leaf1, node);
	} else {
		finalNode = new Node<T>(data2, leaf1, leaf2, node);
	}
	finalNode->first->parent = finalNode;
	finalNode->second->parent = finalNode;
	return finalNode;
}

template<typename T>
int Two3tree<T>::getHeight(Node<T>* headNode, Node<T>* curNode, int height) {
	//height is 0 looking at the root
	if (headNode == curNode)
		return height;
	//recursively run through getHeight to adding incrementding height as it goes 
	else if (curNode == NULL && headNode->first != headNode) {
		++height;
		return getHeight(headNode->first, curNode, height);
	} else if (curNode != headNode && curNode != NULL) {
	
		if ((curNode->isLeaf() && curNode->key < headNode->minSecond) || (!curNode->isLeaf() && curNode->minSecond < headNode->minSecond)){
			++height;
			return getHeight(headNode->first, curNode, height);
		
		}else if (!headNode->is2Node() && ((curNode->isLeaf() && curNode->key >= headNode->minThird) || (!curNode->isLeaf() && curNode->minSecond >= headNode->minThird))){
			++height;
			return getHeight(headNode->third, curNode, height);
		}else{
			++height;
			return getHeight(headNode->second, curNode, height);
		}
	}
	return height;
}




//search the tree for existing data
template<typename T>
Node<T>*& Two3tree<T>::searchTree(Node<T>*& node, T data) {
	if (node == NULL){
		return node;
	}else if (node->isLeaf()){
		if( node->key == data)
			return node;
		else
			return node->first;
		
	}else if (data < node->minSecond) {
		node->first->parent = node;
		return searchTree(node->first, data);
	}
	else if (!node->is2Node() && data >= node->minThird) {
		node->third->parent = node;
		return searchTree(node->third, data);
	}
	else {
		node->second->parent = node;
		return searchTree(node->second, data);
	}
}




#endif
