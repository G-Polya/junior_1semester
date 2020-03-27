// 2016112158 �����
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// ���ȯ ȸ�� �Ǻ� �˰���
bool check_palindrome(string input)
{
	char* arr = new char[input.size() + 1];				// �Ǻ��ϰ��� �ϴ� ����(input)�� �ӽ÷� ������ �迭 arr
	strcpy_s(arr, input.size()+1, input.c_str());
	bool check = true;

	for (int i = 0; i < strlen(arr) / 2; i++)			// ó������ �����ؼ�
	{
		if (arr[i] != arr[strlen(arr) - i - 1])			// ��Ī������ ���Ѵ�
		{
			check = false;
			break;
		}
	}
	delete[] arr;
	arr = NULL;

	return check;
}

// ��ȯ ȸ�� �Ǻ� �˰���
bool recursive_check(string input)
{
	bool check = true;
	
	char* arr = new char[input.size() + 1];
	
	if (input.size() <= 1)								// ������ ���̰� 1�̶��, �� �����ϳ� ��ü�� ȸ���̴�
		return true;
	
	if (input.substr(0, 1) != input.substr(input.size() - 1))		//ó�� �ܾ�� ���ܾ ���� ������ false
		return false;

	return recursive_check(input.substr(1, input.size() - 2));		// ��������� �ݺ�
}

int main()
{
	ifstream in("exam_palindrome.txt");			//���� �о����
	string input;

	while (getline(in, input))					// �о�� ������ ���ڿ��� input�� ����
	{
		cout << input << "�� ���ȯȸ���Ǻ�: " <<  check_palindrome(input) << endl;
		cout << input << "�� ��ȯȸ���Ǻ�: " << recursive_check(input) << endl;
		cout << endl;
	}

	in.close();
}