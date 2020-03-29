#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <map>
#include <tuple>
using namespace std;


// define GreedyBetterChange
// M : total Money
// c : coinList
// d : length of coinList
void GreedBetterChange(int M, vector<int> c, int d)
{
	vector<int> k(d, 0);	// k1,k2,...kd

	sort(c.begin(), c.end());	// Ȥ�� coinList�� ���ĵ��� �ʾҴٸ� ���� �����Ѵ�  


	//�˰��� ����
	for (int i = d - 1; i >= 0; i--)	
	{
		k[i] = M / c[i];		// ū ���κ��� ���
		M = M - c[i] * k[i];	// ������ money���� ���� ���θ�ŭ�� ���� ����

	}

	
	// ���
	for (int i = 0; i < d; i++)
	{
		cout << c[i] << ": " << k[i] << endl;
	}

}

// dicionary�ʱ�ȭ�� ���� �Լ�
void build_Dict(vector<int> coinValueList, map<int, int> coinDict)
{
	for (auto& coin : coinValueList)
		coinDict[coin] = 0;
}


// define BruteForceChange
// coinValueList : coinlist. ex) (25 20 10 5 1)
// numCoins : ���ΰ���
// coinDict : ��������(��ųʸ�)
tuple<int, map<int, int>> BruteForceChange(vector<int> coinValueList, int total, int numCoins, map<int, int> coinDict, bool build)
{
	sort(coinValueList.begin(), coinValueList.end());		// Ȥ�� coinValueList�� ���ĵ��� �ʾҴٸ� ���� ����

	if (build == true)						
		build_Dict(coinValueList, coinDict);		// ��ųʸ� 0���� �ʱ�ȭ 

	if (total == 0)			// total money�� 0�� �Ǹ�  
		return tuple<int, map<int, int>>(numCoins, coinDict);	// ���� ���� ������ ���������� ��ȯ

	// ã�����ϴ� ���� ������ �������� �ʱ�ȭ
	int bestCoins = -1;
	map<int, int> bestDict;


	// coinValueList��ŭ �ݺ�
	for (size_t i = 0; i < coinValueList.size(); i++)
	{
		map<int, int> dictCopy;			//�ӽ� ��ųʸ�

		for (auto& coin : coinValueList)
			dictCopy[coin] = coinDict[coin];

		int coin = coinValueList[i];

		if (coin <= total)
		{
			dictCopy[coin] += 1;		// �ش����ο� �ش��ϴ� ��ųʸ��� value�� 1����. ���� ��� dictCopy[25]�� 1���� ��� >> 25�� key�� ������ value�� 1���� ��ٴ� ��.
			tuple<int, map<int, int>> temp_tuple = BruteForceChange(coinValueList, total - coin, numCoins + 1, dictCopy, false);	// recursion, build parameter�� false�� �ϴ°��� 0���� �ʱ�ȭ�� ����
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

	// �ݾ� �Է�
	int total;
	cout << "�� �ݾ��� �Է��Ͻÿ�: ";
	cin >> total;
	getchar();


	// ���� ���� �Է�
	vector<int> coinValueList;
	cout << "������ ������ �Է��Ͻÿ�(�Է��� �����Ϸ��� Ctrl+Z): ";
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(coinValueList));


	int d = coinValueList.size();
	map<int, int> coinDict;

	//Greed Better Change ���
	cout << "Greed Better Change: " << endl;
	GreedBetterChange(total, coinValueList, d);

	cout << "=========================" << endl;


	// Brute Force Change ���
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
