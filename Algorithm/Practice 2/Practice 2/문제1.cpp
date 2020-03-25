// 2016112158 김희수
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

bool check_palindrome(string input)
{
	char* arr = new char[input.size() + 1];
	strcpy_s(arr, input.size()+1, input.c_str());
	bool check = true;
	for (int i = 0; i < strlen(arr) / 2; i++)
	{
		if (arr[i] != arr[strlen(arr) - i - 1])
		{
			check = false;
			break;
		}
	}
	delete[] arr;
	arr = NULL;

	return check;
}


bool recursive_check(string input)
{
	bool check = true;
	
	char* arr = new char[input.size() + 1];
	
	if (input.size() <= 1)
		return true;
	
	if (input.substr(0, 1) != input.substr(input.size() - 1))
		return false;

	return recursive_check(input.substr(1, input.size() - 2));
}

int main()
{
	ifstream in("exam_palindrome.txt");
	string input;

	while (getline(in, input))
	{
		cout << input << "의 비순환회문판별: " << check_palindrome(input) << endl;
		cout << input << "의 순환회문판별: " << recursive_check(input) << endl;
		cout << endl;
	}

	in.close();
}