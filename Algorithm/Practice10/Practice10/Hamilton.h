#pragma once
#include <iostream>

#include "graph.h"

using namespace std;


class Hamilton
{
private:
	vector<string> spectrum;
	string start_string;
	
public:
	Hamilton(vector<string> spec)
		:spectrum(spec)
	{}

	void DFS_start(int* visited, int** adjMat,int overlap);
	void DFS(int node, int* visited, int** adjMat,int overlap);
	
};