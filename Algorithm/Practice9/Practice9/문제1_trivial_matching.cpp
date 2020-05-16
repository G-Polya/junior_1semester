//2016112158 ±èÈñ¼ö
#include <iostream>
#include <string>
#include <random>
#include <fstream>
using namespace std;

void make_refDNA(string filename,int length)
{
	ofstream fout;
	fout.open(filename, ios::app | ios::out);
	random_device rd;

	mt19937 gen(rd());

	uniform_int_distribution<int> distribution(0, 99);
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
	make_refDNA("refernceDNA.txt", 500000);
}