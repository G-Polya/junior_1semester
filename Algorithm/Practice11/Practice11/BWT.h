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
using namespace std;


class BWT
{
public:
	vector<char> BWTString;
	vector<tuple<int, string>> table;
	vector<short unsigned int> LCPVal;
	vector<unsigned int> componentIds;			// table의 번호가 들어있는 vector

	int bucketSize;
	int compSize;

	string origString;
	vector<string> LCPArray;

	void fill_table();
	void findSuperMaximalRepeats();
	void findBWT();
	void findLCPArray();
	void fillUpComponentIds();
	void Sort();
	string get_BWTString();


};

template<class T>
void print_vector(vector<T> vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;
}

