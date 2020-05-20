#pragma once
#include <iostream>
#include "DNA.h"
using namespace std;

void displaySolution(int path[]);
bool isSafe(int n, bool graph[8][8], int path[], int pos);
bool hamCycleUtil (bool graph[8][8], int path[], int pos);
bool hamCycle(bool graph[8][8]);
void hamilton_path(bool graph[8][8]);