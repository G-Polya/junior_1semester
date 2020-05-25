#include "Hamilton.h"
#include "graph.h"



void Hamilton::DFS_start(int* visited, int** adjMat,int overlap)
{
	vector<string> temp_DNAs;		// 복원되는 DNA를 저장하는 vector
	int length = spectrum[0].length();
	int size = spectrum.size();
	int row = size;

	// 모든 row 대해서 작업
	for (int i = 0; i < row; i++)
	{
		cout << i << " 번째에서 시작" << endl;
		start_string = spectrum[i];
		DFS_even(i, visited, adjMat,overlap);		// DFS를 시작

		int index = not_visited_index(visited,size);
		start_string += spectrum[index].substr(overlap, length-overlap);
		cout <<"끝으로 이동 >> " <<start_string << endl;
		temp_DNAs.push_back(start_string);



		reset_visited(visited, size);			// reset visited 

		cout << i << " 번째에서 시작" << endl;
		start_string = spectrum[i];
		DFS_odd(i, visited, adjMat, overlap);		// DFS를 시작하여

		
		index = not_visited_index(visited, size);
		start_string += spectrum[index].substr(overlap, length - overlap);
		cout << "끝으로 이동 >> " << start_string << endl;
		temp_DNAs.push_back(start_string);
		
		reset_visited(visited, size);	// reset visited


		start_string = "";
		cout << endl;
	}

	if (temp_DNAs.size() != 0)
	{
		for (int i = 0; i < temp_DNAs.size(); i++)
		{
			
			cout << "결과 : " << temp_DNAs[i] << endl;
		}
		cout << endl;
		vector<string> restored_DNAs = find_Max(temp_DNAs);
		cout << "복원된 DNA : " << endl;
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

		if ((visited[i] == 0) && ((adjMat[node][i] == 1)) && !all_false(adjMat[i], size))		// 방문안했고, 연결이 있고, 마지막 노드가 아니면
		{

			cout << node << "에서 " << i << " 로 이동 >> ";
			int length = spectrum[i].length();
			start_string = start_string + spectrum[i].substr(overlap, length - overlap);		// 연결
			cout << start_string << endl;
			DFS_even(i, visited, adjMat, overlap);
		}

	}

	for (int i = 1; i < size; i += 2)
	{

		if ((visited[i] == 0) && ((adjMat[node][i] == 1)) && !all_false(adjMat[i], size))
		{

			cout << node << "에서 " << i << " 로 이동 >> ";
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

			cout << node << "에서 " << i << " 로 이동 >> ";
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

			cout << node << "에서 " << i << " 로 이동 >> ";
			int length = spectrum[i].length();
			start_string = start_string + spectrum[i].substr(overlap, length - overlap);
			cout << start_string << endl;
			DFS_odd(i, visited, adjMat, overlap);
		}

	}
}