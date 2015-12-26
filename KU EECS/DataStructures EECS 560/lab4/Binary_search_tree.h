
#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H
#include "Queue.h"
#include "BST_node.h"
#include <iostream>

class Binary_search_tree {

	private:
		BST_node* root;
		int num_nodes = 0;
		
		void insert_helper(int x, BST_node* t);
		void inorder_helper(BST_node* t);
		void preorder_helper(BST_node* t);
		BST_node* search_helper(int x, BST_node* t);
		void remove_helper(int x, BST_node* t, BST_node* p);
		BST_node* get_min(BST_node* t);
		BST_node* get_max(BST_node* t);
		void remover(BST_node* t, BST_node* p);

	public:
	
		void delete_min();
		void delete_max();
		void preorder();
		void inorder();
		void levelorder();
		Binary_search_tree();
		bool is_empty();
		void insert(int x);
		void remove(int x);
		BST_node* search(int x);
		
		
};

#endif
