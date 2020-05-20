#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
using namespace std;

//https://www.tutorialspoint.com/cplusplus-program-to-check-whether-a-hamiltonian-cycle-or-path-exists-in-a-given-graph
//https://www.geeksforgeeks.org/hamiltonian-cycle-backtracking-6/

void show_matrix(bool** mat)
{
	ofstream fout;
	fout.open("matrix.txt", ios::app | ios::out);

	fout << endl;
	int col = 8;
	int row = 8;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}

	fout.close();
}

void show_matrix(bool matrix[][8])
{
	ofstream fout;
	fout.open("matrix.txt", ios::app | ios::out);

	int col = 8;
	int row = 8;

	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	fout.close();
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


// �־��� ��Ʈ������ ��������� ��������� �����Ѵ�
void make_adjacentMatrix(vector<string> spectrum)
{
	
	bool matrix[8][8];
	bool** mat = new bool* [spectrum.size()];
	for (int i = 0; i < spectrum.size(); i++)
		mat[i] = new bool[spectrum.size()];


	// ť ������ �ʱ�ȭ
	queue<string> spectrum_q;
	for (auto& str : spectrum)
	{
		spectrum_q.push(str);
	}
	

	for (int i = 0; i < spectrum.size(); i++)		// ���ؼ���
	{
		string one = spectrum_q.front();
		
		cout << "���� : " << one << endl;
		
		for (int j = 0; j < spectrum.size(); j++)	// �񱳴����
		{
			
			string two = spectrum_q.front();
			spectrum_q.pop();
			spectrum_q.push(two);
			cout << "�� : " << two << endl;
			show_queue(spectrum_q);
			
			cout << one[one.length() - 2] << " vs. " << two[0] << endl;
			cout << one[one.length() - 1] << " vs. " << two[1] << endl;

			
			while (one != two)
			{
				
				if (one[one.length() - 2] == two[0] && one[one.length() - 1] == two[1])
				{

					matrix[i][j] = true;
					mat[i][j] = true;
				}
				else
				{
					matrix[i][j] = false;
					mat[i][j] = false;
				}			
				break;
			}
			while (one == two)
			{
				matrix[i][j] = false;
				mat[i][j] = false;
				break;
			}

			cout << "matrix[1] : " << matrix[i][j] << endl;
			cout << "mat[1] : " << mat[i][j] << endl;
			
			cout << "----------------" << endl;
		}
		spectrum_q.pop();
		spectrum_q.push(one);

		cout << "===========================" << endl;

	}

	show_matrix(matrix);
	cout << endl;
	show_matrix(mat);

}

int main()
{
	vector<string> spectrum1 = { "AGT","GTA","ACT","AAC","CTT","AAA","TTT","TAA" };
	make_adjacentMatrix(spectrum1);

	//show_matrix(matrix);
	
}