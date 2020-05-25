// 2016112158 김희수
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


// 1. 먼저 주어진 spectrum을 그래프로 만든다. 이때 그래프는 방향그래프이며 표현은 인접행렬이다.
// 2. 주어진 그래프를 토대로 해밀턴 경로를 찾는다. 



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