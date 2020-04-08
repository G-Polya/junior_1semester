// 2016112158 김희수

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <stack>
#include <algorithm>
#include <vector>


using namespace std;


// swap function
void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


// bubble sort
void bubbleSort(vector<int>& arr, int size)
{
	if (size == 1)
		return;

	for (int i = 0; i < size - 1; i++)		// 0부터 arr의 길이-1까지
		if (arr[i] < arr[i + 1])			// 앞에 있는 원소가 더 크면
			swap(arr[i], arr[i + 1]);			// 스왑한다
	for (int i = 0; i < size - 1; i++)
		if (arr[i] < arr[i + 1])
			swap(arr[i], arr[i + 1]);

	bubbleSort(arr, size - 1);
}

// partition for quick sort						
int partition(vector<int>& arr, int low, int high)
{
	int pivotIndex = low + (high - low) / 2;
	int pivotValue = arr[pivotIndex];

	int i = low, j = high;

	while (i <= j)
	{
		while (arr[i] < pivotValue)
			i++;
		while (arr[j] > pivotValue)
			j--;

		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	return i;

}


// quick sort
void quickSort(vector<int>& arr)
{
	int low = 0;
	int high = arr.size() - 1;

	int* stk = new int[high - low + 1];
	int top = -1;

	// low와 high의 초기값을 스택에 푸시
	stk[++top] = low;
	stk[++top] = high;

	while (top >= 0)
	{
		high = stk[top--];
		low = stk[top--];

		int pivot = partition(arr, low, high);		// 파티션

		if (pivot - 1 > low)						// 인덱스 비교: 피봇왼쪽의 원소들에 대해서
		{
			stk[++top] = low;						// 스택에 푸시
			stk[++top] = pivot - 1;
		}

		if (pivot + 1 < high)
		{
			stk[++top] = pivot + 1;
			stk[++top] = high;
		}

	}

	delete[] stk;
}

// 프린트를 위한 함수

void printArray(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";

	cout << endl;
}


int main()
{
	srand((unsigned int)time(NULL));			// random시드 설정

	vector<int> N;
	N.reserve(10);

	vector<int> copy_N;
	copy_N.reserve(N.capacity());

	for (int i = 0; i < N.capacity(); i++)
		N.push_back(rand() % 10000 + 1);

	copy_N = N;



	vector<int> K;								// 버블정렬룡 배열
	K.reserve(1000);
	for (int i = 0; i < K.capacity(); i++)
		K.push_back(rand() % 10000 + 1);
	vector<int> copy_K;							// 퀵정렬용 배열
	copy_K = K;

	// 3-1
	cout << "Original array N: ";
	printArray(N);

	// 3-2	
	cout << "Bubble Sort: ";
	bubbleSort(N, N.size());
	printArray(N);
	cout << endl;



	// 3-3
	cout << "Copied array N: ";
	printArray(copy_N);
	cout << "Quick Sort: ";
	quickSort(copy_N);
	printArray(copy_N);
	cout << endl;


	cout << "================================\n" << endl;

	//3-4	
	chrono::steady_clock::time_point bubble_begin = chrono::steady_clock::now();
	bubbleSort(K, K.size());
	chrono::steady_clock::time_point bubble_end = chrono::steady_clock::now();
	auto bubble_elapsed_time = chrono::duration_cast<chrono::microseconds>(bubble_end - bubble_begin).count();

	chrono::steady_clock::time_point quick_begin = chrono::steady_clock::now();
	quickSort(copy_K);
	chrono::steady_clock::time_point quick_end = chrono::steady_clock::now();
	auto quick_elapsed_time = chrono::duration_cast<chrono::microseconds>(quick_end - quick_begin).count();


	cout << "Elapsed time of Bubble sort: " << bubble_elapsed_time << " us" << endl;
	cout << "Elapsed time of Quick sort: " << quick_elapsed_time << " us" << endl;


	return 0;

}