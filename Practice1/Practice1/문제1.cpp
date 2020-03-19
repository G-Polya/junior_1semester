#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;

template<typename T>
void accmulate_average(vector<T> vec)
{
	double sum = 0;
	cout << "Avr 출력" << endl;
	
	for (size_t i = 0; i < vec.size(); i++)
	{
		sum += vec[i];

		cout << " Avr["<<i<<"]: "<<sum/(i+1) << endl;
	
	}
	

}

int main()
{
	vector<int> vec;
	cout << "배열을 입력해주세요(입력을 종료하려면 Ctrl+Z): ";
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(vec));
	cout << endl << endl;
	
	accmulate_average(vec);
}