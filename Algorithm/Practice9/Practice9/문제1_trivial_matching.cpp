//2016112158 �����
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


//referenceDNA�� �����ϴ� �Լ�
void make_refDNA(string filename, int length)
{
	ofstream fout;		//���ϰ�ü ����
	fout.open(filename, ios::app | ios::out);
	random_device rd;		 //�õ尪�� ��� ���� random_device ����

	mt19937 gen(rd());	// random_deivce�� ���� ���� ���� ������ �ʱ�ȭ, �޸��� Ʈ������ �˰���. rand�� ����ߴ� �����յ���ĺ��� ���� ������ ����

	uniform_int_distribution<int> distribution(0, 50000);	//0���� 99���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ���� ����
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


// �Ű������� �־��� �迭���� ������ ���Ҹ� �����ϰ� �����ϴ� �Լ�
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

// string�迭�� ���ҵ��� �̾���� string�� ��ȯ�ϴ� �Լ� 
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
	ifstream fin;	// �б� ���� ��ü ����
	fin.open(refDNA);
	string text;
	fin >> text;	// �о�� ������ string��ü�� ����

	random_device rd;	// �õ尪�� ��� ���� random_device ����
	mt19937 gen(rd());

	uniform_int_distribution<int> dis(0, text.length() - length);		// ���������� �������� ����

	uniform_int_distribution<int> sample(0, 4);	//20%Ȯ���� �̾ƿ� �ε���

	for (int i = 0; i < n; i++)
	{
		ofstream fout;
		string short_Name = directory + "\\shortRead_" + to_string(i) + ".txt";	//shortRead���丮�� ����
		fout.open(short_Name);
		//std::cout << dis(gen) << endl;

		string temp = text.substr(dis(gen), length);	// �������� ���� ������ġ���� length��ŭ�� ���꽺Ʈ�� ��ȯ

		string* splited_temp = new string[length / 5];		// 20%Ȯ���� �������̰� �Ͼ�� ���� temp�� �߶� ���� string�迭
		int size = length / 5;		// ���� ��� length�� 10�̶�� splited_temp�� ���Ұ����� 2���̴�

		for (int i = 0; i < size; i++)
		{
			splited_temp[i] = temp.substr(i * (length / size), length / size);	// splited_temp���� temp�� ����� string�� ����� 
		}

		//std::cout << temp << " " << splited_temp[0] << " " << splited_temp[1] << endl;

		for (int i = 0; i < size; i++)			//splited_temp�� ��� ����. �� temp�� ��еǾ� ������� string�� ���Ͽ�
		{
			int index = sample(gen);		// 20%Ȯ���� �����ϰ� �������̰� �Ͼ �ε��� ����

			if (splited_temp[i][index] == 'A')	// �������̰� �Ͼ �ε����� �ش��ϴ� ���ڰ� A���
			{
				char arr[3] = { 'G','C','T' };
				splited_temp[i][index] = shuffle(arr, 3);	// G,C,T �߿��� �ϳ��� �ٲ�
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

		string shortRead = concat(splited_temp, size);	//	�������̰� �Ͼ ���. shortRead

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
	map<int, int> result;		// mismatch ������ key�� �ϰ�, ��ġ�� �����ϴ� �ε����� value�� �ϴ� map

	for (int i = 0; i <= N - M; i++)
	{
		int j;
		int mismatches = 0;		// ��ġ���� �ʴ� ������ ����

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

	vector<int> index_vector;	// map���� index���� �̾ƿ��� ���� vector

	for (auto& iter : result)
	{
		index_vector.push_back(iter.second);
	}

	int index = *max_element(begin(index_vector), end(index_vector));	// ���� mismatch�� ���� �ε����̴�.  

	return index;
}

string trivial_Mapping(string refDNA, vector<string> shortReads, int threshold)
{
	string myDNA = refDNA;	// myDNA�� refDNA�� ���� ����ϴ�. 
	for (auto& shortRead : shortReads)		// ������ shortRead�� ���ؼ�
	{
		int index = brute_force_matching(refDNA, shortRead, threshold);		// ���� mismatch�� ���� �ε����� �����´�. 
		for (int i = index; i < index + shortRead.length(); i++)
			myDNA[i] = shortRead[i - index];				// myDNA���� index ~ (index+length)�� �ش��ϴ� �κ��� shortRead�� �ٲ��ش�.
	}
	return myDNA;
}

// refDNA�� myDNA�� ���Ͽ� ��ġ�ϴ� ������ ��ȯ�ϴ� �Լ�
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
	//make_refDNA("referenceDNA.txt", 500000);				// referenceDNA�� ���鶧 ���
	int length = 30;
	int n = 20000;
	////make_shortRead(length, n, "referenceDNA.txt", "30_shortRead");	// shortRead���� ���鶧 ���

	//length = 60;
	//n = 15000;
	//make_shortRead(length, 15000, "referenceDNA.txt", "60_shortRead");

	ifstream inDNA;
	inDNA.open("referenceDNA.txt");
	string refDNA;
	inDNA >> refDNA;

	//myDNA�� ���� �� ���
	vector<string> shortReads;		//shortRead���� ������ vector
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
	cout << "���� �ð� : " << elapsed_time << " ��" << endl;
	myDNA_out.close();

	ifstream myDNA_in;
	myDNA_in.open("myDNA.txt");
	string myDNA;
	myDNA_in >> myDNA;


	cout << "myDNA�� refDNA�� ��ġ�ϴ� ���� : " << get_match_degree(refDNA, myDNA) << endl;


	return 0;
}