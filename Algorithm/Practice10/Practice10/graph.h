#pragma once
#include "DNA.h"

// 인접행렬을 구현하기 위한 헤더
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;





int** make_adjacentMatrix(vector<string> spec);
void show_matrix(int** mat, int col, int row);
void reset_visited(int* visited, int spectrum_size);
bool check_visited(int* visited, int spectrum_size);
void DFS_start(int spectrum_size);
bool all_false(int* row, int spectrum_size);
int not_visited_index(int* visited);