//2016112158 �����
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

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

void KMP_matching(string text, string pattern)
{
	const int d = 36; // [0~9]+[a-z] = 10 +_ 26 = 36

}


int main()
{
	string text;
	string pattern;

	cout << "text�� pattern �Է� >> ";
	cin >> text >> pattern;
	
	brute_force_matching(text, pattern);
}