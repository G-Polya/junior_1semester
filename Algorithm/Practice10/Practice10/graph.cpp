
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

bool all_false(int* row, int spectrum_size)
{
	for (int i = 0; i < spectrum_size;i++)
		if (row[i] == 1 )
			return false;

	return true;
}

int not_visited_index(int* visited, int size)
{
	
	for (int i = 0;i < size-1; i++)
	{
		if (visited[i] == 0)
			return i;
	}
}

int** make_adjacentMatrix(vector<string> spec, int overlap)
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
			int length = one.length();
			if (one.substr(length-overlap,overlap) == two.substr(0,overlap))	//기준의 끝두글자와 비교대상의 앞두글자가 같으면 연결되어있다. 
			{
				mat[i][j] = 1;
			}

			if (one == two)
				mat[i][j] = 0;
		}
	}
	
	return mat;
}

string find_Max(vector<string> restored_DNAs)
{
	vector<int> lengths;
	for (int i = 0; i < restored_DNAs.size(); i++)
		lengths.push_back(restored_DNAs[i].length());

	int max = lengths[0];

	for (int i = 0; i < lengths.size(); i++)
	{
		if (lengths[i] > max)
			max = lengths[i];
	}

	for (int i = 0; i < restored_DNAs.size(); i++)
		if (restored_DNAs[i].length() == max)
			return restored_DNAs[i];

}