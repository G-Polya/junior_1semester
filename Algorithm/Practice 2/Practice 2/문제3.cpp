// 2016112158 ±èÈñ¼ö

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <iterator>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	array<int, 10> N;
	array<int, 1000> K;

	for (int i = 0; i < N.size(); i++)
		N[i] = rand() % 10000 + 1;

	for (int i = 0; i < K.size(); i++)
		K[i] = rand() % 10000 + 1;

	copy(begin(N), end(N), ostream_iterator<int>(cout, " "));
	
	cout << endl;


}