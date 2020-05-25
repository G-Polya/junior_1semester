
// 인접행렬 구현
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "graph.h"
#include <algorithm>
using namespace std;

// overlap : 얼마나 겹치는지. overlap을 2로 할경우 AGTC GTAA의 겹치는 부분이 생겨서 연결이 된다.
// 하지만 overlap을 3으로 할경우 AGTC와 GTAA는 겹치지 않아 연결되지 않는다.
// 예를 들어 overlap을 2라하자
int** make_adjacentMatrix(vector<string> spec, int overlap)
{
	int row = spec.size();
	int col = spec.size();

	int** mat = new int* [row];
	for (int i = 0; i < row; i++)
		mat[i] = new int[col];

	for (int i = 0; i < row; i++)
	{
		string one = spec[i];			// 기준
		for (int j = 0; j < col; j++)
		{
			mat[i][j] = 0;

			if (i == j)
				mat[i][j] = 0;

			string two = spec[j];		// 비교대상
			int length = one.length();
			if (one.substr(length-overlap,overlap) == two.substr(0,overlap))	// 기준의 뒤의 2글자와 비교대상의 앞의 두글자가 같으면 1
			{
				mat[i][j] = 1;
			}

			if (one == two)			// 기준과 비교대상이 같은 스트링이면 0
				mat[i][j] = 0;
		}
	}
	
	return mat;
}


// 인접행렬 출력. mat : 인접행렬, col : 인접행렬의 column수 , row: 인접행렬의 row 수
void show_matrix(int** mat, int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}


// 방문했는지 알기 위한 초기화
void reset_visited(int* visited, int spectrum_size)
{
	for (int i = 0; i < spectrum_size; i++)
		visited[i] = 0;
}

// 방문안했으면 false
bool check_visited(int* visited, int spectrum_size)
{
	for (int i = 0; i < spectrum_size; i++)
		if (visited[i] == 0)
			return false;

	return true;
}

// 한번도 다른 정점으로 나가는 간선이 없는지를 체크하는 함수
// 0 1 0
// 0 0 0
// 1 1 0
// 에서 2번째 row를 검사하면 true를 반환한다.
bool all_false(int* row, int spectrum_size)
{
	for (int i = 0; i < spectrum_size; i++)
		if (row[i] == 1)
			return false;

	return true;
}

// 방문 안한 인덱스를 반환하는 함수
int not_visited_index(int* visited, int size)
{

	for (int i = 0; i < size - 1; i++)
	{
		if (visited[i] == 0)
			return i;
	}
}


// 최대 길이를 가진 스트링들로 구성된 vector반환
vector<string> find_Max(vector<string> temp_DNAs)
{
	
	vector<string> restored_DNAs;
	vector<int> lengths;
	for (int i = 0; i < temp_DNAs.size(); i++)
		lengths.push_back(temp_DNAs[i].length());

	int max = *max_element(lengths.begin(), lengths.end());

	for (int i = 0; i < temp_DNAs.size(); i++)
		if (temp_DNAs[i].length() == max)
		{
			restored_DNAs.push_back(temp_DNAs[i]);
		}

	return restored_DNAs;
}