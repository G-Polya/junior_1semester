// 2016112158 �����
#include "matrix.h"
#include "Hamilton.h"
using namespace std;

//https://www.tutorialspoint.com/cplusplus-program-to-check-whether-a-hamiltonian-cycle-or-path-exists-in-a-given-graph
//https://www.geeksforgeeks.org/hamiltonian-cycle-backtracking-6/

// 1. ���� �־��� spectrum�� �׷����� �����. �̶� �׷����� ����׷����̸� ǥ���� ��������̴�.
// 2. �־��� �׷����� ���� �ع��� ��θ� ã�´�. 
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