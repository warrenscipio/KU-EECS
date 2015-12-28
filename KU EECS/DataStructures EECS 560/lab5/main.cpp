#include <iostream>
#include <math.h>
#include "hash_table.cpp"
#include "lin_hash_table.cpp"
#include "quad_hash_table.cpp"
#include "Timer.cpp"

#define K 600011

int main(int argc, char* argv[]){
	Timer timer; 
	hash_table*  open_hash;
	quad_hash_table* quad_hash;
	lin_hash_table* lin_hash;

	double c_hash_lin_time[4][5];
	double c_hash_quad_time[4][5];
	double o_hash_time[4][5];
	
	
	for(int i = 2; i<=5; i++){
		double load_factor = 0.1*i;
		double rand_values[(int) floor(K*load_factor)];
		for(int j = 1; j<=5; j++) {
			srand(j);
			open_hash = new hash_table(K);
			quad_hash = new quad_hash_table(K);
			lin_hash = new lin_hash_table(K);
			
			for(int k = 1; k<=K*load_factor; k++) {
				rand_values[k] = rand();
				
			}
			
			timer.start();
			for(int k = 1; k<=K*load_factor; k++) {
				lin_hash->insert(rand_values[k]);
				
			}
			c_hash_lin_time[i-2][j-1] = timer.stop();
			

			timer.start();
			for(int k = 1; k<=K*load_factor; k++) {
				quad_hash->insert(rand_values[k]);
			}
			
			c_hash_quad_time[i-2][j-1] = timer.stop();
			
			timer.start();
			for(int k = 1; k<=K*load_factor; k++) {
				open_hash->insert(rand_values[k]);
			}
			
			o_hash_time[i-2][j-1] = timer.stop();
			
		}
		
	}

	std::cout << "---------------------------------------------------------\n";

	for(int i = 0; i < 4; i++) {
		double averageOpenHashTime = 0;
		double averageLinearHashTime = 0;
		double averageQuadraticHashTime = 0;
		for (int j = 0; j < 5; j++) {
			
			averageOpenHashTime += o_hash_time[i][j];
			averageLinearHashTime += c_hash_lin_time[i][j];
			averageQuadraticHashTime += c_hash_quad_time[i][j];
		}
		std::cout << "average Open Hash Time: " << averageOpenHashTime/5 << std::endl;
		std::cout << "average Linear Closed Hash Time: " << averageLinearHashTime/5 << std::endl;
		std::cout << "average Quadratic Closed Hash Time: " << averageQuadraticHashTime/5 << std::endl;
	}
}
