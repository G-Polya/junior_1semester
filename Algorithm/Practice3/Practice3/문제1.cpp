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
	
	/* 분할 정렬된 list의 합병 */
	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// 남아 있는 값들을 일괄 복사
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

	// 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
	for (l = left; l <= right; l++)
	{
		list[l] = sorted[l];
	}
	printArray(sorted);
	
}

// 합병 정렬
void recursive_mergeSort(vector<int>& list, int left, int right) 
{
	int mid;
	

	if (left < right) {
		mid = (left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
		recursive_mergeSort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
		
		recursive_mergeSort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
		
		merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
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
	
	// 정렬 결과 출력
	printArray(copy_list);

	return 0;
}
