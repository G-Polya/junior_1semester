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
// min : arr에 저장될 수 있는 값중에서 최소값 여기선 1~100000이므로 1
// max : arr에 저장될 수 있는 값중에서 최대값 여기선 1~100000이므로 100000
void FindMinMax(vector<int> arr, int& min, int& max)
{
	min = arr[0], max = arr[0];
	for (int i = 1; i < arr.size() - 1; i += 2)
	{
		int small, large;
		if (arr[i] < arr[i + 1])
		{
			small = arr[i];
			large = arr[i + 1];
		}
		else
		{
			small = arr[i + 1];
			large = arr[i];
		}

		if (small < min)
			min = small;
		if (large > max)
			max = large;
	}

	cout << "Minimum: " << min << ", Maximum: " << max << endl;
}


int main()
{
	srand((unsigned int)time(NULL));
	
	vector<int> arr;
	arr.reserve(1000);
	for (int i = 0; i < arr.capacity(); i++)
		arr.push_back(rand() % 100000 + 1);

	cout<< Maximum(arr)<<endl;
	cout << Minimum(arr) << endl;

	int min = 1;
	int max = 100000;

	FindMinMax(arr, min,max);
}