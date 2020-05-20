#pragma once

// 인접행렬을 구현하기 위한 헤더
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;


void show_matrix(bool** mat, int col, int row);

bool** make_adjacentMatrix(vector<string> spectrum);

void show_matrix(bool mat[][8], int col, int row);