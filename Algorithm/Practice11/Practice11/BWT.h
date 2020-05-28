#pragma once
#include<stdio.h>
#include<fstream>
#include<sstream>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<math.h>
#include<conio.h>
#include <algorithm>
#include <cstring>
using namespace std;


class BWT
{
public:
	string BWTString = "";
	vector<tuple<int, string>> table;
	vector<short unsigned int> LCPVal;
	vector<unsigned int> componentIds;			// table의 번호가 들어있는 vector

	int bucketSize;
	int compSize;

	string origString;
	vector<string> LCPArray;

	void fill_table();
	void findBWT();
	void fillUpComponentIds();
	void SortTable();
	int find_dollar();
	
	void restore();

};

typedef struct node
{
	int data;
	node* next;
}node;

node* getNode(int i);
void addAtLast(node** head, node* nn);
void computeLShift(node** head, int index, int* l_shift);
string SortString(string str);

template<class T>
void print_vector(vector<T> vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;
}

