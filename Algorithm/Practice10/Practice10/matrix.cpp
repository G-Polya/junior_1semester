
// ������� ����
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


// �־��� ��Ʈ������ ��������� ��������� �����Ѵ�
bool** make_adjacentMatrix(vector<string> spectrum)
{
	int col = spectrum.size();
	int row = spectrum.size();

	bool** mat = new bool* [col];
	for (int i = 0; i < col; i++)
		mat[i] = new bool[row];

	for (int i = 0; i < col; i++)
	{
		string one = spectrum[i];		// ������ �Ǵ� ��Ʈ��
		for (int j = 0; j < row; j++)
		{
			mat[i][j] = 0;

			if (i == j)
				mat[i][j] = 0;


			string two = spectrum[j];	// ���ذ� �񱳵Ǵ� ���Ʈ��

			if (one[one.length() - 2] == two[0] && one[one.length() - 1] == two[1])	//������ ���α��ڿ� �񱳴���� �յα��ڰ� ������ ����Ǿ��ִ�. 
			{
				mat[i][j] = 1;

			}

			
			if (one == two)		// �ڱ��ڽ��̸� 0
				mat[i][j] = 0;

		}
	}


	
	return mat;
}
