//2016112158 김희수
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <map>
#include <iomanip>
#include <algorithm>
#include <chrono>
using namespace std;


//referenceDNA를 생성하는 함수
void make_refDNA(string filename, int length)
{
	ofstream fout;		//파일객체 생성
	fout.open(filename, ios::app | ios::out);
	random_device rd;		 //시드값을 얻기 위한 random_device 생성

	mt19937 gen(rd());	// random_deivce를 통해 난수 생성 엔진을 초기화, 메르센 트위스터 알고리즘. rand가 사용했던 선형합동방식보다 좋은 난수열 생성

	uniform_int_distribution<int> distribution(0, 50000);	//0부터 99까지 균등하게 나타내는 난수열을 생성하기 위해 균등분포 정의
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


// 매개변수로 주어진 배열에서 임의의 원소를 랜덤하게 추출하는 함수
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

// string배열의 원소들을 이어붙인 string을 반환하는 함수 
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

void make_shortRead(int length, int n, string refDNA, string directory)
{
	ifstream fin;	// 읽기 파일 객체 생성
	fin.open(refDNA);
	string text;
	fin >> text;	// 읽어온 파일은 string객체에 저장

	random_device rd;	// 시드값을 얻기 위한 random_device 설정
	mt19937 gen(rd());

	uniform_int_distribution<int> dis(0, text.length() - length);		// 시작위지를 랜덤으로 설정

	uniform_int_distribution<int> sample(0, 4);	//20%확률로 뽑아올 인덱스

	for (int i = 0; i < n; i++)
	{
		ofstream fout;
		string short_Name = directory + "\\shortRead_" + to_string(i) + ".txt";	//shortRead디렉토리에 저장
		fout.open(short_Name);
		//std::cout << dis(gen) << endl;

		string temp = text.substr(dis(gen), length);	// 랜덤으로 뽑은 시작위치에서 length만큼의 서브스트링 반환

		string* splited_temp = new string[length / 5];		// 20%확률로 돌연변이가 일어나기 위해 temp를 잘라서 만든 string배열
		int size = length / 5;		// 예를 들어 length가 10이라면 splited_temp의 원소개수는 2개이다

		for (int i = 0; i < size; i++)
		{
			splited_temp[i] = temp.substr(i * (length / size), length / size);	// splited_temp에는 temp를 등분한 string이 저장됨 
		}

		//std::cout << temp << " " << splited_temp[0] << " " << splited_temp[1] << endl;

		for (int i = 0; i < size; i++)			//splited_temp의 모든 원소. 즉 temp가 등분되어 만들어진 string에 대하여
		{
			int index = sample(gen);		// 20%확률로 랜덤하게 돌연변이가 일어날 인덱스 설정

			if (splited_temp[i][index] == 'A')	// 돌연변이가 일어날 인덱스에 해당하는 문자가 A라면
			{
				char arr[3] = { 'G','C','T' };
				splited_temp[i][index] = shuffle(arr, 3);	// G,C,T 중에서 하나로 바뀜
			}
			else if (splited_temp[i][index] == 'G')
			{
				char arr[3] = { 'A','C','T' };
				splited_temp[i][index] = shuffle(arr, 3);

			}
			else if (splited_temp[i][index] == 'C')
			{
				char arr[3] = { 'A','G','T' };
				splited_temp[i][index] = shuffle(arr, 3);

			}
			else if (splited_temp[i][index] == 'T')
			{
				char arr[3] = { 'A','G','C' };
				splited_temp[i][index] = shuffle(arr, 3);

			}
		}

		string shortRead = concat(splited_temp, size);	//	돌연변이가 일어난 결과. shortRead

		//string* splited_Read = new string[size];
		//for (int i = 0; i < size; i++)
		//{
		//	splited_Read[i] = shortRead.substr(i * (length / size), length / size);
		//}

		//std::cout << shortRead << " " << splited_Read[0] << " " << splited_Read[1] << endl;
		//
		//std::cout << "============================" << endl;
		fout << shortRead << endl;
		fout.close();
	}


}

int brute_force_matching(string refDNA, string shortRead, int threshold)
{
	int M = shortRead.size();
	int N = refDNA.size();
	map<int, int> result;		// mismatch 개수를 key로 하고, 일치가 시작하는 인덱스를 value로 하는 map

	for (int i = 0; i <= N - M; i++)
	{
		int j;
		int mismatches = 0;		// 일치하지 않는 문자의 개수

		string temp = refDNA.substr(i, M);
		for (int j = 0; j < M; j++)
		{
			if (shortRead[j] != temp[j])
			{
				mismatches++;
				continue;
			}

		}
		if (mismatches < threshold)
		{
			auto pr = make_pair(mismatches, i);
			result.insert(pr);

		}
		else
		{
			auto pr = make_pair(mismatches, 0);
			result.insert(pr);
		}
	}

	vector<int> index_vector;	// map에서 index들을 뽑아오기 위한 vector

	for (auto& iter : result)
	{
		index_vector.push_back(iter.second);
	}

	int index = *max_element(begin(index_vector), end(index_vector));	// 가장 mismatch가 적은 인덱스이다.  

	return index;
}

string trivial_Mapping(string refDNA, vector<string> shortReads, int threshold)
{
	string myDNA = refDNA;	// myDNA와 refDNA는 거의 비슷하다. 
	for (auto& shortRead : shortReads)		// 각각의 shortRead에 대해서
	{
		int index = brute_force_matching(refDNA, shortRead, threshold);		// 가정 mismatch가 적은 인덱스를 가져온다. 
		for (int i = index; i < index + shortRead.length(); i++)
			myDNA[i] = shortRead[i - index];				// myDNA에서 index ~ (index+length)에 해당하는 부분을 shortRead로 바꿔준다.
	}
	return myDNA;
}

// refDNA와 myDNA를 비교하여 일치하는 정도를 반환하는 함수
double get_match_degree(string refDNA, string myDNA)
{
	int N = refDNA.size();
	int M = myDNA.size();

	int mismatches = 0;

	for (int i = 0; i <= N - M; i++)
	{
		int j;
		for (j = 0; j < M; j++)
			if (myDNA[j] != refDNA[i + j])
			{
				mismatches++;
				continue;
			}
	}



	int result = (M - mismatches) / M * 100;

	return result;
}

int main()
{
	//make_refDNA("referenceDNA.txt", 500000);				// referenceDNA를 만들때 사용
	int length = 30;
	int n = 20000;
	////make_shortRead(length, n, "referenceDNA.txt", "30_shortRead");	// shortRead들을 만들때 사용

	//length = 60;
	//n = 15000;
	//make_shortRead(length, 15000, "referenceDNA.txt", "60_shortRead");

	ifstream inDNA;
	inDNA.open("referenceDNA.txt");
	string refDNA;
	inDNA >> refDNA;

	//myDNA를 만들 때 사용
	vector<string> shortReads;		//shortRead들을 저장할 vector
	for (int i = 0; i < n; i++)
	{
		ifstream fin;
		fin.open("30_shortRead\\shortRead_" + to_string(i) + ".txt");
		string shortRead;
		fin >> shortRead;

		shortReads.push_back(shortRead);
	}

	ofstream myDNA_out;
	myDNA_out.open("myDNA.txt", ios::app | ios::out);

	cout << "myDNA : " << endl;
	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	myDNA_out << trivial_Mapping(refDNA, shortReads, 4);
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	auto elapsed_time = chrono::duration_cast<chrono::seconds>(end - start).count();
	cout << "복원 시간 : " << elapsed_time << " 초" << endl;
	myDNA_out.close();

	ifstream myDNA_in;
	myDNA_in.open("myDNA.txt");
	string myDNA;
	myDNA_in >> myDNA;


	cout << "myDNA와 refDNA의 일치하는 정도 : " << get_match_degree(refDNA, myDNA) << endl;


	return 0;
}