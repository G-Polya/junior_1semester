#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> arr,int left, int mid, int right)
{
	vector<int> temp;

	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	if (i > mid)
		for (l = j; l <= right; l++)
			temp[k++] = arr[l];
	
	else
		for (l = i; l < mid; l++)
			temp[k++] = arr[l];

	for (l = left; l <= right; l++)
		arr[l] = temp[l];
}

void recursive_mergeSort(vector<int> arr,int left,int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		recursive_mergeSort(arr, left, mid);
		recursive_mergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}

void no_recursive_mergeSort(int arr[],int left, int right)
{
	
}

void printArray(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> A = { 30,20,40,35,5,50,45,10,25,15 };
	int size = A.size();
	printArray(A);

	recursive_mergeSort(A, 0, size-1);
	
	cout << endl;
	printArray(A);
	cout << endl;

}