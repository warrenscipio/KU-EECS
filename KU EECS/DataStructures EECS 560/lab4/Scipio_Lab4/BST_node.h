#ifndef _BST_NODE_H
#define _BST_NODE_H

class BST_node {
	private:
		BST_node* left_child;
		BST_node* right_child;
		int data;
		bool empty = true;
	public: 
		BST_node();
		~BST_node();
		BST_node(int x);
		bool is_empty();
		BST_node* get_left_child();
		BST_node* get_right_child();
		bool set_left_child(int x);
		bool set_right_child(int x);
		void set_left_child(BST_node* t);
		void set_right_child(BST_node* t);
		int get_data();
		void set_data(int x);
		int get_left_child_data();
		int get_right_child_data();

};

#endif
