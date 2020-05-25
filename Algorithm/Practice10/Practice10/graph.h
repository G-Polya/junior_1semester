#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;





int** make_adjacentMatrix(vector<string> spec, int overlap);		// ��������� �����ϴ� �Լ�
void show_matrix(int** mat, int col, int row);			// ������ ��������� ����ϴ� �Լ�
void reset_visited(int* visited, int spectrum_size);	// visited �ʱ�ȭ
bool check_visited(int* visited, int spectrum_size);	// visited�˻�
bool all_false(int* row, int spectrum_size);		// ���̻� ������ ������ �Ǵ�. ������ ������� �Ǵ�.


int not_visited_index(int* visited, int size);		// �湮���� �ε��� ��ȯ
vector<string> find_Max(vector<string> temp_DNAs);		// �ִ� ���̸� ���� ��Ʈ����� ������ vector��ȯ