// 2016112158 김희수
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// 비순환 회문 판별 알고리즘
bool check_palindrome(string input)
{
	char* arr = new char[input.size() + 1];				// 판별하고자 하는 문장(input)을 임시로 저장할 배열 arr
	strcpy_s(arr, input.size()+1, input.c_str());
	bool check = true;

	for (int i = 0; i < strlen(arr) / 2; i++)			// 처음부터 시작해서
	{
		if (arr[i] != arr[strlen(arr) - i - 1])			// 대칭적으로 비교한다
		{
			check = false;
			break;
		}
	}
	delete[] arr;
	arr = NULL;

	return check;
}

// 순환 회문 판별 알고리즘
bool recursive_check(string input)
{
	bool check = true;
	
	char* arr = new char[input.size() + 1];
	
	if (input.size() <= 1)								// 문장이 길이가 1이라면, 즉 문자하나 자체는 회문이다
		return true;
	
	if (input.substr(0, 1) != input.substr(input.size() - 1))		//처음 단어와 끝단어가 같지 않으면 false
		return false;

	return recursive_check(input.substr(1, input.size() - 2));		// 재귀적으로 반복
}

int main()
{
	ifstream in("exam_palindrome.txt");			//파일 읽어오기
	string input;

	while (getline(in, input))					// 읽어온 파일의 문자열을 input에 저장
	{
		cout << input << "의 비순환회문판별: " <<  check_palindrome(input) << endl;
		cout << input << "의 순환회문판별: " << recursive_check(input) << endl;
		cout << endl;
	}

	in.close();
}