#include "BWT.h"

void print_table(vector<tuple<int, string>> tab)
{
	for (int i = 0; i < tab.size(); i++)
	{
		cout << get<0>(tab[i]) << " " << get<1>(tab[i]) << endl;
	}
}

int main()
{
	string s1 = "missisippi";
	s1 += "$";

	BWT bwt;
	bwt.origString = s1;
	int compSize = 0;


	bwt.fillUpComponentIds();

	cout << "---------------------Fill the Table----------------------" << endl;
	bwt.fill_table();
	print_table(bwt.table);

	cout << "---------------------Sort----------------------" << endl;
	bwt.Sort();
	print_table(bwt.table);
	bwt.findBWT();
	


	cout << "BWT String: " << bwt.get_BWTString() << endl;
	
	
	return 0;
}