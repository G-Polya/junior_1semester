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
#include <chrono>
#include <ctime>
using namespace std;


// brute force로 스트링 매칭
// text : 텍스트, pattern : 패턴
void brute_force_matching(string text, string pattern, string output_name)
{
	ofstream fout;	// 패턴을 찾은 결과가 입력되는 파일객체
	fout.open(output_name, ios::app | ios::out);

	ofstream time_stamp;	// 소요시간이 입력되는 파일객체
	time_stamp.open("timeStamp_" + output_name, ios::app | ios::out);
	chrono::steady_clock::time_point start = chrono::steady_clock::now();

	size_t M = pattern.size();
	size_t N = text.size();
	//cout << "brute foce M " << M << endl;
	for (size_t i = 0; i <= N - M; i++)		// 텍스트크기 - 패턴크기만큼 앞으로 슬라이드 될 것
	{
		size_t j;
		for (j = 0; j < M; j++)				// 패턴의 각 문자에 대해서
			if (pattern[j] != text[i + j])	// 패턴의 문자와 텍스트의 문자가 같지않으면 break되고 한문자만큼 슬라이드
				break;
		if (j == M)
		{
			cout << "(Brute Force)" << pattern << " 패턴이 텍스트의 " << i + 1 << "번쨰부터 나타남" << endl;
			fout << "(Brute Force)" << pattern << " 패턴이 텍스트의 " << i + 1 << "번쨰부터 나타남" << endl;

		}
	}
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	auto elapsed_time = chrono::duration_cast<chrono::seconds>(end - start).count();
	time_stamp << "To find " << pattern << " : Elapsed time of Brute-Force matching : " << (double)elapsed_time / 1000000 << "초" << endl << endl;

	time_stamp.close();
	fout.close();
}


//
// q: 해시함수에 의해 결정되는 mod를 위한 제수
void rabin_karp_matching(string text, string pattern, int q, string output_name)
{
	ofstream fout;	// 패턴을 찾은 결과가 입력되는 파일객체
	fout.open(output_name, ios::app | ios::out);

	ofstream time_stamp;	// 소요시간이 입력되는 파일객체
	time_stamp.open("timeStamp_" + output_name, ios::app | ios::out);
	chrono::steady_clock::time_point start = chrono::steady_clock::now();


	const size_t d = 10; // 진수
	const size_t M = pattern.size();
	const size_t N = text.size();
	size_t p = 0;		// pattern을 위한 hash 값
	size_t t = 0;		// text를 위한 hash값
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
				cout << "(Rabin-Karp)" << pattern << " 패턴이 텍스트의 " << i + 1 << "번쨰부터 나타남" << endl;
				fout << "(Rabin-Karp)" << pattern << " 패턴이 텍스트의 " << i + 1 << "번쨰부터 나타남" << endl;
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

	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	auto elapsed_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
	time_stamp << "To find " << pattern << " : Elapsed time of Rabin-Karp matching : " << (double)elapsed_time / 1000000 << "초" << endl << endl;

	time_stamp.close();

	fout.close();

}


void computeSP(string pattern, size_t SP[])
{


	size_t  j = 0;
	size_t  M = pattern.size();
	SP[0] = 0;



	// SP[i]를 채우기 위한 계산 
	int i = 1;
	while (i < M)
	{
		if (pattern[i] == pattern[j])	// pattern의 i번째 인덱스와 j번째 인덱스를 비교해서 같으면
		{
			j++;
			SP[i] = j;		// j을 증가시켜 SP[i]에 저장
			i++;
		}
		else
		{
			if (j != 0)		// j이 0이 아니면
				j = SP[j - 1];	 // j은 한칸 뒤로
			else
			{
				SP[i] = 0;
				i++;
			}
		}
	}
}

void KMP_matching(string text, string pattern, string output_name)
{
	ofstream fout;	// 패턴을 찾은 결과가 입력되는 파일객체
	fout.open(output_name, ios::app | ios::out);

	ofstream time_stamp;	// 소요시간이 입력되는 파일객체
	time_stamp.open("timeStamp_" + output_name, ios::app | ios::out);
	chrono::steady_clock::time_point start = chrono::steady_clock::now();



	size_t  M = pattern.size();
	size_t N = text.size();

	size_t* SP = new size_t[M];

	computeSP(pattern, SP);

	size_t  i = 0;	// text를 위한 index
	size_t  j = 0;  // pattern을 위한 인덱스

	while (i < N)
	{
		if (pattern[j] == text[i])	// pattern과 text가 일치하는 동안엔 그냥 넘어간다. 
		{
			j++;
			i++;
		}

		if (j == M)	// pattern을 위한 인덱스가 패턴의 길이와 같다는 건, text안에 패턴이 존재한다는 걸 의미
		{
			cout << "(KMP) " << pattern << " 패턴이 텍스트의 " << i - j + 1 << "번쨰부터 나타남" << endl;
			fout << "(KMP) " << pattern << " 패턴이 텍스트의 " << i - j + 1 << "번쨰부터 나타남" << endl;

			j = SP[j - 1];
		}
		else if (i < N && pattern[j] != text[i])	// pattern과 text가 같지 않을때 뒤로 이동해서 text의 suffix/pattern의 prefix 다음의 문자를 비교
		{
			if (j != 0)
				j = SP[j - 1];
			else
				i = i + 1;
		}
	}

	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	auto elapsed_time = chrono::duration_cast<chrono::microseconds>(end - start).count();
	time_stamp << "To find " << pattern << " : Elapsed time of KMP matching : " << (double)elapsed_time / 1000000 << "초" << endl << endl;
	time_stamp.close();

	fout.close();

	delete SP;
}


void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i];
	cout << endl;
}

// random pattern 생성 함수
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

// 파일을 읽어와서 스트링매칭을 수행하는 함수
void get_result(string filename)
{
	ifstream inFile;

	cout << filename << " :" << endl;

	inFile.open(filename);
	string text;
	inFile >> text;

	string real_pattern;
	for (size_t length = 10; length <= 30; length += 5)
	{
		real_pattern = text.substr(0, length);

		string br_output_name = "brute_force_" + filename;
		string rk_output_name = "rabin_karp_" + filename;
		string kmp_outpunt_name = "kmp_" + filename;
		brute_force_matching(text, real_pattern, br_output_name);
		rabin_karp_matching(text, real_pattern, 2, rk_output_name);
		KMP_matching(text, real_pattern, kmp_outpunt_name);
	}
	inFile.close();
}

// 주어진 길이만큼의 string을 생성하여 파일에 입력하는 함수
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

// dest : 결과로 만들어지는 txt파일
// source : 추출해올 txt파일
// size : 결과파일안의 스트링 크기
void extract(string dest, int size)
{
	ifstream inFile; // 100,000,000.txt를 읽어올 객체
	inFile.open("100,000,000.txt");
	string temp_text;
	inFile >> temp_text;

	string result_text = temp_text.substr(0, size);	// 길이size인 substring. 반드시 100,000,000.txt안에 존재

	ofstream outFile; // result_text를 입력할 객체
	outFile.open(dest);
	outFile << result_text;

	outFile.close();
	inFile.close();

}

int main()
{
	srand((unsigned int)time(NULL));

	make_text_file("100,000,000.txt", 100000000);

	extract("10,000.txt", 10000);
	extract("100,000.txt", 100000);
	extract("1,000,000.txt", 1000000);
	extract("10,000,000.txt", 10000000);




	get_result("10,000.txt");
	get_result("100,000.txt");
	get_result("1,000,000.txt");
	get_result("10,000,000.txt");
	get_result("100,000,000.txt");

}