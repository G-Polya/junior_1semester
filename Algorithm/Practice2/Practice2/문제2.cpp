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
	int temp;
	while (b)
	{
		temp = a % b;
		a = b;
		b = temp;
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
// 예시 {16, 24, 40, 36}
int recursive_gcd(queue<int> q)
{
	if (q.size() == 1)						//큐의 크기가 1이라면, 즉 원소가 1개뿐
	{
		int result = q.front();
		q.pop();

		return result;
	}

	int num1 = q.front();
	q.pop();

	int num2 = q.front();
	q.pop();
	q.push(recursive_gcd(num1, num2));		// 첫번째, 두번째 원소의 최대공약수를 큐에 저장. 16,24의 최대공약수 >> 8을 저장 >> 큐: {40, 36, 8}
	return recursive_gcd(q);				// 이를 반복하면...40, 36에 대해서 한번더 계산이 이루어진 후 큐: {8, 4} >> 4

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