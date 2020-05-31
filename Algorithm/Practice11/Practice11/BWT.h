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
	vector<tuple<int, string>> table;			// origString�� ���� �ϳ��� �����̵��ؼ� ���� ��Ʈ������ ������ table
	vector<short unsigned int> LCPVal;
	vector<unsigned int> componentIds;			// table ������ ��ȣ�� ����ִ� vector. ��Ʈ������ ��ȣ�� ����ִ�.

	int bucketSize;
	int compSize;

	string origString;				// �Էµ� ��Ʈ��
	vector<string> LCPArray;

	void fillUpComponentIds();		// ComponetIds �ʱ�ȭ
	void fill_table();				// origString�� ���� �ϳ��� �����̵��ؼ� ���� ��Ʈ���� table�� ����
	void SortTable();				// table���� ��Ʈ������ ���ؼ� Sort. ���ĵ� ������ ���� �ο��� componetIds�鵵 ���� �̵��Ǿ���Ѵ�. 
	void findBWT();					// table���� BWTString�� ã�� �Լ�
	
	int find_dollar();
	
	void reconstruct();				// ���� ��Ʈ�� ����

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

