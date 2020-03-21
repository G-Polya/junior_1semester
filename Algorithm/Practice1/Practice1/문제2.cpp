#include <iostream>
#include <vector>
#include <algorithm>
<<<<<<< HEAD
<<<<<<< HEAD:Algorithm/Practice1/Practice1/ë¬¸ì œ2.cpp
#include <iterator>
#include <iomanip>
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


// define BruteForceChange
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
	vector<int> M(100, 0);
	vector<int> c;

	cout << "ÄÚÀÎ Á¾·ù¸¦ ÀÔ·ÂÇÏ½Ã¿À(ÀÔ·ÂÀ» Á¾·áÇÏ·Á¸é Ctrl+Z): ";
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(c));
	int d = c.size();

	for (int i = 0; i < 100; i++)
	{
		M[i] = i + 1;
		vector<int> gbc = GreedBetterChange(M[i], c, d);
		vector<int> bfc = BruteForceChange(M[i], c, d);
		cout.width(5);
		cout.fill(' ');
		cout << endl << setw(5) << "M : " << M[i] << " | Greed Better Change: ";
		copy(gbc.begin(), gbc.end(), ostream_iterator<int>(cout, " "));
		cout << "| Brute Force Change:";
		copy(gbc.begin(), gbc.end(), ostream_iterator<int>(cout, " "));



	}

	cout << endl;

	return 0;
}
=======
#include 
>>>>>>> Generalization_of_M:Algorithm/Algorithm/ì†ŒìŠ¤.cpp
=======
#
>>>>>>> from_LeetCode
