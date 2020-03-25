// 2016112158 ±èÈñ¼ö

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int no_recursive_gcd(vector<int> numbers)
{
	int t;
	while (numbers[1])
	{
		t = numbers[0] % numbers[1];
		numbers[0] = numbers[1];
		numbers[1] = t;
	}

	return numbers[0];
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
	vector<int> test = { 36,12,24,50 };
	cout << no_recursive_gcd(test) << endl;

	cout << recursive_gcd(12,16) << endl;
	
	cout << recursive_gcd(test) << endl;
	cout << endl;

}