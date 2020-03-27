// 2016112158 김희수

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

template<typename T>
void elapsed_time(T& func(int arr[], int size))
{
	clock_t t;
	t = clock();
	func();

	t = clock() - t;
	cout << "time: " << t << " miliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
}


int main()
{
	srand((unsigned int)time(NULL));
	
	int* N = new int[10];
	int N_size = _msize(N) / sizeof(int);
	for (int i = 0; i < N_size; i++)
		N[i] = rand() % 10000 + 1;

	// 3-1
	//cout << "Original array N: ";
	//printArray(N, N_size);
	//cout << endl;

	int* K = new int[1000];						// 버블소트용 배열
	int K_size = _msize(K) / sizeof(int);
	int* copy_K = new int[K_size];				// 퀵소트용 배열
	copy(K, K + K_size, copy_K);
	for (int i = 0; i < K_size; i++)
		K[i] = rand() % 10000 + 1;

	// 3-2
	//cout << "Bubble Sort: ";
	//bubbleSort(N, N_size);
	//printArray(N, N_size);
	//cout << endl;


	// 3-3
	//cout << "Quick Sort: ";
	//quickSort(N, 0, 9);
	//printArray(N, N_size);
	//cout << endl;

	//3-4
	
	elapsed_time(bubbleSort(K, K_size));
	
	
	quickSort(K, 0, K_size - 1);
	

	
	

	delete[] N;
	delete[] K;
	delete[] copy_K;

}