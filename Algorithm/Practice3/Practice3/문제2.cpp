// 2016112158 �����
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

	// �� �ʱⰪ ����
	parent = root;					// �θ� �ε���
	rootValue = arr[root];			// �θ� �ε����� �ش��ϴ� ����
	leftSon = 2 * parent + 1;		// ���� �ڽ� �ε���
	rightSon = leftSon + 1;			// ������ �ڽ� �ε���

	while (leftSon <= lastNode)
	{
		if (rightSon <= lastNode && arr[leftSon] < arr[rightSon])	// ������ �ε����� ��������庸�� �۰�, �����ε����� ���Ұ� ������ �ε����� ���Һ��� ������
			son = rightSon;			// �ش� �ε����� �ڽ�(�ӽ�)���� ������
		else
			son = leftSon;
		
		if (rootValue < arr[son])		// �ڽ��ε����� ���Һ��� �θ��� ���Ұ� ������
		{
			arr[parent] = arr[son];		// ���� �ٲ�.. ū������ ��带 ���� �ø��ٰ� �ؾ��ϳ�?
			parent = son;				
			leftSon = parent * 2 + 1;  // ����, ������ �ڽĳ�� ���ʱ�ȭ
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
		make_heap(arr, i, size - 1);	// �����ϰ��� �ϴ� �迭�� ������ ��ȯ

	for (i = size - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);			// ���� �ִ밪�� �����ϰ� arr[i]�� ��ȯ
			
		make_heap(arr, 0, size - 1);	// ���� ���ҷ� �ٽ� �� ������
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