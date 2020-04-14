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

// find path greedily
void get_path_greedy(Map map[][5])
{
	
	int col = 0;
	int row = 0;
	cout << "Start Point: Map[" << row << "][" << col << "]\n" << endl;

	Map current_loc = map[col][row];	// ���� ��ġ
	int spot_sum = 0;		// �ѷ��� �������� ������

	cout << "�̵� ���: " << endl;
	// parameter�� map�� (col_size-1) + (row_size+1) = 8
	for(int i = 0 ; i < 8; i++)
	{
		
		if (current_loc.right > current_loc.down)		// �Ʒ��� ����, ���������� ���� ����
		{
			spot_sum += current_loc.right;
			current_loc = map[col][++row];		// �����ʿ� �������� �� ���ٸ� ������ġ�� ����������
		}
		else
		{
			spot_sum += current_loc.down;
			current_loc = map[++col][row];		// �Ʒ��ʿ� �������� �� ���ٸ� ������ġ�� �Ʒ�������
		}

		cout << setw(17)<<"Map["<<row << "][" << col <<"]"<< endl;		// �̵���� ���
	}
	
	cout << "\n�ѷ��� �������� ����: " << spot_sum << endl;
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

	get_path_greedy(map);

	return 0;
}