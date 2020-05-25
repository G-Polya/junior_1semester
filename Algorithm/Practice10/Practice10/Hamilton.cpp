#include "Hamilton.h"
#include "graph.h"

void Hamilton::DFS_start(int* visited, int** adjMat,int overlap)
{
	vector<string> restored_DNAs;
	int length = spectrum[0].length();
	int size = spectrum.size();
	for (int i = 0; i < size; i++)
	{
		cout << i << " 번째에서 시작" << endl;
		start_string = spectrum[i];
		DFS(i, visited, adjMat,overlap);

		int index = not_visited_index(visited,size);
		string temp = spectrum[index];
		start_string += spectrum[index].substr(overlap, length-overlap);
		cout <<"끝으로 이동 >> " <<start_string << endl;
		restored_DNAs.push_back(start_string);



		reset_visited(visited, size);

		start_string = "";
		cout << endl;
	}

	if (restored_DNAs.size() != 0)
	{
		for (int i = 0; i < restored_DNAs.size(); i++)
		{
			
			cout << "결과 : " << restored_DNAs[i] << endl;
		}
		cout << endl;
		cout << "복원된 DNA : " << find_Max(restored_DNAs) << endl;
		
	}
	else
		cout << "no string" << endl;
}

void Hamilton::DFS(int node, int* visited, int** adjMat,int overlap)
{
	visited[node] = 1;
	int size = spectrum.size();
	for (int i = 0; i < size; i++)
	{
		if (all_false(adjMat[node], size))
			visited[node] = 0;

		if ((visited[i] == 0) && ((adjMat[node][i] == 1)) && !all_false(adjMat[i],size))
		{
	
			cout << node << "에서 " << i << " 로 이동 >> " ;
			int length = spectrum[i].length();
			start_string = start_string + spectrum[i].substr(overlap, length-overlap);
			cout << start_string << endl;
			DFS(i,visited,adjMat,overlap);	
		}
		
	}


}
