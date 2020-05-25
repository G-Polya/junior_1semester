#pragma once
#include <iostream>

#include "graph.h"

using namespace std;


class Hamilton
{
private:
	vector<string> spectrum;
	string start_string;
	int recursion_level = 0;
public:
	Hamilton(vector<string> spec)
		:spectrum(spec)
	{}

	void DFS_start(int* visited, int** adjMat);
	void DFS(int node, int* visited, int** adjMat);
	
};