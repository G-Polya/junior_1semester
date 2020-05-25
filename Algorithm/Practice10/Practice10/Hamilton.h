#pragma once
#include <iostream>
#include <random>
#include <ctime>
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

	void DFS_start(int* visited, int** adjMat,int overlap);		// DFS Ω√¿€
	void DFS_even(int node, int* visited, int** adjMat,int overlap);		// DFS
	void DFS_odd(int node, int* visited, int** adjMat, int overlap);		// DFS
	
};