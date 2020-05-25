#include "Hamilton.h"
#include "graph.h"

void Hamilton::DFS_start(int* visited, int** adjMat)
{
	vector<string> restored_DNA;
	int size = spectrum.size();
	for (int i = 0; i < size; i++)
	{
		cout << i << " 번째에서 시작" << endl;
		start_string = spectrum[i];
		DFS(i, visited, adjMat);

		int index = not_visited_index(visited);
		start_string += spectrum[index].substr(spectrum[0].length() - 1, 1);
		cout << start_string << endl;
		restored_DNA.push_back(start_string);

		//if (check_visited(visited, size+1) && (start_string.length() == spectrum[i].length() + spectrum.size() - 1))
		//{
		//	cout << "푸시" << endl;
		//	restored_DNA.push_back(start_string);
		//}
		//else
		//	cout << "없음" << endl;

		reset_visited(visited, size);

		start_string = "";
		cout << endl;
	}

	if (restored_DNA.size() != 0)
	{
		for (int i = 0; i < restored_DNA.size(); i++)
			cout << "결과 : " << restored_DNA[i] << endl;
		
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
		if (all_false(adjMat[node], size))
			visited[node] = 0;

		if ((visited[i] == 0) && ((adjMat[node][i] == 1)) && !all_false(adjMat[i],size))
		{
	
			cout << node << "에서 " << i << " 로 이동 >> "<<"visted["<<i<<"] : "<<visited[i] << endl;
			start_string = start_string + spectrum[i].substr(spectrum[i].length() - 1, 1);
			cout << start_string << endl;
			DFS(i,visited,adjMat);
			cout << "==== " << recursion_level<<" ===="<<endl;

		}
		
	}


}
