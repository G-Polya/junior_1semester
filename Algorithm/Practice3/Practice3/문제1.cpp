#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& list, int left, int mid, int right) 
{
	vector<int> sorted(list.size(), 0);
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	/* ���� ���ĵ� list�� �պ� */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	// ���� �ִ� ������ �ϰ� ����
	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else 
	{
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	// �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}

// �պ� ����
void merge_sort(vector<int>& list, int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
		merge_sort(list, left, mid); // ���� �κ� ����Ʈ ���� -����(Conquer)
		merge_sort(list, mid + 1, right); // ���� �κ� ����Ʈ ���� -����(Conquer)
		merge(list, left, mid, right); // ���ĵ� 2���� �κ� �迭�� �պ��ϴ� ���� -����(Combine)
	}
}

int main()
{
	vector<int> list = { 21, 10, 12, 20, 25, 13, 15, 22 };
	int size = list.size();
	merge_sort(list, 0,  size - 1);

	// ���� ��� ���
	for (int i = 0; i < list.size(); i++) 
	{
		cout << list[i] << " ";
	}
	cout << endl;

	return 0;
}
