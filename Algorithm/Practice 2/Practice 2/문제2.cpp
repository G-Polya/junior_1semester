// 2016112158 ±èÈñ¼ö

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
	deque<int> test = { 16,12,24,60,90 };
	queue<int> q(test);
	cout<<recursive_gcd(q)<<endl;

}