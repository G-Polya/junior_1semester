// 2016112158 김희수
#include <iostream>
#include <vector>

using namespace std;

// Map 표현
// right: 오른쪽 간선의 weight
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
	cout << "Start Point: Map[" << row << "][" << col << "]" << endl;

	Map current_loc = map[col][row];	// 현재 위치
	
	
	for (int i = 0; i < 8; i++)					
	{
		if (current_loc.right >= current_loc.down)
		{
			current_loc = map[col][++row];
			
		}
		else
		{
			current_loc = map[++col][row];	
		}

		cout << "Map["<<row << "][" << col <<"]"<< endl;
	}
	
	
}


int main()
{
	Map map[5][5] =
	{ { {3,1}, {2,0}, {4,2}, {0,4}, {0,3} },
	  { {3,4}, {2,6}, {4,5}, {1,2}, {0,1} },
	  { {0,4}, {7,4}, {3,5}, {4,2}, {0,1} },
	  { {3,5}, {3,6}, {0,8}, {2,5}, {0,3} },
	  { {1,0}, {3,0}, {2,0} ,{2,0}, {0,0} } };

	get_path_greedy(map);

	return 0;
}