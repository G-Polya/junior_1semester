//2016112158 �����
#include <iostream>
#include <string>
#include <random>
#include <fstream>
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

void make_shortRead(int length, int n,string refDNA)
{
	ifstream fin;	// �б� ���� ��ü ����
	fin.open(refDNA);
	string text;
	fin >> text;	// �о�� ������ string��ü�� ����

	random_device rd;	// �õ尪�� ��� ���� random_device ����
	mt19937 gen(rd());
	
	uniform_int_distribution<int> dis(0, text.length()-length);		// ���������� �������� ����

	uniform_int_distribution<int> sample(0,5);	//20%Ȯ����
	for (int i = 0; i < n; i++)
	{
		ofstream fout;
		string short_Name = "shortRead\shortRead_" + to_string(i) + ".txt";
		fout.open(short_Name);
		cout << dis(gen) << endl;
		string temp = text.substr(dis(gen), length);
		
		string splited_temp1 = temp.substr(0, length / 2);
		string splited_temp2 = temp.substr(length / 2, length / 2);
		cout << temp << " "<< splited_temp1 <<" "<< splited_temp2 << endl;
		
		switch (splited_temp1[sample(gen)])
		{
		case 'A':
			splited_temp1[sample(gen)] = 'G';
			cout << " dd " << splited_temp1 << endl;
		}

		string shortRead;
		
		
		//cout << "temp : " << temp << ", shortRead : " << shortRead << endl;
		fout << temp;
		fout.close();

	}
		

}

int main()
{
	//make_refDNA("refernceDNA.txt", 500000);
	int length = 10;
	make_shortRead(length, 30, "refernceDNA.txt");
	
	string shortRead;
	for (int i = 0; i < length; i++)
	{
		ifstream fin;
		fin.open("shortRead_" + to_string(i) + ".txt", ios::app | ios::out);
		string shortRead;
		fin >> shortRead;

	}

}