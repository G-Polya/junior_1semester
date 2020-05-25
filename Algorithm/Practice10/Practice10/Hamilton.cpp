#include "Hamilton.h"
#include "graph.h"

void Hamilton::DFS_start(int* visited, int** adjMat)
{
	vector<string> restored_DNA;
	int size = spectrum.size();
	for (int i = 0; i < size; i++)
	{
		cout << i << " ��°���� ����" << endl;
		start_string = spectrum[i];
		DFS(i, visited, adjMat);

		if (check_visited(visited, size) && (start_string.length() == spectrum[i].length() + spectrum.size() - 1))
		{
			cout << "Ǫ��" << endl;
			restored_DNA.push_back(start_string);
		}
		else
			cout << "����" << endl;

		reset_visited(visited, size);

		start_string = "";
		cout << endl;
	}

	if (restored_DNA.size() != 0)
	{
		for (int i = 0; i < restored_DNA.size(); i++)
			cout << "��� : " << restored_DNA[i] << endl;
		
		cout << endl << endl;
	}
	else
		cout << "no string" << endl;
}

void Hamilton::DFS(int node, int* visited, int** adjMat)
{
	visited[node] = 1;
	int size = spectrum.size();
	for (int i = 0; i < size; i++)
	{
		if ((visited[i] == 0) && ((adjMat[node][i] == 1)))
		{
			cout << node << "���� " << i << " �� �̵�" << endl;
			start_string = start_string + spectrum[i].substr(spectrum[i].length()-1,1);
			DFS(i,visited,adjMat);
		}
	}
}