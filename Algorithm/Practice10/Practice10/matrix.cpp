
// 인접행렬 구현
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void show_matrix(bool** mat, int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

void show_matrix(bool mat[][8], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}


// 주어진 스트링들을 기반으로한 인접행렬을 생성한다
bool** make_adjacentMatrix(vector<string> spectrum)
{
	int col = spectrum.size();
	int row = spectrum.size();

	bool** mat = new bool* [col];
	for (int i = 0; i < col; i++)
		mat[i] = new bool[row];

	for (int i = 0; i < col; i++)
	{
		string one = spectrum[i];		// 기준이 되는 스트링
		for (int j = 0; j < row; j++)
		{
			mat[i][j] = 0;

			if (i == j)
				mat[i][j] = 0;


			string two = spectrum[j];	// 기준과 비교되는 대상스트링

			if (one[one.length() - 2] == two[0] && one[one.length() - 1] == two[1])	//기준의 끝두글자와 비교대상의 앞두글자가 같으면 연결되어있다. 
			{
				mat[i][j] = 1;

			}

			
			if (one == two)		// 자기자신이면 0
				mat[i][j] = 0;

		}
	}


	
	return mat;
}
