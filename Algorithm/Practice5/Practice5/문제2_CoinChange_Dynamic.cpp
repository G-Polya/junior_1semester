k//2016112158 김희수
#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;


// 최소의 동전 개수 반환
void minCoins(vector<int> coins, int amount)
{
	int* table = new int[amount + 1];	// 동전의 최소개수를 저장할 배열 table
	table[0] = 0;	// amount =0 일떄

	for (int i = 1; i <= amount; i++)		// table의 배열의 값들을 초기화
		table[i] = INT_MAX;

	for (int i = 1 ; i <= amount; i++)		//예를 들어 1~11에 대해
	{
		for (int j = 0; j < coins.size(); j++)		// 코인의 종류 모두에 대해서.. 1,4,7에 대해
		{
			if (coins[j] <= i)		// 현재 코인이 작으면 다음을 수행. 수업시간에 설명했던 내용. 1~11을 키로 갖는 표가 나오면서 value로는 1,2,1,2,1...이렇게 갖게 되는 과정
			{
				int sub_res = table[i - coins[j]];	
				if (sub_res != INT_MAX && sub_res + 1 < table[i])	
					table[i] = sub_res + 1;
			}
		}
	}


	// 출력
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