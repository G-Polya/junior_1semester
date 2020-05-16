//2016112158 김희수
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
	ofstream fout;		//파일객체 생성
	fout.open(filename, ios::app | ios::out);
	random_device rd;		 //시드값을 얻기 위한 random_device 생성

	mt19937 gen(rd());	// random_deivce를 통해 난수 생성 엔진을 초기화, 메르센 트위스터 알고리즘. rand가 사용했던 선형합동방식보다 좋은 난수열 생성

	uniform_int_distribution<int> distribution(0, 99);	//0부터 99까지 균등하게 나타내는 난수열을 생성하기 위해 균등분포 정의
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
	ifstream fin;	// 읽기 파일 객체 생성
	fin.open(refDNA);
	string text;
	fin >> text;	// 읽어온 파일은 string객체에 저장

	random_device rd;	// 시드값을 얻기 위한 random_device 설정
	mt19937 gen(rd());
	
	uniform_int_distribution<int> dis(0, text.length()-length);		// 시작위지를 랜덤으로 설정

	uniform_int_distribution<int> sample(0,4);	//20%확률로

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