// 2016112158 �����

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

// N���� ���� ���� �ִ�����
// ť�� ����Ͽ� �տ� �ִ� �� ���� ���� �ִ������� ���� ��, �� �ִ������� �ٽ� ť�� ���� >> �ݺ�
// ���Ե� ���鿡 ���� �ִ������� ���� ���� ���ϰ��� �ϴ� ���̴�.
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
	cout << "N���� ���ڸ� �Է��Ͻÿ�(�Է��� �����Ϸ��� Ctrl+Z): ";
	deque<int> test;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(test));

	queue<int> q(test);
	
	cout << "��;��� �� ��(�Է°��� ù��°, �ι��� ��)�� �ִ����� ���ϱ�: "<<no_recursive_gcd(test[0], test[1]) << endl;

	cout <<"��͸� �Ἥ �� ��(�Է°��� ù��°, �ι��� ��)�� �ִ����� ���ϱ�: " << recursive_gcd(test[0], test[1]) << endl;
	
	cout <<"N���� ���� ���� �ִ����� ���ϱ�: "<< recursive_gcd(q) << endl;
	cout << endl;

}