//2016112158 �����

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <vector>

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
			cout << "(Brute-Force) ������ �ؽ�Ʈ�� " << i+1 << "�������� ��Ÿ��" << endl;
	}
}

//
// q: �ؽ��Լ��� ���� �����Ǵ� mod�� ���� ����
void rabin_karp_matching(string text, string pattern, int q)
{
	const int d = 36; // [0~9]+[a-z] = 10 +_ 26 = 36. 
	const int M = pattern.size();
	const int N = text.size();
	int p = 0;		// pattern�� ���� hash ��
	int t = 0;		// text�� ���� hash��
	int i, j;
	int h = 1;

	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;
	

	// ȣ�ʹ���� ���� p,t���
	for (i = 0; i < M; i++)
	{
		p = (d * p + pattern[i]) % q;
		t = (d * t + text[i]) % q;
	}

	// �ϳ��� �����̵��ذ��� ���� ã��
	for (i = 0; i < N - M + 1; i++)
	{

		if (p == t)	// hash���� ������ ��쿡 ���� ���� ���� ��Ī����
		{
			for (j = 0; j < M; j++)
				if (text[i + j] != pattern[j])
					break;

			//p == t�̰� pattern[0...M-1] == text[i...i+M-1]�̸� 
			if (j == M)
				cout << "(Rabin-Karp) ������ �ؽ�Ʈ�� " << i + 1 << "�������� ��Ÿ��" << endl;
		}
		// ��ȭ���� �̿��� ���� t�� ���
		if (i < N - M)
		{
			t = (d * (t - text[i] * h) + text[i + M]) % q;

			if (t < 0)
				t = t + q;
		}
	}

}

void computeSP(string pattern, int SP[])
{
	int len = 0;	// �������� ���� ����� prefix-suffix�� ����
	int M = pattern.size();
	SP[0] = 0;



	// SP[i]�� ä��� ���� ��� 1~M-1
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
	int M = pattern.size();
	int N = text.size();

	int* SP = new int[M];
	
	computeSP(pattern, SP);

	int i = 0;	// text�� ���� index
	int j = 0;  // pattern�� ���� �ε���
	while (i < N)
	{
		if (pattern[j] == text[i])
		{
			j++;
			i++;
		}

		if (j == M)
		{
			cout << "(KMP) ������ �ؽ�Ʈ�� " << i -j + 1 << "�������� ��Ÿ��" << endl;
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

int main()
{
	string text;
	string pattern;

	cout << "text �Է� >> ";
	cin >> text;
	cout << "pattern �Է� >> ";
	cin >> pattern;
	
	//bruteforce matching
	chrono::steady_clock::time_point br_start = chrono::steady_clock::now();
	brute_force_matching(text, pattern);
	chrono::steady_clock::time_point br_end = chrono::steady_clock::now();
	auto br_elapsed_time = chrono::duration_cast<chrono::microseconds>(br_end - br_start).count();
	cout << "Elapsed time of Brute-Force matching : " << br_elapsed_time << endl << endl;

	// Rabin-Karp
	chrono::steady_clock::time_point rk_start = chrono::steady_clock::now();
	rabin_karp_matching(text, pattern, 13);
	chrono::steady_clock::time_point rk_end = chrono::steady_clock::now();
	auto rk_elapsed_time = chrono::duration_cast<chrono::microseconds>(rk_end - rk_start).count();
	cout << "Elapsed time of Rabin-Karp mathcing : " << rk_elapsed_time << endl<<endl;


	// KMP
	chrono::steady_clock::time_point kmp_start = chrono::steady_clock::now();
	KMP_matching(text, pattern);
	chrono::steady_clock::time_point kmp_end = chrono::steady_clock::now();
	auto kmp_elapsed_time = chrono::duration_cast<chrono::microseconds>(kmp_end - kmp_start).count();
	cout << "Elapsed time of KMP mathcing : " << kmp_elapsed_time << endl << endl;


}