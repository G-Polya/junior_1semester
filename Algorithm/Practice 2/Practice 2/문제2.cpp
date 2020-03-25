// 2016112158 ±èÈñ¼ö

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

int recursive_gcd(vector<int> numbers)
{
	vector<int> sub_numbers = { begin(numbers), --end(numbers)};
	
	if (sub_numbers.size() <= 1)
		return -1;
	
	
	if (sub_numbers.size() == 2)
	{
		return recursive_gcd(sub_numbers[0], sub_numbers[1]);
	} 



	return recursive_gcd(sub_numbers);

}


int main()
{
	deque<int> test = { 16,12,24,60,90 };
	queue<int> q(test);
	
	cout << no_recursive_gcd(36,12) << endl;

	cout << recursive_gcd(12,16) << endl;
	
	cout << recursive_gcd(q) << endl;
	cout << endl;

}