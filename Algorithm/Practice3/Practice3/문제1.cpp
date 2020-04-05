// 2016112158 김희수
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

void iterative_mergeSort(vector<int>& list, int left, int right)
{
	int curr_size;		// 합병될 서브정렬의 현재 사이즈
	int left_start;		// 합병될 서브정렬의 시작 인덱스

	for ( curr_size = 1; curr_size < right - left; curr_size *= 2)			// 서브정렬의 현재사이즈를 1로 시작. 2배식 증가시킴
	{
		// curr_size = 1일때, left_start = 0, 2, 4, 6, 8...
		// curr_size = 2일때, left_start = 0, 4, 8,...
		// curr_size = 4일때, left_start = 0, 8, ...
		for (left_start = left; left_start < right; left_start += 2 * curr_size)	// 현재사이즈의 서브정렬과 다른 스타팅포인트
		{
			
			int mid = left_start + curr_size - 1;
			int to = min(left_start + 2 * curr_size - 1, right);

			// 서브정렬 arr[left_start...mid]와 arr[mid+1...to]를 합병
			merge(list, left_start, mid, to);
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

	cout << "Start iterative merge Sort..." << endl;
	printArray(copy_list);
	iterative_mergeSort(copy_list,0,size-1);
	
	
	return 0;
}
