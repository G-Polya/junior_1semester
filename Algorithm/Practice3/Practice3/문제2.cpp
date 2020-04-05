// 2016112158 김희수
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

	// 힙 초기값 설정
	parent = root;					// 부모 인덱스
	rootValue = arr[root];			// 부모 인덱스에 해당하는 원소
	leftSon = 2 * parent + 1;		// 왼쪽 자식 인덱스
	rightSon = leftSon + 1;			// 오른쪽 자식 인덱스

	while (leftSon <= lastNode)
	{
		if (rightSon <= lastNode && arr[leftSon] < arr[rightSon])	// 오른쪽 인덱스가 마지막노드보다 작고, 왼쪽인덱스의 원소가 오른쪽 인덱스의 원소보다 작으면
			son = rightSon;			// 해당 인덱스를 자식(임시)으로 가져옴
		else
			son = leftSon;
		
		if (rootValue < arr[son])		// 자식인덱스의 원소보다 부모의 원소가 작으면
		{
			arr[parent] = arr[son];		// 서로 바꿈.. 큰원소의 노드를 위로 올린다고 해야하나?
			parent = son;				
			leftSon = parent * 2 + 1;  // 왼쪽, 오른쪽 자식노드 재초기화
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
		make_heap(arr, i, size - 1);	// 정렬하고자 하는 배열을 힙으로 변환

	for (i = size - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);			// 힙의 최대값을 제거하고 arr[i]와 교환
			
		make_heap(arr, 0, size - 1);	// 남은 원소로 다시 힙 재정비
	}
}

int main()
{
	vector<int> a = { 4,1,3,2,16,9,10,14,8,7 };
	cout << "Original: ";
	printArray(a);
	heapSort(a);
	cout << "After...: ";
	printArray(a);

}