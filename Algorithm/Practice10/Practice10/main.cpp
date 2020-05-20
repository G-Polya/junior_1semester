// 2016112158 김희수
#include "graph.h"
#include "DNA.h"
#include <map>
using namespace std;

//https://www.tutorialspoint.com/cplusplus-program-to-check-whether-a-hamiltonian-cycle-or-path-exists-in-a-given-graph
//https://www.geeksforgeeks.org/hamiltonian-cycle-backtracking-6/

// 1. 먼저 주어진 spectrum을 그래프로 만든다. 이때 그래프는 방향그래프이며 표현은 인접행렬이다.
// 2. 주어진 그래프를 토대로 해밀턴 경로를 찾는다. 

vector<vector<int>> convert(vector<vector<int>> a)
{
	vector<vector<int>> adjList(a.size());
	for (int i = 0; i < a.size(); i++)
	{

		for (int j = 0; j < a[i].size(); j++)
		{
			if (a[i][j] == 1)
			{
				adjList[i].push_back(j);
			}
		}
	}
	return adjList;
}


int main()
{


	vector<tuple<string, int>> spec =
	{
		make_tuple("ATG",0),
		make_tuple("TGG",1),
		make_tuple("TGC",2),
		make_tuple("GTG",3),
		make_tuple("GGC",4),
		make_tuple("GCA",5),
		make_tuple("GCG",6),
		make_tuple("CGT",7),
	};



	
	int** matrix = make_adjacentMatrix(spec);
	
	const int col = spec.size();
	const int row = spec.size();
	int graph[8][8];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			graph[i][j] = matrix[i][j];
	}


	vector<vector<int>> mat = vector_Matrix(graph,col,row);
	show_matrix(mat);
	
	vector<vector<int>> adjList = convert_toList(mat);
	print_adjList(adjList);
	cout << endl;
	print_adjList(adjList, spec);
	cout << endl;

	
	vector<Edge> edges = make_Edges(adjList);

	for (int i = 0; i < edges.size(); i++)
	{
		cout << edges[i].getSrc() << ", " << edges[i].getDest() << endl;
	}
	cout << endl<<endl;

	int start = 0;
	int N = 8;
	Graph g(edges, N);

	vector<int> path;
	path.push_back(start);

	vector<bool> visited(N);
	visited[start] = true;

	printAllHamiltonianPaths(g, start, visited, path, N);

	return 0;

}