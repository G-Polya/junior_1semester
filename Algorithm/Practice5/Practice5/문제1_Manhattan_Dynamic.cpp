// 2016112158 �����
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Map ǥ��
// right: ������ ������ weight(������ ��)
// down: �Ʒ� ������ weight
typedef struct Map
{
	int right;
	int down;
} Map;


void print_Grid(Map map[][5])
{
	int grid[5][5];
	grid[0][0] = 0;

	// 0��° row �ʱ�ȭ
	for (int j = 1; j < 5; j++)
	{
		int temp = j - 1;
		grid[0][j] = grid[0][temp] + map[0][temp].right;
	}

	// 0��° column �ʱ�ȭ
	for (int i = 1; i < 5; i++)
	{
		int temp = i - 1;
		grid[i][0] = grid[temp][0] + map[temp][0].down;
	}
	
	// 0���� ����, 0���� ���� �׸��� ������ weight�� ������ ���� ������ ���� ���Ѵ�
	for (int i = 1; i < 5; i++)
		for (int j = 1; j < 5; j++)
		{
			int i_before = i - 1;		// ������ ��� �ε���
			int j_before = j - 1;		// ������ ��� �ε���
			
			if (grid[i][j_before] + map[i][j_before].right > grid[i_before][j] + map[i_before][j].down)	// ���� ��� �� + weight > ���� ��� �� + weight���  
				grid[i][j] = grid[i][j_before] + map[i][j_before].right;							// ���� ��� �� + weight�� ���� ����� ������ ����
			else
				grid[i][j] = grid[i_before][j] + map[i_before][j].down;								// ���� �ݴ�
		}


	// ���
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
	// map �ʱ�ȭ
	Map map[5][5] =
	{ { {3,1}, {2,0}, {4,2}, {0,4}, {0,3} },
	  { {3,4}, {2,6}, {4,5}, {1,2}, {0,1} },
	  { {0,4}, {7,4}, {3,5}, {4,2}, {0,1} },
	  { {3,5}, {3,6}, {0,8}, {2,5}, {0,3} },
	  { {1,0}, {3,0}, {2,0} ,{2,0}, {0,0} } };

	print_Grid(map);

	return 0;
}

