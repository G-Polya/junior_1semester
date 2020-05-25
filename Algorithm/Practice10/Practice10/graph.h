#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;





int** make_adjacentMatrix(vector<string> spec, int overlap);		// 인접행렬을 생성하는 함수
void show_matrix(int** mat, int col, int row);			// 생성된 인접행렬을 출력하는 함수
void reset_visited(int* visited, int spectrum_size);	// visited 초기화
bool check_visited(int* visited, int spectrum_size);	// visited검사
bool all_false(int* row, int spectrum_size);		// 더이상 연결이 없는지 판단. 마지막 노드인지 판단.


int not_visited_index(int* visited, int size);		// 방문안한 인덱스 반환
vector<string> find_Max(vector<string> temp_DNAs);		// 최대 길이를 가진 스트링들로 구성된 vector반환