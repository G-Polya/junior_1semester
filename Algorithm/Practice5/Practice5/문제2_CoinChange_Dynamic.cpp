k//2016112158 �����
#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;


// �ּ��� ���� ���� ��ȯ
void minCoins(vector<int> coins, int amount)
{
	int* table = new int[amount + 1];	// ������ �ּҰ����� ������ �迭 table
	table[0] = 0;	// amount =0 �ϋ�

	for (int i = 1; i <= amount; i++)		// table�� �迭�� ������ �ʱ�ȭ
		table[i] = INT_MAX;

	for (int i = 1 ; i <= amount; i++)		//���� ��� 1~11�� ����
	{
		for (int j = 0; j < coins.size(); j++)		// ������ ���� ��ο� ���ؼ�.. 1,4,7�� ����
		{
			if (coins[j] <= i)		// ���� ������ ������ ������ ����. �����ð��� �����ߴ� ����. 1~11�� Ű�� ���� ǥ�� �����鼭 value�δ� 1,2,1,2,1...�̷��� ���� �Ǵ� ����
			{
				int sub_res = table[i - coins[j]];	
				if (sub_res != INT_MAX && sub_res + 1 < table[i])	
					table[i] = sub_res + 1;
			}
		}
	}


	// ���
	cout << "Keys:   ";
	for (int i = 1; i < amount + 1; i++)
		cout << setw(5) << i;

	cout << "\nValues: ";
	for (int i = 1; i < amount + 1; i++)
		cout << setw(5) << table[i];
	cout << endl;

	delete table;
}



int main()
{
	vector<int> coins = { 1,4,7 };
	int amount = 11;

	minCoins(coins, amount);
	
	return 0;
}