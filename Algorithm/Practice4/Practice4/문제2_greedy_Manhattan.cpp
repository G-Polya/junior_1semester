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

// find path greedily
void get_path_greedy(Map map[][5])
{
	
	int col = 0;
	int row = 0;
	cout << "Start Point: Map[" << row << "][" << col << "]\n" << endl;

	Map current_loc = map[col][row];	// 현재 위치
	int spot_sum = 0;		// 둘러본 관광지의 누적합

	cout << "이동 경로: " << endl;
	// parameter인 map의 (col_size-1) + (row_size+1) = 8
	for(int i = 0 ; i < 8; i++)
	{
		
		if (current_loc.right > current_loc.down)		// 아래로 갈지, 오른쪽으로 갈지 선택
		{
			spot_sum += current_loc.right;
			current_loc = map[col][++row];		// 오른쪽에 관광지가 더 많다면 현재위치를 오른쪽으로
		}
		else
		{
			spot_sum += current_loc.down;
			current_loc = map[++col][row];		// 아래쪽에 관광지가 더 많다면 현재위치를 아래쪽으로
		}

		cout << setw(17)<<"Map["<<row << "][" << col <<"]"<< endl;		// 이동경로 출력
	}
	
	cout << "\n둘러본 관광지의 개수: " << spot_sum << endl;
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

	get_path_greedy(map);

	return 0;
}