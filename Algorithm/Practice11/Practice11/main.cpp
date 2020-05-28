#include "BWT.h"

// https://www.geeksforgeeks.org/inverting-burrows-wheeler-transform/

void print_table(vector<tuple<int, string>> tab)
{
	for (int i = 0; i < tab.size(); i++)
	{
		cout << get<0>(tab[i]) << " " << get<1>(tab[i]) << endl;
	}
}

int main()
{
	cout << "---------------Original String---------------" << endl;
	string s1 = "missisippi";
	s1 += "$";
	cout << s1 << endl;

	BWT bwt;
	bwt.origString = s1;
	int compSize = 0;


	bwt.fillUpComponentIds();

	cout << "---------------------Fill the Table----------------------" << endl;
	bwt.fill_table();
	print_table(bwt.table);

	cout << "---------------------Sort----------------------" << endl;
	bwt.SortTable();
	print_table(bwt.table);
	bwt.findBWT();
	cout << endl;
	cout << "BWT String: " << bwt.BWTString<< endl;
	
	cout << "----------------------Restore---------------------" << endl;
	bwt.restore();
	
	return 0;
}