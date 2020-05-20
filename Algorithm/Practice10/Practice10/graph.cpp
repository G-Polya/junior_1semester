
// 인접행렬 구현
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "graph.h"
#include <algorithm>
using namespace std;

vector<Edge> make_Edges(vector<vector<int>> adjList)
{
	int row = adjList.size();
	vector<Edge> edges;
	
	for (int i = 0; i < row; i++)
	{	
		
		for (int j = 0; j < adjList[i].size(); j++)
		{
			Edge edge;
			edge.setSrc(i);
			edge.setDest(adjList[i][j]);
			edges.push_back(edge);
		}
		
	}

	return edges;
}

void show_matrix(int** mat, int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

void show_matrix(int mat[][8], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

void show_matrix(vector<vector<int>> mat)
{
	int col = mat[0].size();
	int row = mat.size();

	for (vector<int> row : mat)
	{
		for (int element : row)
			cout << element << " ";
		cout << endl;
	}
		
}


vector<vector<int>> vector_Matrix(int** graph, int col, int row)
{
	
	vector<vector<int>> mat;
	for (int i = 0; i < row; i++)
	{
		vector<int> row;
		for (int j = 0; j < col; j++)
		{
			row.push_back(graph[i][j]);
		}
		mat.push_back(row);
	}

	return mat;
}

vector<vector<int>> vector_Matrix(int graph[8][8], int col, int row)
{
	vector<vector<int>> mat;
	for (int i = 0; i < row; i++)
	{
		vector<int> row;
		for (int j = 0; j < col; j++)
		{
			row.push_back(graph[i][j]);
		}
		mat.push_back(row);
	}

	return mat;
}

vector<vector<int>> convert_toList(vector<vector<int>> a)
{
	vector<vector<int>> adjList(a.size());

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			if (a[i][j] == 1)
				adjList[i].push_back(j);
		}
	}

	return adjList;
}

void print_adjList(vector<vector<int>> adjList, vector<tuple<string, int>> spec)
{
	for (int i = 0; i < adjList.size(); i++)
	{
		cout << get<0>(spec[i]);
		for (int j = 0; j < adjList[i].size(); j++)
		{
			if (adjList[i].size() == 0)
				continue;

			if (j == adjList[i].size()-1)
			{
				cout << " -> " << get<0>(spec[adjList[i][j]]);
				break;
			}
			else
				cout << " -> " << get<0>(spec[adjList[i][j]]);
		}
		cout << endl;
	}
}


void print_adjList(vector<vector<int>> adjList)
{
	for (int i = 0; i < adjList.size(); i++)
	{
		cout << i;
		for (int j = 0; j < adjList[i].size(); j++)
		{
			if (j == adjList[i].size() - 1)
			{
				cout << " -> " << adjList[i][j];
				break;
			}
			else
				cout << " -> " << adjList[i][j];


		}
		cout << endl;
	}
}
int** make_adjacentMatrix(vector<tuple<string, int>> spec)
{
	int row = spec.size();
	int col = spec.size();

	int** mat = new int* [row];
	for (int i = 0; i < row; i++)
		mat[i] = new int[col];
	
	for (int i = 0; i < row; i++)
	{
		string one = get<0>(spec[i]);

		for (int j = 0; j < col; j++)
		{
			mat[i][j] = 0;
			if (i == j)
				mat[i][j] = 0;

			string two = get<0>(spec[j]);

			if (one[one.length() - 2] == two[0] && one[one.length() - 1] == two[1])	//기준의 끝두글자와 비교대상의 앞두글자가 같으면 연결되어있다. 
			{
				mat[i][j] = 1;
			}

			if (one == two)
				mat[i][j] = 0;
		}
	}

	return mat;
}

// 주어진 스트링들을 기반으로한 인접행렬을 생성한다
int** make_adjacentMatrix(vector<DNA> spec)
{
	int row = spec.size();
	int col = spec.size();

	int** mat = new int* [row];
	for (int i = 0; i < row; i++)
		mat[i] = new int[col];

	for (int i = 0; i < row; i++)
	{
		string one = spec[i].get_String();

		for (int j = 0; j < col; j++)
		{
			mat[i][j] = 0;

			if (i == j)
				mat[i][j] = 0;

			string two = spec[j].get_String();

			if (one[one.length() - 2] == two[0] && one[one.length() - 1] == two[1])	//기준의 끝두글자와 비교대상의 앞두글자가 같으면 연결되어있다. 
			{
				mat[i][j] = 1;
			}

			if (one == two)
				mat[i][j] = 0;

		}
	}

	return mat;
}

void printAllHamiltonianPaths(Graph const& g, int v, vector<bool>visited, vector<int>& path, int N)
{
	// if all the vertices are visited, then
	// Hamiltonian path exists
	if (path.size() == N)
	{
		// print Hamiltonian path
		for (int i : path)
			cout << i << " ";
		cout << endl;

		return;
	}

	// Check if every edge starting from vertex v leads
	// to a solution or not
	for (int w : g.adjList[v])
	{
		// process only unvisited vertices as Hamiltonian
		// path visits each vertex exactly once
		if (!visited[w])
		{
			visited[w] = true;
			path.push_back(w);

			// check if adding vertex w to the path leads
			// to solution or not
			printAllHamiltonianPaths(g, w, visited, path, N);

			// Backtrack
			visited[w] = false;
			path.pop_back();
		}
	}
}