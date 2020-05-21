#include "Hamilton.h"
#include "graph.h"

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