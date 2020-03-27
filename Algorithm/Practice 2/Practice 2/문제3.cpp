// 2016112158 김희수

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>


using namespace std;


// swap function
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


// bubble sort
void bubbleSort(int arr[], int size)
{
	if (size == 1)
		return;

	for (int i = 0; i < size - 1; i++)		// 0부터 arr의 길이-1까지
		if (arr[i] < arr[i + 1])			// 앞에 있는 원소가 더 크면
			swap(arr[i], arr[i+1]);			// 스왑한다

	bubbleSort(arr, size - 1);
}

// partition for quick sort
int partition(int arr[], int low, int high)
{
	int pivotIndex = low + (high - low) / 2;		// pivot을 가운데로 설정
	int pivotValue = arr[pivotIndex];

	int i = low, j = high;							// i: 왼쪽부터, j: 오른쪽부터

	while (i <= j)
	{
		while (arr[i] < pivotValue)					// 왼쪽에 있는 값이 pivotValue보다 작으면 계속 증가
			i++;
		while (arr[j] > pivotValue)					// 오른쪽에 있는 값이 pivotValue보다 크면 계속 감소
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
void quickSort(int arr[], int size)
{
	int high = size - 1;
	int low = 0;
	int* stk = new int[high - low + 1];		    // 스택 생성				
	int top = -1;								// top of stack 초기화

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

		if (pivot + 1 < high)						// 인덱스 비교: 피봇 오른쪽의 원소들에 대해서
		{
			stk[++top] = pivot + 1;
			stk[++top] = high;						// 스택에 푸시
		}
	}

	delete[] stk;
}

// 프린트를 위한 함수
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
	srand((unsigned int)time(NULL));			// random시드 설정
	
	int* N = new int[10];						// 3-2번 버블정렬용 배열
	int N_size = _msize(N) / sizeof(int);
	int* copy_N = new int[N_size];				// 3-3번 퀵정렬용 배열
	
	// 배열 초기화
	for (int i = 0; i < N_size; i++)
	{
		int* rand_number = new int(rand()%10000+1);
		N[i] = *rand_number;
		copy_N[i] = *rand_number;
		delete rand_number;
	}

	int* K = new int[1000];						// 버블정렬용 배열
	int K_size = _msize(K) / sizeof(int);
	int* copy_K = new int[K_size];				// 퀵정렬용 배열


	// 배열 초기화
	for (int i = 0; i < K_size; i++)
	{
		int* rand_number = new int(rand() % 10000 + 1);
		K[i] = *rand_number;
		copy_K[i] = *rand_number;
		delete rand_number;
	}



	// 3-1
	cout << "Original array N: ";
	printArray(N, N_size);
	

	// 3-2	
	cout << "Bubble Sort: ";
	bubbleSort(N, N_size);
	printArray(N, N_size);
	cout << endl;

	// 3-3
	cout << "Copied array copy_N: ";
	printArray(copy_N, N_size);
	cout << "Quick Sort: ";
	quickSort(copy_N, N_size);
	printArray(N, N_size);
	cout << endl;
	
	cout << "====================================\n" << endl;

	

	//3-4	

	// 버블 정렬
	chrono::steady_clock::time_point bubble_begin = chrono::steady_clock::now();								// 정렬 전 시간
	bubbleSort(K, K_size);																						// 정렬 
	chrono::steady_clock::time_point bubble_end = chrono::steady_clock::now();									// 정렬 후 시간
	auto bubble_elapsed_time = chrono::duration_cast<chrono::microseconds>(bubble_end - bubble_begin).count();	// 정렬에 걸린 시간
	

	// 퀵 정렬
	chrono::steady_clock::time_point quick_begin = chrono::steady_clock::now();									// 정렬 전 시간
	quickSort(copy_K, K_size);																					// 정렬
	chrono::steady_clock::time_point quick_end = chrono::steady_clock::now();									// 정렬 후 시간
	auto quick_elapsed_time = chrono::duration_cast<chrono::microseconds>(quick_end - quick_begin).count();		// 정렬에 걸린 시간

	
	cout << "Elapsed time of Bubble sort: " << bubble_elapsed_time<<" us"<< endl;
	cout << "Elapsed time of Quick sort: " << quick_elapsed_time <<" us" <<endl;


	delete[] N;
	delete[] K;
	delete[] copy_K;
	delete[] copy_N;

}