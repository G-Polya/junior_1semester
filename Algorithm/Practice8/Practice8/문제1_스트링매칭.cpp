//2016112158 �����
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <cmath>

using namespace std;

// brute force�� ��Ʈ�� ��Ī
// text : �ؽ�Ʈ, pattern : ����
void brute_force_matching(string text, string pattern)
{
	int i, j;
	for(i = 0; i<text.size()-pattern.size();i++)	// �ؽ�Ʈũ�� - ����ũ�⸸ŭ ������ �����̵� �� ��
	{
		for (j = 0; j < pattern.size(); j++)	// ������ �� ���ڿ� ���ؼ�
			if (pattern[j] != text[i + j])		// ������ ���ڿ� �ؽ�Ʈ�� ���ڰ� ���������� break�ǰ� �ѹ��ڸ�ŭ �����̵�
				break;
		if (j == pattern.size())				
			cout << "������ �ؽ�Ʈ�� " << i+1 << "�������� ��Ÿ��" << endl;
	}
}

//https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
// q: �ؽ��Լ��� ���� �����Ǵ� mod�� ���� ����
void rabin_karp_matching(string text, string pattern, int q)
{
	const int d = 36; // [0~9]+[a-z] = 10 +_ 26 = 36. 
	const int M = pattern.size();
	const int N = text.size();
	int p = 0;		// pattern�� ���� hash ��
	int t = 0;		// text�� ���� hash��
	
	int h = (int)pow(d, M-1) % q;

	// pattern�� text�� ù��° ������ hash ��� (pattern���̸�ŭ text�� �߶���� �Ÿ� '����'��� �ϰڴ�.)
	for (int i = 0; i < M; i++)
	{
		p = (d * p + pattern[i]) % q;
		t = (d * t + text[i]) % q;
	}



}


int main()
{
	string text;
	string pattern;

	cout << "text�� pattern �Է� >> ";
	cin >> text >> pattern;
	
	brute_force_matching(text, pattern);
}