//2016112158 김희수
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <cmath>

using namespace std;

// brute force로 스트링 매칭
// text : 텍스트, pattern : 패턴
void brute_force_matching(string text, string pattern)
{
	int i, j;
	for(i = 0; i<text.size()-pattern.size();i++)	// 텍스트크기 - 패턴크기만큼 앞으로 슬라이드 될 것
	{
		for (j = 0; j < pattern.size(); j++)	// 패턴의 각 문자에 대해서
			if (pattern[j] != text[i + j])		// 패턴의 문자와 텍스트의 문자가 같지않으면 break되고 한문자만큼 슬라이드
				break;
		if (j == pattern.size())				
			cout << "패턴이 텍스트의 " << i+1 << "번쨰부터 나타남" << endl;
	}
}

//https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
// q: 해시함수에 의해 결정되는 mod를 위한 제수
void rabin_karp_matching(string text, string pattern, int q)
{
	const int d = 36; // [0~9]+[a-z] = 10 +_ 26 = 36. 
	const int M = pattern.size();
	const int N = text.size();
	int p = 0;		// pattern을 위한 hash 값
	int t = 0;		// text를 위한 hash값
	
	int h = (int)pow(d, M-1) % q;

	// pattern과 text의 첫번째 덩이의 hash 계산 (pattern길이만큼 text를 잘라놓은 거를 '덩이'라고 하겠다.)
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

	cout << "text와 pattern 입력 >> ";
	cin >> text >> pattern;
	
	brute_force_matching(text, pattern);
}