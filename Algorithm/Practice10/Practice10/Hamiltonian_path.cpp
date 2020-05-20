#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include "matrix.h"
using namespace std;

//https://www.tutorialspoint.com/cplusplus-program-to-check-whether-a-hamiltonian-cycle-or-path-exists-in-a-given-graph
//https://www.geeksforgeeks.org/hamiltonian-cycle-backtracking-6/


int main()
{
	vector<string> spectrum1 = { "ATG","TGG","TGC","GTG","GGC","GCA","GCG","CGT" };
	make_adjacentMatrix(spectrum1);

	//show_matrix(matrix);
	
}