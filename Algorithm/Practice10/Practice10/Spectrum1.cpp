// 2016112158 �����
#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
#include "Hamilton.h"
#include <algorithm>
using namespace std;


int main()
{
	

	vector<string> spectrum1 = { "AGT" ,"AAA","ACT","ACT","AAC","CTT","GTA","TTT","TAA" };
	Hamilton h1(spectrum1);
	int overlap = spectrum1[0].length() - 1;
	int** matrix_h1 = (int**)make_adjacentMatrix(spectrum1,overlap);
	int size = spectrum1.size();
	int* visited = new int[size];
	reset_visited(visited,size);	
	show_matrix(matrix_h1, size, size);
	h1.DFS_start(visited, matrix_h1, overlap);

}