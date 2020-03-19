#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


// define GreedyBetterChange

vector<int> GreedBetterChange(int M, vector<int> c, int d)
{
	vector<int> k(d, 0);

	reverse(begin(c), end(c));
	for (int i = d - 1; i >= 0; i--)
	{
		k[i] += M / c[i];
		M = M - c[i] * k[i];

	}

	reverse(begin(k), end(k));

	return k;
}

vector<int> BruteForceChange(int M, vector<int> c, int d)
{
	vector<int> k(d, 0);
	//reverse(begin(c), end(c));

	int smallestNumberOfCoins = INT32_MAX;
	//for (int k0 = 0; k0 < M / c[0]; k0++)
	//{
	//	for (int k1 = 0; k1 < M / c[1]; k1++)
	//	{
	//		for (int k2 = 0; k2 < M / c[2]; k2++)
	//		{
	//			for (int k3 = 0; k3 < M / c[3]; k3++)
	//			{
	//				for (int k4 = 0; k4 < M / c[4]; k4++)
	//				{

	//				}
	//			}
	//		}
	//	}
	//}

	vector<int> bestchange(d, 0);

	for (int i = 0; i < d; i++)
	{
		//	cout << "k[" << i << "] : " << k[i] << endl;
		for (k[i]; k[i] < M / c[i]; k[i]++)
		{
			int valuesOfCoins = 0;

			cout << "[" << i << "], M/c[" << i << "] : " << k[i] << ", " << M / c[i] << endl;
			for (int j = 0; j < 5; j++)
			{
				cout << c[j] << " ";
			}

			cout << endl;

			for (int j = 0; j < 5; j++)
			{
				cout << k[j] << " ";
			}
			cout << endl;


			for (int j = 0; j < 5; j++)
			{
				valuesOfCoins += c[j] * k[j];

			}
				cout <<  valuesOfCoins << endl;


			if (valuesOfCoins == M)
			{
				//cout << <<valuesOfCoins << endl;


				int numberOfCoins = 0;
				for (int n = 0; n < d; n++)
				{
					numberOfCoins += k[i];
					cout << "numberofCoins: " << numberOfCoins << endl;

				}
				if (numberOfCoins < smallestNumberOfCoins)
				{
					smallestNumberOfCoins = numberOfCoins;
					k[i]++;
					cout << smallestNumberOfCoins << " " << k[i] << endl;

				}
			}

		}
		cout << endl;
		//cout<<"\nvalue of coins : "<<valuesOfCoins << endl;
	}
	cout << endl;
	return k;
}

int main()
{
	int M = 40;
	vector<int> c = { 25,20,10,5,1 };
	int d = c.size();


	// GreedyBetterChange
	vector<int> gbc = GreedBetterChange(M, c, d);
	copy(gbc.begin(), gbc.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// BruteForceChange
	vector<int> bfc = BruteForceChange(M, c, d);
	copy(bfc.begin(), bfc.end(), ostream_iterator<int>(cout, " "));

	cout << endl;


}