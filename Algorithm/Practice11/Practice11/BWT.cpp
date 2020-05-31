#define _CRT_SECURE_NO_WARNINGS
#include "BWT.h"

// componentIds �ʱ�ȭ. table�ȿ� ����ִ� ��Ʈ������ ��ȣ�� �ʱ�ȭ
void BWT::fillUpComponentIds()
{
	for (int i = 0; i < origString.size(); i++)
	{
		componentIds.push_back(i);
	}
}

// ���̺� ä���ִ� �Լ�
void BWT::fill_table()
{

	for (int i = 0; i < componentIds.size(); i++)
	{
		table.push_back(make_tuple(componentIds[i], origString));
		string temp = origString.substr(1) + origString[0];
		origString = temp;
	}
}

// table���� ��Ʈ������ ���ؼ� ����
void BWT::SortTable()
{
	string temp_string;		// ���ҿ� ���� �ӽ� ��Ʈ��
	int temp_Ids;			// ���ҿ� ���� �ӽ� componentId

	for (int step = 0; step < table.size() - 1; step++)
	{
		int len = get<1>(table[step]).length();
		for (int i = 0; i < len - 1 - step; i++)
		{
			//  ��
			if (get<1>(table[i]) > get<1>(table[i + 1]))
			{
				temp_string = get<1>(table[i]);
				temp_Ids = get<0>(table[i]);

				get<1>(table[i]) = get<1>(table[i + 1]);
				get<0>(table[i]) = get<0>(table[i + 1]);

				get<1>(table[i + 1]) = temp_string;
				get<0>(table[i + 1]) = temp_Ids;
			}
		}
	}
}



// table�ȿ��� BWTString�� ã�� �Լ�
void BWT::findBWT()
{
	
	for (int i = 0; i < table.size(); i++)
	{
		BWTString += get<1>(table[i])[table.size()-1];
	}
	
}




// ���ο� ��� ����
node* getNode(int i)
{
	node* nn = new node();
	nn->data = i;
	nn->next = NULL;
	return nn;
}

// l_shift����ϴ� �Լ�. 
void computeLShift(node** head, int index, int* l_shift)
{
	l_shift[index] = (*head)->data; //l_shift[index] ���� ���Ḯ��Ʈ�� ����� ������. ��, BWTString���� �� ������ ����� ��ġ��. 
	(*head) = (*head)->next;
}

// ��Ʈ���� ���ڸ� ����
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


// $�� ��Ÿ���� �ε��� ��ȯ
int BWT::find_dollar()
{
	for (int i = 0; i < BWTString.length(); i++)
		if (BWTString[i] == '$')
			return i;
}



// BWT�� ������� ���� ��Ʈ�� ����
void BWT::reconstruct()
{	
	int len_bwt = BWTString.length();
	string first_column = SortString(BWTString);
	cout <<"first column : "<< first_column << endl;
	int* l_shift = new int[len_bwt];		//first column�� ���ڿ� �ش��ϴ� BWTString�� ���ڸ� �����ϴ� �迭.
	/* acaacg$�� ���� ��� first column�� $aaaccg�� �ȴ�. l_shift�� �ε����� first column�� ���Ҹ� ����Ų��. 
	 l_shift[0]���� first column�� 0��° ���ڿ� �ش��ϴ� $�� BWTString���� ã�Ƽ� �� �ε����� �����Ѵ�. ���� l_shift[0] = 2
	 l_shift[1]���� first column�� 1��° ���ڿ� �ش��ϴ� a�� BWTString���� ã�Ƽ� �� �ε����� �����Ѵ�. ���� l_shift[1] = 3 */
	
	
	node* list[128] = { NULL };	// ���Ḯ��Ʈ

	// list�� ������
	for (int i = 0; i < len_bwt; i++)
	{
		node* nn = getNode(i);
		insert_toList(&list[BWTString[i]], nn); // BWTString�� ���ڸ� �ε����� �� ������ ����� ��ġ�� data�� �ް� �ȴ�.
	}

	// l_shift ���
	for (int i = 0; i < len_bwt; i++)
		computeLShift(&list[first_column[i]], i, l_shift);	// ���Ḯ��Ʈ���� first_column�� �ش��ϴ� ���ڷ� l_shift�� �ʱ�ȭ�Ѵ�.  
	/* ����� �Ϸ�Ǹ� $�� ��ġ, a�� ��ġ, c�� ��ġ, g�� ��ġ�� ���Ḯ��Ʈ�� ����ȴ�. */

	int x = find_dollar(); // $�� ã�Ƽ� $�� �ش��ϴ� �ε����� l_shift(g)�� ��µ� BWTString�� �ε�����

	for(int i = 0; i < len_bwt; i++)
	{
		x = l_shift[x];
		cout << BWTString[x];
		
	}
	cout << endl;

}

// ���Ḯ��Ʈ�� ���� ����
void insert_toList(node** head, node* nn)
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



