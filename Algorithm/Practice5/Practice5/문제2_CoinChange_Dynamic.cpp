//2016112158 ±èÈñ¼ö
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

void Dynamic_CoinChange(vector<int> arr, int amount)
{
	map<int, int> amount_dict;
	for (int i = 1; i < amount + 1; i++)
	{
		amount_dict.insert(make_pair(i, 0));
	}
	
	for (auto it = amount_dict.begin(); it != amount_dict.end(); it++) {
		cout << "key : " << it->first << " " << "value : " << it->second << '\n';
	}
}

int main()
{
	vector<int> coins = { 1,4,7 };
	int amount = 11;

	Dynamic_CoinChange(coins, amount);
}