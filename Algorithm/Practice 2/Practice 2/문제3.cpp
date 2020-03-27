﻿// 2016112158 김희수

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>


using namespace std;

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int arr[], int size)
{
	if (size == 1)
		return;

	for (int i = 0; i < size - 1; i++)
		if (arr[i] > arr[i + 1])
			swap(arr[i], arr[i+1]);

	bubbleSort(arr, size - 1);
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
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

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
	srand((unsigned int)time(NULL));
	
	int* N = new int[10];						// 3-2번 버블소트용 배열
	int N_size = _msize(N) / sizeof(int);
	int* copy_N = new int[N_size];				// 3-3번 퀵소트용 배열
	for (int i = 0; i < N_size; i++)
		N[i] = rand() % 10000 + 1;

	// 3-1
	cout << "Original array N: ";
	printArray(N, N_size);
	
	int* K = new int[1000];						// 버블소트용 배열
	int K_size = _msize(K) / sizeof(int);
	int* copy_K = new int[K_size];				// 퀵소트용 배열
	copy(K, K + K_size, copy_K);
	for (int i = 0; i < K_size; i++)
		K[i] = rand() % 10000 + 1;

	// 3-2
	cout << "Bubble Sort: ";
	bubbleSort(N, N_size);
	printArray(N, N_size);
	

	// 3-3
	cout << "Quick Sort: ";
	quickSort(copy_N, 0, N_size-1);
	printArray(N, N_size);
	cout << endl;
	cout << endl;

	//3-4	
	chrono::steady_clock::time_point bubble_begin = chrono::steady_clock::now();
	bubbleSort(K, K_size);
	chrono::steady_clock::time_point bubble_end = chrono::steady_clock::now();
	auto bubble_elapsed_time = chrono::duration_cast<chrono::microseconds>(bubble_end - bubble_begin).count();
	
	chrono::steady_clock::time_point quick_begin = chrono::steady_clock::now();
	quickSort(copy_K, 0, K_size - 1);
	chrono::steady_clock::time_point quick_end = chrono::steady_clock::now();
	auto quick_elapsed_time = chrono::duration_cast<chrono::microseconds>(quick_end - quick_begin).count();

	
	cout << "Elapsed time of Bubble sort: " << bubble_elapsed_time<<" us"<< endl;
	cout << "Elapsed time of Quick sort: " << quick_elapsed_time <<" us" <<endl;


	delete[] N;
	delete[] K;
	delete[] copy_K;
	delete[] copy_N;

}