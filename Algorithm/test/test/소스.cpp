#include <iostream>
#include <string>
#include <fstream>
#include <random>

using namespace std;
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

int main()
{
	make_refDNA("referenceDNA.txt", 500000);
}