#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <map>
#include <tuple>
using namespace std;


// define GreedyBetterChange
void GreedBetterChange(int M, vector<int> c, int d)
{
	vector<int> k(d, 0);

	reverse(begin(c), end(c));
	for (int i = d - 1; i >= 0; i--)
	{
		k[i] += M / c[i];
		M = M - c[i] * k[i];

	}

	reverse(begin(k), end(k));


	for (int i = 0; i < d; i++)
	{
		cout << c[i] << ": " << k[i] << endl;
	}

}

void build_Dict(vector<int> coinValueList, map<int, int> coinDict)
{
	for (auto& coin : coinValueList)
		coinDict[coin] = 0;
}


// define BruteForceChange
tuple<int, map<int, int>> BruteForceChange(vector<int> coinValueList, int total, int numCoins, map<int, int> coinDict, bool build)
{
	if (build == true)
		build_Dict(coinValueList, coinDict);

	if (total == 0)
		return tuple<int, map<int, int>>(numCoins, coinDict);

	int bestCoins = -1;
	map<int, int> bestDict;

	for (size_t i = 0; i < coinValueList.size(); i++)
	{
		map<int, int> dictCopy;

		for (auto& coin : coinValueList)
			dictCopy[coin] = coinDict[coin];

		int coin = coinValueList[i];

		if (coin <= total)
		{
			dictCopy[coin] += 1;
			tuple<int, map<int, int>> temp_tuple = BruteForceChange(coinValueList, total - coin, numCoins + 1, dictCopy, false);
			int subCoins = get<0>(temp_tuple);
			map<int, int> subDict = get<1>(temp_tuple);

			if (bestCoins == -1 || subCoins < bestCoins)
			{
				bestCoins = subCoins;
				bestDict = subDict;
			}
		}
	}

	tuple<int, map<int, int>> result_tuple = make_tuple(bestCoins, bestDict);

	return result_tuple;

}

int main()
{
	int total;
	cout << "총 금액을 입력하시오: ";
	cin >> total;
	getchar();


	vector<int> coinValueList;
	cout << "코인의 종류를 입력하시오(입력을 종료하려면 Ctrl+Z): ";
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(coinValueList));


	int d = coinValueList.size();
	map<int, int> coinDict;


	cout << "Greed Better Change: " << endl;
	GreedBetterChange(total, coinValueList, d);

	cout << "=========================" << endl;

	tuple<int, map<int, int>> bfc = BruteForceChange(coinValueList, total, 0, coinDict, true);
	int result_coins = get<0>(bfc);
	map<int, int> result_dict = get<1>(bfc);

	cout << "Brute Force Change: " << endl;

	for (auto iter = result_dict.begin(); iter != result_dict.end(); iter++)
	{
		cout << iter->first << " : " << iter->second << endl;
	}

	cout << endl;


	return 0;
}
