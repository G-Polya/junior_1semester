
// ������� ����
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "graph.h"
#include <algorithm>
using namespace std;

// overlap : �󸶳� ��ġ����. overlap�� 2�� �Ұ�� AGTC GTAA�� ��ġ�� �κ��� ���ܼ� ������ �ȴ�.
// ������ overlap�� 3���� �Ұ�� AGTC�� GTAA�� ��ġ�� �ʾ� ������� �ʴ´�.
// ���� ��� overlap�� 2������
int** make_adjacentMatrix(vector<string> spec, int overlap)
{
	int row = spec.size();
	int col = spec.size();

	int** mat = new int* [row];
	for (int i = 0; i < row; i++)
		mat[i] = new int[col];

	for (int i = 0; i < row; i++)
	{
		string one = spec[i];			// ����
		for (int j = 0; j < col; j++)
		{
			mat[i][j] = 0;

			if (i == j)
				mat[i][j] = 0;

			string two = spec[j];		// �񱳴��
			int length = one.length();
			if (one.substr(length-overlap,overlap) == two.substr(0,overlap))	// ������ ���� 2���ڿ� �񱳴���� ���� �α��ڰ� ������ 1
			{
				mat[i][j] = 1;
			}

			if (one == two)			// ���ذ� �񱳴���� ���� ��Ʈ���̸� 0
				mat[i][j] = 0;
		}
	}
	
	return mat;
}


// ������� ���. mat : �������, col : ��������� column�� , row: ��������� row ��
void show_matrix(int** mat, int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}


// �湮�ߴ��� �˱� ���� �ʱ�ȭ
void reset_visited(int* visited, int spectrum_size)
{
	for (int i = 0; i < spectrum_size; i++)
		visited[i] = 0;
}

// �湮�������� false
bool check_visited(int* visited, int spectrum_size)
{
	for (int i = 0; i < spectrum_size; i++)
		if (visited[i] == 0)
			return false;

	return true;
}

// �ѹ��� �ٸ� �������� ������ ������ �������� üũ�ϴ� �Լ�
// 0 1 0
// 0 0 0
// 1 1 0
// ���� 2��° row�� �˻��ϸ� true�� ��ȯ�Ѵ�.
bool all_false(int* row, int spectrum_size)
{
	for (int i = 0; i < spectrum_size; i++)
		if (row[i] == 1)
			return false;

	return true;
}

// �湮 ���� �ε����� ��ȯ�ϴ� �Լ�
int not_visited_index(int* visited, int size)
{

	for (int i = 0; i < size - 1; i++)
	{
		if (visited[i] == 0)
			return i;
	}
}


// �ִ� ���̸� ���� ��Ʈ����� ������ vector��ȯ
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