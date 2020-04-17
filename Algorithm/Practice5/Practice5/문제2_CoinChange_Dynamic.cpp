//2016112158 �����
#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

void printArray(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << setw(5)<<arr[i];
	cout << endl;
}

// �ּ��� ���� ���� ��ȯ
int minCoins(vector<int> coins, int amount)
{
	// base
	if (amount == 0)
		return 0;

	int res = INT_MAX;

	for (int i = 0; i < coins.size(); i++)				
	{
		if (coins[i] <= amount)
		{
			int sub_res = minCoins(coins, amount - coins[i]);
		
			if (sub_res != INT_MAX && sub_res + 1 < res)
				res = sub_res + 1;
		}
	}

	return res;
}

void Dynamic_CoinChange(vector<int> arr, int amount)
{
	// 1~11�� key�� ���� ��ųʸ� ����, �ʱ�ȭ
	map<int, int> amount_dict;
	for (int i = 1; i < amount + 1; i++)
	{
		amount_dict.insert(make_pair(i, minCoins(arr, i)));
	}
	


	// ���
	cout << "Keys:  ";
	for (auto it = amount_dict.begin(); it != amount_dict.end(); it++)
	{
		cout << setw(3)<<it->first << " " ;
	}
	cout << endl;
	cout << "Values:";
	for (auto it = amount_dict.begin(); it != amount_dict.end(); it++)
	{
		cout<< setw(3) << it->second << " ";
	}
	cout << endl;
	
}

int main()
{
	vector<int> coins = { 1,4,7 };
	int amount = 11;

	
	Dynamic_CoinChange(coins, amount);
}