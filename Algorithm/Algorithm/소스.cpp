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
	
	int smallestNumberOfCoins = INT32_MAX;
	
	vector<int> bestchange(d, 0);

	for (int i = 0; i < d; i++)
	{

		for (int m = k[i]; m <= M / c[i]; m++)
		{
			int valuesOfCoins = 0;
			
			valuesOfCoins += c[i] * m;




			if (valuesOfCoins == M)
			{
				

				int numberOfCoins = 0;
				for (int n = 0; n <= m; n++)
				{

					numberOfCoins += n;
					
				}
				

				if (numberOfCoins < smallestNumberOfCoins)
				{
					smallestNumberOfCoins = numberOfCoins;
					bestchange[i] = m;
				}
			}

		}

	}
	return bestchange;
}

int main()
{
	vector<int> M(99, 0);
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