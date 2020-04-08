// 2016112158 김희수
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

// find maximum
int Maximum(vector<int> arr)
{
	int temp = arr[0];						// temp에 arr의 첫번째 원소 저장
	for (int i = 1; i < arr.size(); i++)	// arr의 모든 원소에 대해서
		if (temp < arr[i])
			temp = arr[i];					// 그 원소가 temp보다 크다면 그 원소를 temp에 저장. 

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

// arr : 입력 배열
void FindMinMax(vector<int> arr)
{

	int min = arr[0], max = arr[0];
	for (int i = 1; i < arr.size() - 1; i += 2)		// (n-1)/2
	{
		int small, large;
		if (arr[i] < arr[i + 1])		// i번째 원소가 i+1번쨰보다 작으면 
		{
			small = arr[i];
			large = arr[i + 1];
		}
		else                           // 크면
		{
			small = arr[i + 1];
			large = arr[i];
		}

		if (small < min)		// small이 min보다 작으면 small이 새로운 min이 된다
			min = small;
		if (large > max)		// larger가 max보다 크면 large가 새로운 max가 된다
			max = large;
	}

	cout << "Minimum: " << min << ", Maximum: " << max << endl;
}


int main()
{
	srand((unsigned int)time(NULL));

	// 배열 초기화
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