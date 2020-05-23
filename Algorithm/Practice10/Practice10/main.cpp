// 2016112158 김희수
#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
#include "DNA.h"
#include "Hamilton.h"
#include <map>
#include <list>
using namespace std;


// 1. 먼저 주어진 spectrum을 그래프로 만든다. 이때 그래프는 방향그래프이며 표현은 인접행렬이다.
// 2. 주어진 그래프를 토대로 해밀턴 경로를 찾는다. 

string concat(string zero, list<string> queue)
{
	string result;
	if (zero == "")
	{
		result = "" + queue.front();
		queue.pop_front();
		result += queue.front().substr(2, 1);

		return result;
	}
	else
	{
		queue.pop_front();
		result = zero + queue.front().substr(2, 1);
		return result;
	}


}

void hamilton_path(vector<string> spectrum)
{
	int row = spectrum.size();
	int col = spectrum.size();
	
	string restored = "";

	for (int i = 0; i < row; i++)
	{
		list<string> queue;
		queue.push_back(spectrum[0]);
		for (int j = 0; j < col; j++)
		{

		}
		string selected = queue.front();
		//cout << selected << endl;
		string compete = spectrum[i];
		
		if (selected[selected.length() - 2] == compete[0] && selected[selected.length() - 1] == compete[1])
		{
			
			queue.push_back(compete);
			for (auto iter = begin(queue); iter != end(queue); iter++)
				cout << *iter << endl;

			restored = concat(restored, queue);
			cout << "restored : " << restored << endl;
			cout << endl;

			queue.pop_front();
			
		}
	}
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

	vector<string> spectrum1 = { "ATG", "TGG", "TGC","GTG","GGC","GCA","GCG","CGT" };


	
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
	hamilton_path(spectrum1);
	
	cout << endl;


}