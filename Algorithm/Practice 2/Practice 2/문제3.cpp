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

int Partition(vector<int> a, int start, int end)
{
	int pivot = a[end];

	int pIndex = start;

	for (int i = start; i < end; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}

	swap(a[pIndex], a[end]);

	return pIndex;
}


void quickSort(vector<int> a)
{
	stack<pair<int, int>> stk;

	int start = 0;
	int end = a.size() - 1;

	stk.push(make_pair(start, end));

	while (!stk.empty())
	{
		start = stk.top().first, end = stk.top().second;
		stk.pop();

		int pivot = Partition(a, start, end);

		if (pivot - 1 > start)
		{
			stk.push(make_pair(start, pivot - 1));
		}

		if (pivot + 1 < end)
		{
			stk.push(make_pair(pivot + 1, end));
		}
	}
}
void printArray(vector<int> arr)
{
	for (auto iter = begin(arr); iter != end(arr); iter++)
		cout << *iter << " ";

	cout << endl;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	cout << endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	
	vector<int> N;
	N.reserve(10);

	
	for (int i = 0; i < N.capacity(); i++)
	{
		int rand_number = rand() % 10000 + 1;
		N.push_back(rand_number);
	}
	
	vector<int> copy_N;
	copy_N = N;


	
	
	
	int* K = new int[1000];						// 버블소트용 배열
	int K_size = _msize(K) / sizeof(int);
	int* copy_K = new int[K_size];				// 퀵소트용 배열
	copy(K, K + K_size, copy_K);
	for (int i = 0; i < K_size; i++)
		K[i] = rand() % 10000 + 1;

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
//	bubbleSort(K, K_size);
	chrono::steady_clock::time_point bubble_end = chrono::steady_clock::now();
	auto bubble_elapsed_time = chrono::duration_cast<chrono::microseconds>(bubble_end - bubble_begin).count();
	
	chrono::steady_clock::time_point quick_begin = chrono::steady_clock::now();
//	quickSort(copy_K, K_size);
	chrono::steady_clock::time_point quick_end = chrono::steady_clock::now();
	auto quick_elapsed_time = chrono::duration_cast<chrono::microseconds>(quick_end - quick_begin).count();

	
	cout << "Elapsed time of Bubble sort: " << bubble_elapsed_time<<" us"<< endl;
	cout << "Elapsed time of Quick sort: " << quick_elapsed_time <<" us" <<endl;


	//delete[] N;
	delete[] K;
	delete[] copy_K;
	//delete[] copy_N;

}