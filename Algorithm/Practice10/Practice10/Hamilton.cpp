#include "Hamilton.h"
#include "graph.h"



void Hamilton::DFS_start(int* visited, int** adjMat,int overlap)
{
	vector<string> temp_DNAs;		// �����Ǵ� DNA�� �����ϴ� vector
	int length = spectrum[0].length();
	int size = spectrum.size();
	int row = size;

	// ��� row ���ؼ� �۾�
	for (int i = 0; i < row; i++)
	{
		cout << i << " ��°���� ����" << endl;
		start_string = spectrum[i];
		DFS_even(i, visited, adjMat,overlap);		// DFS�� ����

		int index = not_visited_index(visited,size);
		start_string += spectrum[index].substr(overlap, length-overlap);
		cout <<"������ �̵� >> " <<start_string << endl;
		temp_DNAs.push_back(start_string);



		reset_visited(visited, size);			// reset visited 

		cout << i << " ��°���� ����" << endl;
		start_string = spectrum[i];
		DFS_odd(i, visited, adjMat, overlap);		// DFS�� �����Ͽ�

		
		index = not_visited_index(visited, size);
		start_string += spectrum[index].substr(overlap, length - overlap);
		cout << "������ �̵� >> " << start_string << endl;
		temp_DNAs.push_back(start_string);
		
		reset_visited(visited, size);	// reset visited


		start_string = "";
		cout << endl;
	}

	if (temp_DNAs.size() != 0)
	{
		for (int i = 0; i < temp_DNAs.size(); i++)
		{
			
			cout << "��� : " << temp_DNAs[i] << endl;
		}
		cout << endl;
		vector<string> restored_DNAs = find_Max(temp_DNAs);
		cout << "������ DNA : " << endl;
		for (int i = 0; i < restored_DNAs.size(); i++)
			cout << restored_DNAs[i] << endl;


	}
	else
		cout << "no string" << endl;
}

void Hamilton::DFS_even(int node, int* visited, int** adjMat,int overlap)
{
	
	visited[node] = 1;
	int size = spectrum.size();


	for (int i = 0; i < size; i += 2)
	{

		if ((visited[i] == 0) && ((adjMat[node][i] == 1)) && !all_false(adjMat[i], size))		// �湮���߰�, ������ �ְ�, ������ ��尡 �ƴϸ�
		{

			cout << node << "���� " << i << " �� �̵� >> ";
			int length = spectrum[i].length();
			start_string = start_string + spectrum[i].substr(overlap, length - overlap);		// ����
			cout << start_string << endl;
			DFS_even(i, visited, adjMat, overlap);
		}

	}

	for (int i = 1; i < size; i += 2)
	{

		if ((visited[i] == 0) && ((adjMat[node][i] == 1)) && !all_false(adjMat[i], size))
		{

			cout << node << "���� " << i << " �� �̵� >> ";
			int length = spectrum[i].length();
			start_string = start_string + spectrum[i].substr(overlap, length - overlap);
			cout << start_string << endl;
			DFS_even(i, visited, adjMat, overlap);
		}

	}
}

void Hamilton::DFS_odd(int node, int* visited, int** adjMat, int overlap)
{
	visited[node] = 1;
	int size = spectrum.size();


	for (int i = 1; i < size; i += 2)
	{

		if ((visited[i] == 0) && ((adjMat[node][i] == 1)) && !all_false(adjMat[i], size))
		{

			cout << node << "���� " << i << " �� �̵� >> ";
			int length = spectrum[i].length();
			start_string = start_string + spectrum[i].substr(overlap, length - overlap);
			cout << start_string << endl;
			DFS_odd(i, visited, adjMat, overlap);
		}

	}

	for (int i = 0; i < size; i += 2)
	{

		if ((visited[i] == 0) && ((adjMat[node][i] == 1)) && !all_false(adjMat[i], size))
		{

			cout << node << "���� " << i << " �� �̵� >> ";
			int length = spectrum[i].length();
			start_string = start_string + spectrum[i].substr(overlap, length - overlap);
			cout << start_string << endl;
			DFS_odd(i, visited, adjMat, overlap);
		}

	}
}