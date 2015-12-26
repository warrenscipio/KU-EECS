#ifndef _QUEUE_H
#define _QUEUE_H

#include "BST_node.h"

class Queue{
	private:
		BST_node** arr = new BST_node*[30];
		int size = 30;
		int count = 0;
	public:
		Queue();
		~Queue();
		void push(BST_node* n);
		BST_node* pop();
		BST_node* peek();
		bool is_empty();
};

#endif
