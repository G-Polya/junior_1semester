// 2016112158 김희수

#include <iostream>
#include <vector>
#include <iterator>
#include <deque>
#include <queue>
using namespace std;

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

int recursive_gcd(int a,int b)
{
	if (b == 0)
		return a;
	else
		return recursive_gcd(b, a % b);


}

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
	cout << "N개의 숫자를 입력하시오(입력을 종료하려면 Ctrl+Z):";
	deque<int> test;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(test));

	queue<int> q(test);
	
	cout << no_recursive_gcd(test[0], test[1]) << endl;

	cout << recursive_gcd(test[0], test[1]) << endl;
	
	cout << recursive_gcd(q) << endl;
	cout << endl;

}