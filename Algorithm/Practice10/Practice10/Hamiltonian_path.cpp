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


// 주어진 스트링들을 기반으로한 인접행렬을 생성한다
void make_adjacentMatrix(vector<string> spectrum)
{
	
	bool matrix[8][8];
	bool** mat = new bool* [spectrum.size()];
	for (int i = 0; i < spectrum.size(); i++)
		mat[i] = new bool[spectrum.size()];


	// 큐 생성과 초기화
	queue<string> spectrum_q;
	for (auto& str : spectrum)
	{
		spectrum_q.push(str);
	}
	

	for (int i = 0; i < spectrum.size(); i++)		// 기준선택
	{
		string one = spectrum_q.front();
		
		cout << "기준 : " << one << endl;
		
		for (int j = 0; j < spectrum.size(); j++)	// 비교대상선택
		{
			
			string two = spectrum_q.front();
			spectrum_q.pop();
			spectrum_q.push(two);
			cout << "비교 : " << two << endl;
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