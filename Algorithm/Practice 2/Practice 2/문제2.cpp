// 2016112158 김희수

#include <iostream>
#include <vector>
#include <iterator>
#include <deque>
#include <queue>
using namespace std;

// not recursive GCD
int no_recursive_gcd(int a, int b)
{
	int t;
	while (b)
	{
		t = a % b;
		a = b;
		b = t;
	}

	return a;
}

// recursive GCD
int recursive_gcd(int a,int b)
{
	if (b == 0)
		return a;
	else
		return recursive_gcd(b, a % b);


}

// N개의 수에 대한 최대공약수
// 큐를 사용하여 앞에 있는 두 수에 대한 최대공약수를 구한 후, 그 최대공약수를 다시 큐에 삽입 >> 반복
// 삽입된 수들에 대해 최대공약수를 구한 값이 구하고자 하는 값이다.
int recursive_gcd(queue<int> q)
{
	if (q.size() == 1)
	{
		int result = q.front();
		q.pop();

		return result;
	}

	int num1 = q.front();
	q.pop();

	int num2 = q.front();
	q.pop();
	q.push(recursive_gcd(num1, num2));
	return recursive_gcd(q);

}


int main()
{
	cout << "N개의 숫자를 입력하시오(입력을 종료하려면 Ctrl+Z): ";
	deque<int> test;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(test));

	queue<int> q(test);
	
	cout << "재귀없이 두 수(입력값의 첫번째, 두번쨰 값)의 최대공약수 구하기: "<<no_recursive_gcd(test[0], test[1]) << endl;

	cout <<"재귀를 써서 두 수(입력값의 첫번째, 두번쨰 값)의 최대공약수 구하기: " << recursive_gcd(test[0], test[1]) << endl;
	
	cout <<"N개의 수에 대해 최대공약수 구하기: "<< recursive_gcd(q) << endl;
	cout << endl;

}