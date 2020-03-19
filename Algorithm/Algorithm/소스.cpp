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
	cout << "smallestNumberOfCoin: " << smallestNumberOfCoins << endl;

	vector<int> bestchange(d, 0);

	for (int i = 0; i < d; i++)
	{

		//	cout << "k[" << i << "] : " << k[i] << endl;
		for (int m = k[i]; m <= M / c[i]; m++)
		{
			int valuesOfCoins = 0;
			cout << "k[" << i << "], M/c[" << i << "] : " << m << ", " << M / c[i] << endl;
			/*for (int j = 0; j < 5; j++)
			{
				cout << c[j] << " ";
			}

			cout << endl;
*/


//cout << "m: " << m <<" c: "<<c[i] << endl;

			valuesOfCoins += c[i] * m;




			if (valuesOfCoins == M)
			{
				cout << "valuesOfCoins: " << valuesOfCoins << endl << endl;


				int numberOfCoins = 0;
				for (int n = 0; n <= m; n++)
				{

					numberOfCoins += n;
					cout << "m : " << m << endl;
					cout << "numberofCoins: " << numberOfCoins << endl;

				}
				cout << "smallestNumberOfCoin: " << smallestNumberOfCoins << ", numberofCoins: " << numberOfCoins << endl;


				if (numberOfCoins < smallestNumberOfCoins)
				{
					smallestNumberOfCoins = numberOfCoins;

					cout << "smallestNumberOfCoin: " << smallestNumberOfCoins << endl;
					bestchange[i] = m;

				}
			}

		}
		cout << endl;
		cout << "=========================" << endl;

		//cout<<"\nvalue of coins : "<<valuesOfCoins << endl;
	}
	cout << endl;
	return bestchange;
}

int main()
{
	int M = 45;
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