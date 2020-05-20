#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
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


void show_queue(queue<string> q)
{
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}


// 주어진 스트링들을 기반으로한 인접행렬을 생성한다

void make_adjacentMatrix(vector<string> spectrum)
{
	int col = spectrum.size();
	int row = spectrum.size();

	bool** mat = new bool* [col];
	for (int i = 0; i < col; i++)
		mat[i] = new bool[row];

	for (int i = 0; i < col; i++)
	{
		string one = spectrum[i];		// 기준
		for (int j = 0; j < row; j++)
		{
			mat[i][j] = 0;

			if (i == j)
				mat[i][j] = 0;


			string two = spectrum[j];	// 비교

			if (one[one.length() - 2] == two[0] && one[one.length() - 1] == two[1])
			{
				mat[i][j] = 1;

			}

			//mat[j][i] = mat[i][j];
			if (one == two)
				mat[i][j] = 0;

		}
	}


	show_matrix(mat, col, row);

}
