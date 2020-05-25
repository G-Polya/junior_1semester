
// 인접행렬 구현
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "graph.h"
#include <algorithm>
using namespace std;



void show_matrix(int** mat, int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

void reset_visited(int* visited,int spectrum_size)
{
	for (int i = 0; i < spectrum_size; i++)
		visited[i] = 0;
}

bool check_visited(int* visited, int spectrum_size)
{
	for (int i = 0; i < spectrum_size; i++)
		if (visited[i] == 0)
			return false;

	return true;
}


int** make_adjacentMatrix(vector<string> spec)
{
	int row = spec.size();
	int col = spec.size();

	int** mat = new int* [row];
	for (int i = 0; i < row; i++)
		mat[i] = new int[col];

	for (int i = 0; i < row; i++)
	{
		string one = spec[i];
		for (int j = 0; j < col; j++)
		{
			mat[i][j] = 0;

			if (i == j)
				mat[i][j] = 0;

			string two = spec[j];

			if (one.substr(one.length()-2,2) == two.substr(0,2))	//기준의 끝두글자와 비교대상의 앞두글자가 같으면 연결되어있다. 
			{
				mat[i][j] = 1;
			}

			if (one == two)
				mat[i][j] = 0;
		}
	}
	
	return mat;
}