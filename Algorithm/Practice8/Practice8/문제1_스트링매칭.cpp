//2016112158 김희수

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

// brute force로 스트링 매칭
// text : 텍스트, pattern : 패턴
void brute_force_matching(string text, string pattern)
{
	int M = pattern.size();
	int N = text.size();
	for (int i = 0; i <= N - M; i++)		// 텍스트크기 - 패턴크기만큼 앞으로 슬라이드 될 것
	{
		int j;
		for (j = 0; j < M; j++)				// 패턴의 각 문자에 대해서
			if (pattern[j] != text[i + j])	// 패턴의 문자와 텍스트의 문자가 같지않으면 break되고 한문자만큼 슬라이드
				break;
		if (j == M)
			cout << "(Brute Force)" << pattern << " 패턴이 텍스트의 " << i + 1 << "번쨰부터 나타남" << endl;
	}
}

//
// q: 해시함수에 의해 결정되는 mod를 위한 제수
void rabin_karp_matching(string text, string pattern, int q)
{
	const int d = 36; // [0~9]+[a-z] = 10 +_ 26 = 36. 
	const int M = pattern.size();
	const int N = text.size();
	int p = 0;		// pattern을 위한 hash 값
	int t = 0;		// text를 위한 hash값
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
				cout << "(Rabin-Karp)" << pattern << " 패턴이 텍스트의 " << i + 1 << "번쨰부터 나타남" << endl;
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

// 최대 접두부 테이블 생성함수
void computeSP(string pattern, int SP[])
{
	int j = 0;	// 이전에서 가장 길었던 prefix-suffix의 길이
	int M = pattern.size();
	SP[0] = 0;



	// SP[i]를 채우기 위한 계산 1부터 M-1까지 반복
	int i = 1;
	while (i < M)
	{
		if (pattern[i] == pattern[j])	 // pattern의 i번째 인덱스와 j번째 인덱스를 비교해서 같으면
		{
			j++;
			SP[i] = j;	// j을 증가시켜 SP[i]에 저장
			i++;
		}
		else     // 다르면
		{
			if (j != 0)          // j이 0이 아니면
				j = SP[j - 1]; // j은 한칸 뒤로
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

	int i = 0;	// text를 위한 index
	int j = 0;  // pattern을 위한 인덱스
	while (i < N)
	{
		if (pattern[j] == text[i])	// pattern과 text가 일치하는 동안엔 그냥 넘어간다. 
		{
			j++;
			i++;
		}

		if (j == M) // pattern을 위한 인덱스가 패턴의 길이와 같다는 건, text안에 패턴이 존재한다는 걸 의미
		{
			cout << "(KMP)" << pattern << " 패턴이 텍스트의 " << i - j + 1 << "번쨰부터 나타남" << endl;
			j = SP[j - 1];
		}
		else if (i < N && pattern[j] != text[i]) // pattern과 text가 같지 않을때 뒤로 이동해서 text의 suffix/pattern의 prefix 다음의 문자를 비교
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

	cout << "text 입력 >> ";
	cin >> text;
	cout << "pattern 입력 >> ";
	cin >> pattern;

	//bruteforce matching
	chrono::steady_clock::time_point br_start = chrono::steady_clock::now();
	brute_force_matching(text, pattern);
	chrono::steady_clock::time_point br_end = chrono::steady_clock::now();
	auto br_elapsed_time = chrono::duration_cast<chrono::microseconds>(br_end - br_start).count();
	cout << "Elapsed time of Brute-Force matching : " << (double)br_elapsed_time/1000000 << "초" << endl << endl;

	// Rabin-Karp
	chrono::steady_clock::time_point rk_start = chrono::steady_clock::now();
	rabin_karp_matching(text, pattern, 13);
	chrono::steady_clock::time_point rk_end = chrono::steady_clock::now();
	auto rk_elapsed_time = chrono::duration_cast<chrono::microseconds>(rk_end - rk_start).count();
	cout << "Elapsed time of Rabin-Karp mathcing : " << (double)rk_elapsed_time / 1000000 <<"초"<< endl << endl;


	// KMP
	chrono::steady_clock::time_point kmp_start = chrono::steady_clock::now();
	KMP_matching(text, pattern);
	chrono::steady_clock::time_point kmp_end = chrono::steady_clock::now();
	auto kmp_elapsed_time = chrono::duration_cast<chrono::microseconds>(kmp_end - kmp_start).count();
	cout << "Elapsed time of KMP mathcing : " << (double)kmp_elapsed_time / 1000000 << "초" << endl << endl;


}