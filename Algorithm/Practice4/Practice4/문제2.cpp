// 2016112158 ±èÈñ¼ö
#include <iostream>

using namespace std;

typedef struct Map
{
	int right;
	int down;
} Map;

void get_path(Map map[][5])
{
	int current_x = 0;
	int current_y = 0;
	Map current_loc = map[current_y][current_x];
	
	cout << current_loc.right << " " << current_loc.down << endl;

	if (current_loc.right >= current_loc.down)
	{
		current_x += 1;
		current_loc = map[current_y][current_x];
	}
	else
		current_loc = map[++current_y][current_x];
	

	cout << current_x<< " " << current_y << endl;

	if (current_loc.right >= current_loc.down)
	{
		current_x += 1;
		current_loc = map[current_y][current_x];
	}
	else
		current_loc = map[++current_y][current_x];

	cout << current_x << " " << current_y << endl;

	cout << current_x<< " " << current_y << endl;

	if (current_loc.right >= current_loc.down)
	{
		current_x += 1;
		current_loc = map[current_y][current_x];
	}
	else
		current_loc = map[++current_y][current_x];

	cout << current_x << " " << current_y << endl;

}


int main()
{
	Map map[5][5] =
	{ { {3,1}, {2,0}, {4,2}, {0,4}, {0,3} },
	  { {3,4}, {2,6}, {4,5}, {1,2}, {0,1} },
	  { {0,4}, {7,4}, {3,5}, {4,2}, {0,1} },
	  { {3,5}, {3,6}, {0,8}, {2,5}, {0,3} },
	  { {1,0}, {3,0}, {2,0} ,{2,0}, {0,0} } };

	get_path(map);


}