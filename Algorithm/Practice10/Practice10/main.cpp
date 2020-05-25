// 2016112158 �����
#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
#include "DNA.h"
#include "Hamilton.h"
#include <map>
#include <list>
#include <algorithm>
using namespace std;

#define NOT_IN_STACK 0
#define IN_STACK 1


// 1. ���� �־��� spectrum�� �׷����� �����. �̶� �׷����� ����׷����̸� ǥ���� ��������̴�.
// 2. �־��� �׷����� ���� �ع��� ��θ� ã�´�. 



int main()
{
	

	vector<string> spectrum1 = { "ATG", "TGG", "TGC","GTG","GGC","GCA","GCG","CGT" };
	Hamilton h1(spectrum1);
	int** matrix_h1 = (int**)make_adjacentMatrix(spectrum1);
	int size = spectrum1.size();
	int* visited = new int[size];
	reset_visited(visited,size);
	
	show_matrix(matrix_h1, size, size);
	h1.DFS_start(visited, matrix_h1);


}