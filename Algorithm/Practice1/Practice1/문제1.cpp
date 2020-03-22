#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;

// 누적평균을 구하는 함수
template<typename T>
void accmulate_average(vector<T> vec)	//vector(동적배열)를 원소로 받는다
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
	vector<int> vec;	// vector(배열)
	cout << "배열을 입력해주세요(입력을 종료하려면 Ctrl+Z): ";
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(vec)); // 입력
	cout << endl << endl;
	
	accmulate_average(vec);	// 출력
}