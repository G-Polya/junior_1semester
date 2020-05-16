//2016112158 �����
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;


//referenceDNA�� �����ϴ� �Լ�
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

void make_shortRead(int length, int n,string refDNA,string directory)
{
	ifstream fin;	// �б� ���� ��ü ����
	fin.open(refDNA);
	string text;
	fin >> text;	// �о�� ������ string��ü�� ����

	random_device rd;	// �õ尪�� ��� ���� random_device ����
	mt19937 gen(rd());
	
	uniform_int_distribution<int> dis(0, text.length()-length);		// ���������� �������� ����

	uniform_int_distribution<int> sample(0,4);	//20%Ȯ���� �̾ƿ� �ε���

	for (int i = 0; i < n; i++)
	{
		ofstream fout;
		string short_Name = directory+"\\shortRead_" + to_string(i) + ".txt";	//shortRead���丮�� ����
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

void trivial_Mapping(string shortRead, string refDNA, int threshold)
{
	int M = shortRead.size();
	int N = refDNA.size();
	int count = 0;
	for (int i = 0; i <= N - M; i++)
	{
		int j;
		for (j = 0; j < M; j++)
			if (shortRead[j] != refDNA[i + j])
			{
				int mismatch = 0;
				mismatch++;
				if (mismatch > threshold)
				{
					cout << "Total of " << mismatch << " mismatches. Not below threshold" << endl;
					break;
				}
				else
					count = mismatch;
			}	
	}
	cout << "Total of " << count <<" mismatches. Below threshold"<< endl;
}


int main()
{
	//make_refDNA("referenceDNA.txt", 500000);
	int length = 30;
	make_shortRead(length, 20000, "referenceDNA.txt","30_shortRead");
	ifstream inDNA;
	inDNA.open("referenceDNA.txt");
	string refDNA;
	inDNA >> refDNA;
	//cout << refDNA << endl;

	string shortRead;
	for (int i = 0; i < length; i++)
	{
		ifstream fin;
		fin.open("30_shortRead\\shortRead_" + to_string(i) + ".txt");
		string shortRead;
		fin >> shortRead;
		
		trivial_Mapping(shortRead, refDNA, 3);

	}

	
}