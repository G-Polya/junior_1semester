#include "BWT.h"


void BWT::findBWT()
{
	for (int i = 0; i < origString.length(); i++)
	{
		if (componentIds[i] > 0)
			BWTString.push_back(origString[componentIds[i] - 1]);
		else
			BWTString.push_back(origString[origString.length() - 1]);
	}
}

void BWT::fill_table()
{

	for (int i = 0; i < componentIds.size(); i++)
	{
		table.push_back(make_tuple(componentIds[i], origString));
		string temp = origString.substr(1) + origString[0];
		origString = temp;
	}
}

void BWT::findLCPArray()
{
	LCPArray.push_back("\0");
	LCPVal.push_back(-1);

	for (int i = 1; i < componentIds.size(); i++)
	{
		string s1 = origString.substr(componentIds[i - 1]);
		string s2 = origString.substr(componentIds[i]);
		int j = 0;
		string LCPStr = "";
		while (s1[j] == s2[j])
		{
			LCPStr += s1[j];
			j++;
		}
		LCPStr[j] += '\0';
		LCPArray.push_back(LCPStr);
		LCPVal.push_back(j);
	}
}


void BWT::Sort()
{
	string temp_string;
	int temp_int;

	for (int step = 0; step < table.size()-1; step++)
	{
		for (int i = 0; i < table.size()-1-step; i++)
		{
			if (get<1>(table[i]) > get<1>(table[i + 1]))
			{
				temp_string = get<1>(table[i]);
				temp_int = get<0>(table[i]);

				get<1>(table[i]) = get<1>(table[i+1]);
				get<0>(table[i]) = get<0>(table[i + 1]);

				get<1>(table[i+1]) = temp_string;
				get<0>(table[i + 1]) = temp_int;
			}
		}
	}
}


void BWT::fillUpComponentIds()
{
	for (int i = 0; i < origString.size(); i++)
	{
		componentIds.push_back(i);
	}
}

void BWT::findSuperMaximalRepeats()
{
	fstream fout;
	fout.open("out.txt", ios::out);
	bool currentUp = false, currDown = false;
	int startInt = -1, endInt = -1;
	cout << endl << "Supermaximal repeats:" << endl;
	for (int i = 0; i < LCPVal.size() - 1; i++)
	{
		//if (!currentUp && bwt.LCPVal[i+1] < 3)
		//break;
		if (i + 1 != LCPVal.size() && LCPVal[i] < LCPVal[i + 1])
		{
			currentUp = true;
			startInt = i;
			endInt = i + 1;
		}
		if (currentUp)
		{
			if (LCPVal[i] == LCPVal[i + 1])
			{
				endInt = i + 1;
			}
			else if (LCPVal[i] > LCPVal[i + 1])
			{
				currentUp = false;
				currDown = true;
			}
		}
		if (!currentUp && currDown)
		{
			//put stint and endint in file.
			if (endInt - startInt + 1 <= 4 && LCPVal[endInt] > 15) // possiblity for supermaximal repeat
			{
				// check for pairwise distinct
				bool pairWiseDistinct = true;
				for (int j = startInt; j < endInt; j++)
				{
					for (int k = j + 1; k <= endInt; k++)
					{
						if (BWTString[j] == BWTString[k])
						{
							pairWiseDistinct = false;
							break;
						}
					}
				}

				if (fout.is_open() && pairWiseDistinct)
				{
					fout << componentIds[startInt] << "\t" << LCPVal[endInt] << "\t" << origString.substr(componentIds[startInt], LCPVal[endInt]) << endl;
					cout << componentIds[startInt] << "\t" << LCPVal[endInt] << "\t" << origString.substr(componentIds[startInt], LCPVal[endInt]) << endl;
					pairWiseDistinct = false;
					currentUp = false;
					currDown = false;
				}
			}
		}
	}
	fout.close();
}
