#pragma once
#include <iostream>

#include "graph.h"
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



void printAllHamiltonianPaths(Graph const& g, int v, vector<bool>visited, vector<int>& path, int N);
vector<Edge> make_Edges(vector<vector<int>> adjList);
