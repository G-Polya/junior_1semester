// 2016112158 ±èÈñ¼ö
#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
#include "Hamilton.h"
#include <algorithm>
using namespace std;


int main()
{


	vector<string> spectrum1 = { "ATG","TGG","TGC","GTG","GGC","GCA","GCG","CGT" };
	Hamilton h1(spectrum1);
	int** matrix_h1 = (int**)make_adjacentMatrix(spectrum1);
	int size = spectrum1.size();
	int overlap = spectrum1[0].length()-1;
	int* visited = new int[size];
	reset_visited(visited, size);
	show_matrix(matrix_h1, size, size);
	h1.DFS_start(visited, matrix_h1, overlap);

}