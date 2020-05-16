//2016112158 김희수
#include <iostream>
#include <string>
#include <random>
#include <fstream>
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

void make_shortRead(int length, int n,string refDNA)
{
	ifstream fin;	// 읽기 파일 객체 생성
	fin.open(refDNA);
	string text;
	fin >> text;	// 읽어온 파일은 string객체에 저장

	random_device rd;	// 시드값을 얻기 위한 random_device 설정
	mt19937 gen(rd());
	
	uniform_int_distribution<int> dis(0, text.length()-length);		// 시작위지를 랜덤으로 설정

	uniform_int_distribution<int> sample(0,5);	//20%확률로
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