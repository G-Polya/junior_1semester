// 2016112158 김희수
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Map 표현
// right: 오른쪽 간선의 weight(관광지 수)
// down: 아래 간선의 weight
typedef struct Map
{
	int right;
	int down;
} Map;


void print_Grid(Map map[][5])
{
	int grid[5][5];
	grid[0][0] = 0;

	// 0번째 row 초기화
	for (int j = 1; j < 5; j++)
	{
		int temp = j - 1;
		grid[0][j] = grid[0][temp] + map[0][temp].right;
	}

	// 0번째 column 초기화
	for (int i = 1; i < 5; i++)
	{
		int temp = i - 1;
		grid[i][0] = grid[temp][0] + map[temp][0].down;
	}
	
	// 0행의 값들, 0행의 값들 그리고 간선의 weight를 가져서 남은 노드들의 값을 정한다
	for (int i = 1; i < 5; i++)
		for (int j = 1; j < 5; j++)
		{
			int i_before = i - 1;		// 위쪽의 노드 인덱스
			int j_before = j - 1;		// 왼쪽의 노드 인덱스
			
			if (grid[i][j_before] + map[i][j_before].right > grid[i_before][j] + map[i_before][j].down)	// 왼쪽 노드 값 + weight > 위쪽 노드 값 + weight라면  
				grid[i][j] = grid[i][j_before] + map[i][j_before].right;							// 왼쪽 노드 값 + weight를 현재 노드의 값으로 설정
			else
				grid[i][j] = grid[i_before][j] + map[i_before][j].down;								// 위의 반대
		}


	// 출력
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(5) <<grid[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	// map 초기화
	Map map[5][5] =
	{ { {3,1}, {2,0}, {4,2}, {0,4}, {0,3} },
	  { {3,4}, {2,6}, {4,5}, {1,2}, {0,1} },
	  { {0,4}, {7,4}, {3,5}, {4,2}, {0,1} },
	  { {3,5}, {3,6}, {0,8}, {2,5}, {0,3} },
	  { {1,0}, {3,0}, {2,0} ,{2,0}, {0,0} } };

	print_Grid(map);

	return 0;
}

