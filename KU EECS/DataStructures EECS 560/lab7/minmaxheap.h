#ifndef _minmaxheap_H
#define _minmaxheap_H
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <limits.h>

class minmaxheap {

	private:
		int heap[500];
		int num_nodes = 0;
		bool search(int x);
		bool insert_helper(int x, int parent, int cur_loc);
		void heapify(int i);
		bool isminlevel(int location);
		
	public:
		minmaxheap();
		minmaxheap(std::string input_file);
		bool is_empty();
		void insert(int x);
		void remove(int x);
		void delete_min();
		void delete_max();
		void level_order();
};

#endif