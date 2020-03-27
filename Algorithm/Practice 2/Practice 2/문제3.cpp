// 2016112158 김희수

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <stack>
#include <algorithm>
#include <vector>


using namespace std;

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void bubbleSort(vector<int>& arr, int size)
{
	if (size == 1)
		return;

	for (int i = 0; i < size - 1; i++)
		if (arr[i] < arr[i + 1])
			swap(arr[i], arr[i+1]);

	bubbleSort(arr, size - 1);
}

int partition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] > pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);

	return i+1;
}

void quickSort(vector<int>& arr)
{
	int low = 0;
	int high = arr.size() - 1;
	
	int* stack = new int[high - low + 1];
	int top = -1;

	stack[++top] = low;
	stack[++top] = high;

	while (top >= 0)
	{
		high = stack[top--];
		low = stack[top--];

		int pivot = partition(arr, low, high);

		if (pivot - 1 > low)
		{
			stack[++top] = low;
			stack[++top] = pivot - 1;
		}

		if (pivot + 1 < high)
		{
			stack[++top] = pivot + 1;
			stack[++top] = high;
		}
	}

	delete[] stack;
	
}
void printArray(vector<int> arr)
{
	for (auto iter = begin(arr); iter != end(arr); iter++)
		cout << *iter << " ";

	cout << endl;
}


int main()
{
	srand((unsigned int)time(NULL));
	
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

	
	cout << "Elapsed time of Bubble sort: " << bubble_elapsed_time<<" us"<< endl;
	cout << "Elapsed time of Quick sort: " << quick_elapsed_time <<" us" <<endl;


	return 0;

}