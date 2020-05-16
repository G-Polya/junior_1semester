//2016112158 �����
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

void make_refDNA(string filename,int length)
{
	ofstream fout;		//���ϰ�ü ����
	fout.open(filename, ios::app | ios::out);
	random_device rd;		 //�õ尪�� ��� ���� random_device ����

	mt19937 gen(rd());	// random_deivce�� ���� ���� ���� ������ �ʱ�ȭ, �޸��� Ʈ������ �˰���. rand�� ����ߴ� �����յ���ĺ��� ���� ������ ����

	uniform_int_distribution<int> distribution(0, 99);	//0���� 99���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ���� ����
	for (int i = 0; i < length; i++)
	{
		if (distribution(gen) % 4 == 0)
			fout << 'A';
		else if (distribution(gen) % 4 == 1)
			fout << 'G';
		else if (distribution(gen) % 4 == 2)
			fout << 'T';
		else if (distribution(gen) % 4 == 3)
			fout << 'C';
	}

	fout.close();
}

template <typename T>
T shuffle(T arr[], int num)
{
	srand((unsigned int)time(NULL));
	T temp;
	int rn;
	for (int i = 0; i < num - 1; i++)
	{
		rn = rand() % (num - i) + i;
		temp = arr[i];
		arr[i] = arr[rn];
		arr[rn] = temp;
	}

	return temp;
}

string concat(string strArr[], int size)
{
	string result;

	queue<string> q;
	for (int i = 0; i < size; i++)
		q.push(strArr[i]);

	while (!q.empty())
	{
		result += q.front();
		q.pop();
	}

	return result;
}

void make_shortRead(int length, int n,string refDNA)
{
	ifstream fin;	// �б� ���� ��ü ����
	fin.open(refDNA);
	string text;
	fin >> text;	// �о�� ������ string��ü�� ����

	random_device rd;	// �õ尪�� ��� ���� random_device ����
	mt19937 gen(rd());
	
	uniform_int_distribution<int> dis(0, text.length()-length);		// ���������� �������� ����

	uniform_int_distribution<int> sample(0,4);	//20%Ȯ����

	for (int i = 0; i < n; i++)
	{
		ofstream fout;
		string short_Name = "shortRead\shortRead_" + to_string(i) + ".txt";
		fout.open(short_Name);
		std::cout << dis(gen) << endl;
		string temp = text.substr(dis(gen), length);

		string* splited_temp = new string[length / 5];
		int size = length / 5;

		for (int i = 0; i < size; i++)
		{
			splited_temp[i] = temp.substr(i * (length / size), length / size);
		}

		std::cout << temp << " " << splited_temp[0] << " " << splited_temp[1] << endl;

		for (int i = 0; i < size; i++)
		{
			switch (splited_temp[i][sample(gen)])
			{
			case 'A':
			{
				char arr[3] = { 'G','C','T' };
				std::cout << sample(gen) << endl;
				std::cout << splited_temp[i][sample(gen)] << endl;
				splited_temp[i][sample(gen)] = shuffle(arr, 3);
				continue;
			}
			case 'G':
			{
				char arr[3] = { 'A','C','T' };
				splited_temp[i][sample(gen)] = shuffle(arr, 3);
				continue;
			}
			case 'C':
			{
				char arr[3] = { 'A','G','T' };
				splited_temp[i][sample(gen)] = shuffle(arr, 3);
				continue;
			}
			case 'T':
			{
				char arr[3] = { 'A','C','G' };
				splited_temp[i][sample(gen)] = shuffle(arr, 3);
				continue;
			}

			}
		}
		//std::cout << temp << " " << splited_temp[0] << " " << splited_temp[1] << endl;
		
		string shortRead = concat(splited_temp, size);
		string* splited_Read = new string[size];
		for (int i = 0; i < size; i++)
		{
			splited_Read[i] = shortRead.substr(i * (length / size), length / size);
		}
		std::cout << shortRead<< " " << splited_Read[0] << " " << splited_Read[1] << endl;

		std::cout << "==============================" << endl;
		
		
	}
}


int main()
{
	//make_refDNA("refernceDNA.txt", 500000);
	int length = 10;
	make_shortRead(length, 30, "refernceDNA.txt");
	//
	//string shortRead;
	//for (int i = 0; i < length; i++)
	//{
	//	ifstream fin;
	//	fin.open("shortRead_" + to_string(i) + ".txt", ios::app | ios::out);
	//	string shortRead;
	//	fin >> shortRead;

	//}

	string strArr[] = { "1","23","4562" };
	string result = concat(strArr, 3);
	
}