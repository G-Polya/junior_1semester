// 2016112158 �����
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

// find maximum
int Maximum(vector<int> arr)
{
	int temp = arr[0];						// temp�� arr�� ù��° ���� ����
	for (int i = 1; i < arr.size(); i++)	// arr�� ��� ���ҿ� ���ؼ�
		if (temp < arr[i])
			temp = arr[i];					// �� ���Ұ� temp���� ũ�ٸ� �� ���Ҹ� temp�� ����. 

	return temp;
}


// find minimum
int Minimum(vector<int> arr)
{
	int temp = arr[0];
	for (int i = 1; i < arr.size(); i++)
		if (temp > arr[i])
			temp = arr[i];

	return temp;
}

// arr : �Է� �迭
void FindMinMax(vector<int> arr)
{

	int min = arr[0], max = arr[0];
	for (int i = 1; i < arr.size() - 1; i += 2)		// (n-1)/2
	{
		int small, large;
		if (arr[i] < arr[i + 1])		// i��° ���Ұ� i+1�������� ������ 
		{
			small = arr[i];
			large = arr[i + 1];
		}
		else                           // ũ��
		{
			small = arr[i + 1];
			large = arr[i];
		}

		if (small < min)		// small�� min���� ������ small�� ���ο� min�� �ȴ�
			min = small;
		if (large > max)		// larger�� max���� ũ�� large�� ���ο� max�� �ȴ�
			max = large;
	}

	cout << "Minimum: " << min << ", Maximum: " << max << endl;
}


int main()
{
	srand((unsigned int)time(NULL));

	// �迭 �ʱ�ȭ
	vector<int> arr;
	arr.reserve(1000);
	for (int i = 0; i < arr.capacity(); i++)
		arr.push_back((rand()<<15) % 100000 + 1);

	cout << "Maximum function: " << Maximum(arr) << endl;
	cout << "Minimum function: " << Minimum(arr) << endl;

	cout << endl;

	cout << "Reuslt of FindMinMax: " << endl;
	FindMinMax(arr);

	return 0;
}