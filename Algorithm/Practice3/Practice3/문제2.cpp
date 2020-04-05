#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void swap(int  &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void make_heap(vector<int> &arr, int root ,int lastNode)
{
	int parent, leftSon, rightSon, son, rootValue;

	parent = root;
	rootValue = arr[root];
	leftSon = 2 * parent + 1;
	rightSon = leftSon + 1;

	while (leftSon <= lastNode)
	{
		if (rightSon <= lastNode && arr[leftSon] < arr[rightSon])
			son = rightSon;
		else
			son = leftSon;
		
		if (rootValue < arr[son])
		{
			arr[parent] = arr[son];
			parent = son;
			leftSon = parent * 2 + 1;
			rightSon = leftSon + 1;
		}
		else
			break;
	}

	arr[parent] = rootValue;

}

void printArray(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << setw(3)<<arr[i] << " ";
	cout << endl;
}

void heapSort(vector<int> &arr)
{
	int size = arr.size();
	int i;

	for (i = size / 2; i >= 0; i--)
		make_heap(arr, i, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);

		make_heap(arr, 0, size - 1);
	}
}

int main()
{
	vector<int> a = { 4,1,3,2,16,9,10,14,8,7 };
	printArray(a);
	heapSort(a);
	printArray(a);

}