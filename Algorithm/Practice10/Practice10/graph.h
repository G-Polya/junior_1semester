#pragma once
#include "DNA.h"

// 인접행렬을 구현하기 위한 헤더
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;


class Edge
{
private:
	int src;
	int dest;

public:
	Edge()
	{}

	void setSrc(int src)
	{
		this->src = src;
	}

	void setDest(int dest)
	{
		this->dest = dest;
	}

	int getSrc()
	{
		return src;
	}

	int getDest()
	{
		return dest;
	}
};

// class to represent a graph object
class Graph
{
public:
	// An array of vectors to represent adjacency list
	vector<vector<int>> adjList;

	// Constructor
	Graph(vector<Edge>& edges, int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);

		// add edges to the undirected graph
		for (unsigned i = 0; i < edges.size(); i++)
		{
			int src = edges[i].getSrc();
			int dest = edges[i].getDest();

			adjList[src].push_back(dest);
			adjList[dest].push_back(src);
		}
	}
};



int** make_adjacentMatrix(vector<DNA> spec);
int** make_adjacentMatrix(vector<tuple<string, int>> spec);

void show_matrix(int** mat, int col, int row);
void show_matrix(int mat[][8], int col, int row);
void show_matrix(vector<vector<int>> mat);

vector<vector<int>> vector_Matrix(int** graph, int col, int row);
vector<vector<int>> vector_Matrix(int graph[8][8], int col, int row);
vector<vector<int>> convert_toList(vector<vector<int>> mat);

void print_adjList(vector<vector<int>> adjlist);
void print_adjList(vector<vector<int>> adjList, vector<tuple<string, int>> spec);

void printAllHamiltonianPaths(Graph const& g, int v, vector<bool>visited, vector<int>& path, int N);
vector<Edge> make_Edges(vector<vector<int>> adjList);
