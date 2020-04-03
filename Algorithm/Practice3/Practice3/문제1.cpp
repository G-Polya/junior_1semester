#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printArray(vector<int> list)
{
	for (int i = 0; i < list.size(); i++)
		cout << setw(5)<<list[i] << " ";
	cout << endl;
}
void merge(vector<int>& list, int left, int mid, int right)
{
	vector<int> sorted(list.size(), 0);
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;
	
	/* ���� ���ĵ� list�� �պ� */
	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// ���� �ִ� ������ �ϰ� ����
	if (i > mid)
	{
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else
	{
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	// �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
	for (l = left; l <= right; l++)
	{
		list[l] = sorted[l];
	}
	printArray(sorted);
	
}

// �պ� ����
void recursive_mergeSort(vector<int>& list, int left, int right) 
{
	int mid;
	

	if (left < right) {
		mid = (left + right) / 2; // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
		recursive_mergeSort(list, left, mid); // ���� �κ� ����Ʈ ���� -����(Conquer)
		
		recursive_mergeSort(list, mid + 1, right); // ���� �κ� ����Ʈ ���� -����(Conquer)
		
		merge(list, left, mid, right); // ���ĵ� 2���� �κ� �迭�� �պ��ϴ� ���� -����(Combine)
	}
}
int min(int x, int y)
{
	return (x < y) ? x : y;
}

// https://www.techiedelight.com/iterative-merge-sort-algorithm-bottom-up/
void iterative_mergeSort(vector<int>& list, int left, int right)
{
	for (int m = 1; m < right - left; m *= 2)
	{
		for (int i = left; i < right; i += 2 * m)
		{
			int from = i;
			int mid = i + m - 1;
			int to = min(i + 2 * m - 1, right);
			merge(list, from, mid, to);
		}
	}
}


int main()
{
	vector<int> list = { 30, 20, 40, 35, 5, 50, 45, 15 };
	int size = list.size();
	vector<int> copy_list = list;
	cout << "Original: " << endl;
	printArray(list);
	cout << "Start recursive merge Sort..." << endl;
	recursive_mergeSort(list, 0, size - 1);

	cout << "Copy:" << endl;
	printArray(copy_list);
	iterative_mergeSort(copy_list,0,size-1);
	
	// ���� ��� ���
	printArray(copy_list);

	return 0;
}
