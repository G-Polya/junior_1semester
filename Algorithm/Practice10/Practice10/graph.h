#pragma once
#include "DNA.h"

// 인접행렬을 구현하기 위한 헤더
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;





int** make_adjacentMatrix(vector<DNA> spec);
int** make_adjacentMatrix(vector<tuple<string, int>> spec);

void show_matrix(int** mat, int col, int row);
void show_matrix(int mat[][8], int col, int row);
void show_matrix(vector<vector<int>> mat);

vector<vector<int>> vector_Matrix(int** graph, int col, int row);
vector<vector<int>> vector_Matrix(int graph[8][8], int col, int row);
vector<vector<int>> convert_toList(vector<vector<int>> mat);

void print_adjList(vector<vector<int>> adjlist);
void print_adjList(vector<vector<int>> adjList, vector<tuple<string, int>> spec);

