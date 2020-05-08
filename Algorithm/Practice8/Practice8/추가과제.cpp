//2016112158 김희수
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
using namespace std;


// brute force로 스트링 매칭
// text : 텍스트, pattern : 패턴
void brute_force_matching(string text, string pattern)
{
	size_t M = pattern.size();
	size_t N = text.size();
	cout << "brute foce M " << M << endl;
	for (size_t i = 0; i <= N - M; i++)		// 텍스트크기 - 패턴크기만큼 앞으로 슬라이드 될 것
	{
		size_t j;
		for (j = 0; j < M; j++)				// 패턴의 각 문자에 대해서
			if (pattern[j] != text[i + j])	// 패턴의 문자와 텍스트의 문자가 같지않으면 break되고 한문자만큼 슬라이드
				break;
		if (j == M)
			cout << "(Brute Force)패턴이 텍스트의 " << i + 1 << "번쨰부터 나타남" << endl;
	}
}


//
// q: 해시함수에 의해 결정되는 mod를 위한 제수
void rabin_karp_matching(string text, string pattern, int q)
{
	const size_t d = 10; // [0~9]+[a-z] = 10 +_ 26 = 36. 
	const size_t M = pattern.size();
	const size_t N = text.size();
	size_t p = 0;		// pattern을 위한 hash 값
	size_t t = 0;
	int i, j;
	int h = 1;

	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;


	// 호너방법을 통한 p,t계산
	for (i = 0; i < M; i++)
	{
		p = (d * p + pattern[i]) % q;
		t = (d * t + text[i]) % q;
	}

	// 하나씩 슬라이드해가며 패턴 찾기
	for (i = 0; i < N - M + 1; i++)
	{

		if (p == t)	// hash값이 동일한 경우에 한해 세부 패턴 매칭진행
		{
			for (j = 0; j < M; j++)
				if (text[i + j] != pattern[j])
					break;

			//p == t이고 pattern[0...M-1] == text[i...i+M-1]이면 
			if (j == M)
			{
				cout << "(Rabin-Karp) 패턴이 텍스트의 " << i + 1 << "번쨰부터 나타남" << endl;
			}

		}
		// 점화식을 이용한 다음 t값 계산
		if (i < N - M)
		{
			t = (d * (t - text[i] * h) + text[i + M]) % q;

			if (t < 0)
				t = t + q;
		}
	}

}


void computeSP(string pattern, size_t SP[])
{
	size_t  len = 0;
	size_t  M = pattern.size();
	SP[0] = 0;



	// SP[i]를 채우기 위한 계산 
	int i = 1;
	while (i < M)
	{
		if (pattern[i] == pattern[len])
		{
			len++;
			SP[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
				len = SP[len - 1];
			else
			{
				SP[i] = 0;
				i++;
			}
		}
	}
}

void KMP_matching(string text, string pattern)
{
	size_t  M = pattern.size();
	size_t N = text.size();

	size_t* SP = new size_t[M];

	computeSP(pattern, SP);

	size_t  i = 0;	// text를 위한 index
	size_t  j = 0;  // pattern을 위한 인덱스

	while (i < N)
	{
		if (pattern[j] == text[i])
		{
			j++;
			i++;
		}

		if (j == M)
		{
			cout << "(KMP) 패턴이 텍스트의 " << i - j + 1 << "번쨰부터 나타남" << endl;
			j = SP[j - 1];
		}
		else if (i < N && pattern[j] != text[i])
		{
			if (j != 0)
				j = SP[j - 1];
			else
				i = i + 1;
		}
	}

	delete SP;
}


void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i];
	cout << endl;
}


string get_rand_pattern(int size)
{
	char* temp_pattern = new char[size];

	for (int i = 0; i < size; i++)
	{
		temp_pattern[i] = (char)(rand() % 10) + '0';
	}

	string random_pattern;
	for (size_t i = 0; i < size; i++)
		random_pattern += temp_pattern[i];

	delete temp_pattern;
	return random_pattern;
}

void get_result(string filename)
{
	ifstream inFile;

	cout << filename << " :" << endl;

	inFile.open(filename);
	string text;
	inFile >> text;

	string pattern;
	for (size_t length = 5; length <= 30; length += 5)
	{
		pattern = get_rand_pattern(length);
		cout << pattern << endl;
		brute_force_matching(text, pattern);
		rabin_karp_matching(text, pattern, 13);
		KMP_matching(text, pattern);
	}
	inFile.close();
}

void make_text_file(string filename, int size)
{
	ofstream outFile;
	outFile.open(filename);
	for (size_t i = 0; i < size; i++)
	{
		size_t  rand_number = rand() % 10;
		outFile << rand_number;
	}

	outFile.close();
}


int main()
{
	srand((unsigned int)time(NULL));

	//make_text_file("10,000.txt", 10000);
	//make_text_file("100,000.txt", 100000);
	//make_text_file("1,000,000.txt", 1000000);
	//make_text_file("10,000,000.txt", 10000000);
	//make_text_file("100,000,000.txt", 100000000);

	get_result("10,000.txt");
	get_result("100,000.txt");
	get_result("1,000,000.txt");
	//get_result("10,00,000.txt");
	//get_result("100,000,000.txt");

}