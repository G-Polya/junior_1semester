// 2016112158 김희수
#include "matrix.h"
#include "Hamilton.h"
using namespace std;

//https://www.tutorialspoint.com/cplusplus-program-to-check-whether-a-hamiltonian-cycle-or-path-exists-in-a-given-graph
//https://www.geeksforgeeks.org/hamiltonian-cycle-backtracking-6/

// 1. 먼저 주어진 spectrum을 그래프로 만든다. 이때 그래프는 방향그래프이며 표현은 인접행렬이다.
// 2. 주어진 그래프를 토대로 해밀턴 경로를 찾는다. 
class DNA
{
private:
	string str;

public:
	DNA(string str)
	{
		this->str = str;
	}



};

int main()
{
	vector<string> spectrum1 = { "ATG","TGG","TGC","GTG","GGC","GCA","GCG","CGT" };
	bool** matrix = make_adjacentMatrix(spectrum1);
	
	const int col = spectrum1.size();
	const int row = spectrum1.size();
//	show_matrix(matrix, col, row);
	bool graph[8][8];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			graph[i][j] = matrix[i][j];
	}

	show_matrix(graph, col, row);
	hamilton_path(graph);
}