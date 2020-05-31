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
	string BWTString = "";						// BWTString
	vector<tuple<int, string>> table;			// origString을 문자 하나씩 슬라이드해서 만든 스트링들을 저장한 table
	vector<short unsigned int> LCPVal;
	vector<unsigned int> componentIds;			// table 원소의 번호가 들어있는 vector. 스트링들의 번호가 들어있다.

	int bucketSize;
	int compSize;

	string origString;				// 입력된 스트링
	vector<string> LCPArray;

	void fillUpComponentIds();		// ComponetIds 초기화
	void fill_table();				// origString을 문자 하나씩 슬라이드해서 만든 스트링을 table에 저장
	void SortTable();				// table안의 스트링끼리 비교해서 Sort. 정렬된 순서에 따라 부여된 componetIds들도 같이 이동되어야한다. 
	void findBWT();					// table에서 BWTString을 찾는 함수
	
	int find_dollar();
	
	void reconstruct();				// 원래 스트링 복원

};

typedef struct node
{
	int data;
	node* next;
}node;

node* getNode(int i);
void insert_toList(node** head, node* nn);
void computeLShift(node** head, int index, int* l_shift);
string SortString(string str);

template<class T>
void print_vector(vector<T> vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;
}

