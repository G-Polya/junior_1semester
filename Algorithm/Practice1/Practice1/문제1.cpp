#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;

// ��������� ���ϴ� �Լ�
template<typename T>
void accmulate_average(vector<T> vec)	//vector(�����迭)�� ���ҷ� �޴´�
{
	double sum = 0;
	cout << "Avr ���" << endl;
	
	for (size_t i = 0; i < vec.size(); i++)
	{
		sum += vec[i];			// �迭���ҵ��� ���� ��.

		cout << " Avr["<<i<<"]: "<<sum/(i+1) << endl;	// i+1�� ����� ����� ���Ѵ�
	
	}
	

}

int main()
{
	vector<int> vec;	// vector(�迭)
	cout << "�迭�� �Է����ּ���(�Է��� �����Ϸ��� Ctrl+Z): ";
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(vec)); // �Է�
	cout << endl << endl;
	
	accmulate_average(vec);	// ���
}