// 2016112158 ±èÈñ¼ö

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <array>
#include <iterator>


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
	stack<int> stack;
	
	
	stack.push(low);
	stack.push(high);

	while (stack.empty())
	{
		high = stack.top();
		stack.pop();
		low = stack.top();
		stack.pop();

		int pivot = partition(arr, low, high);

		if (pivot - 1 > low)
		{
			stack.push(low);
			stack.push(pivot - 1) ;
		}

		if (pivot + 1 < high)
		{
			stack.push(pivot + 1);
			stack.push(high);
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	
	int* N = new int[10];
	for (int i = 0; i < _msize(N)/sizeof(int); i++)
		N[i] = rand() % 10000 + 1;

	for (int i = 0; i < 10; i++)
		cout << N[i] << " ";
	cout << endl;

	int* K = new int[1000];
	for (int i = 0; i < _msize(K) / sizeof(int); i++)
		K[i] = rand() % 10000 + 1;

	quickSort(N, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << N[i] << " ";
	cout << endl;

	


	
	cout << endl;


}