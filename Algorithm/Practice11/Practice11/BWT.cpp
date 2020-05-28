#define _CRT_SECURE_NO_WARNINGS
#include "BWT.h"


void BWT::findBWT()
{
	
	for (int i = 0; i < table.size(); i++)
	{
		BWTString += get<1>(table[i])[table.size()-1];
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


// 货肺款 畴靛 积己
node* getNode(int i)
{
	node* nn = new node();
	nn->data = i;
	nn->next = NULL;
	return nn;
}


void computeLShift(node** head, int index, int* l_shift)
{
	l_shift[index] = (*head)->data;
	(*head) = (*head)->next;
}

string SortString(string str)
{
	string result = str;
	char temp_string;
	

	for (int step = 0; step < str.size() - 1; step++)
	{
		for (int i = 0; i < str.size() - 1 - step; i++)
		{
			if (result[i] > result[i + 1])
			{
				temp_string = result[i];
				
				result[i] = result[i + 1];
				
				result[i + 1] = temp_string;
			}
		}
	}

	return result;
}

int cmpfunc(const void* a, const void* b)
{
	const char* ia = (const char*)a;
	const char* ib = (const char*)b;
	return strcmp(ia, ib);
}

int BWT::find_dollar()
{
	for (int i = 0; i < BWTString.length(); i++)
		if (BWTString[i] == '$')
			return i;
}


void BWT::restore()
{
	int len_bwt = BWTString.length();
	char* bwt_arr = (char*)malloc(len_bwt * sizeof(char));
	strcpy(bwt_arr, BWTString.c_str());

	int i;
	string sorted_bwt = SortString(BWTString);

	int* l_shift = (int*)malloc(len_bwt * sizeof(int));
	
	int x = find_dollar();
	node* arr[128] = { NULL };


	for (i = 0; i < len_bwt; i++)
	{
		node* nn = getNode(i);
		addAtLast(&arr[BWTString[i]], nn);
	}

	for (i = 0; i < len_bwt; i++)
		computeLShift(&arr[sorted_bwt[i]], i, l_shift);

	for(i = 0; i < len_bwt; i++)
	{
		x = l_shift[x];
		cout << bwt_arr[x];
		
	}
	cout << endl;

}

void addAtLast(node** head, node* nn)
{
	if (*head == NULL)
	{
		*head = nn;
		return;
	}
	node* temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = nn;
}

void BWT::SortTable()
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
