#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;





int** make_adjacentMatrix(vector<string> spec, int overlap);
void show_matrix(int** mat, int col, int row);
void reset_visited(int* visited, int spectrum_size);
bool check_visited(int* visited, int spectrum_size);
void DFS_start(int spectrum_size);
bool all_false(int* row, int spectrum_size);
int not_visited_index(int* visited, int size);
string find_Max(vector<string> restored_DNAs);