#define _CRT_SECURE_NO_WARNINGS
#include "BWT.h"

// componentIds 초기화. table안에 들어있는 스트링들의 번호를 초기화
void BWT::fillUpComponentIds()
{
	for (int i = 0; i < origString.size(); i++)
	{
		componentIds.push_back(i);
	}
}

// 테이블 채워넣는 함수
void BWT::fill_table()
{

	for (int i = 0; i < componentIds.size(); i++)
	{
		table.push_back(make_tuple(componentIds[i], origString));
		string temp = origString.substr(1) + origString[0];
		origString = temp;
	}
}

// table안의 스트링들을 비교해서 정렬
void BWT::SortTable()
{
	string temp_string;		// 스왑에 사용될 임시 스트링
	int temp_Ids;			// 스왑에 사용될 임시 componentId

	for (int step = 0; step < table.size() - 1; step++)
	{
		int len = get<1>(table[step]).length();
		for (int i = 0; i < len - 1 - step; i++)
		{
			//  비교
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



// table안에서 BWTString을 찾는 함수
void BWT::findBWT()
{
	
	for (int i = 0; i < table.size(); i++)
	{
		BWTString += get<1>(table[i])[table.size()-1];
	}
	
}




// 새로운 노드 생성
node* getNode(int i)
{
	node* nn = new node();
	nn->data = i;
	nn->next = NULL;
	return nn;
}

// l_shift계산하는 함수. 
void computeLShift(node** head, int index, int* l_shift)
{
	l_shift[index] = (*head)->data; //l_shift[index] 값은 연결리스트의 노드의 데이터. 즉, BWTString에서 각 문자의 상대적 위치다. 
	(*head) = (*head)->next;
}

// 스트링의 문자를 정렬
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


// $가 나타나는 인덱스 반환
int BWT::find_dollar()
{
	for (int i = 0; i < BWTString.length(); i++)
		if (BWTString[i] == '$')
			return i;
}



// BWT를 기반으로 원래 스트링 복원
void BWT::reconstruct()
{	
	int len_bwt = BWTString.length();
	string first_column = SortString(BWTString);
	cout <<"first column : "<< first_column << endl;
	int* l_shift = new int[len_bwt];		//first column의 문자에 해당하는 BWTString의 문자를 저장하는 배열.
	/* acaacg$를 예로 들면 first column은 $aaaccg가 된다. l_shift의 인덱스는 first column의 원소를 가리킨다. 
	 l_shift[0]에는 first column의 0번째 문자에 해당하는 $를 BWTString에서 찾아서 그 인덱스를 저장한다. 따라서 l_shift[0] = 2
	 l_shift[1]에는 first column의 1번째 문자에 해당하는 a를 BWTString에서 찾아서 그 인덱스를 저장한다. 따라서 l_shift[1] = 3 */
	
	
	node* list[128] = { NULL };	// 연결리스트

	// list에 노드삽입
	for (int i = 0; i < len_bwt; i++)
	{
		node* nn = getNode(i);
		insert_toList(&list[BWTString[i]], nn); // BWTString의 문자를 인덱스로 그 문자의 상대적 위치를 data로 받게 된다.
	}

	// l_shift 계산
	for (int i = 0; i < len_bwt; i++)
		computeLShift(&list[first_column[i]], i, l_shift);	// 연결리스트에서 first_column에 해당하는 문자로 l_shift를 초괴화한다.  
	/* 계산이 완료되면 $의 위치, a의 위치, c의 위치, g의 위치가 연결리스트로 저장된다. */

	int x = find_dollar(); // $를 찾아서 $에 해당하는 인덱스의 l_shift(g)가 출력될 BWTString의 인덱스다

	for(int i = 0; i < len_bwt; i++)
	{
		x = l_shift[x];
		cout << BWTString[x];
		
	}
	cout << endl;

}

// 연결리스트의 끝에 삽입
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



