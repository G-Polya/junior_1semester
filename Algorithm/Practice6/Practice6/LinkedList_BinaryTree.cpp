#include <iostream>
#include <string>
using namespace std;


// 트리의 노드
typedef struct node
{
	node* l;
	int key;
	node* r;
} node;

// 트리 초기화
node* treeInit()
{
	node* t, *head;
	head = new node;
	head->l = NULL;
	head->r = NULL;
	head->key = 0;

	return head;
}

// 이진트리 탐색
// head : 이진탐색트리 헤드 포인터
// xkey : 탐색키
node* treeSearch(node* head, int xkey)
{
	node* t;
	t = head->r;
	while (t != NULL)
	{
		if (xkey == t->key)	// 키 찾으면 리턴
			return t;
		if (xkey < t->key)	// 찾고자하는 키가 현재키보다 작으면 왼쪽에서 탐색
			t = t->l;
		if (xkey > t->key)	// 찾고자하는 키가 현재키보다 크면 오른쪽에서 탐색
			t = t->r;
	}
	return NULL;
}

// 이진 탐색 트리 키삽입
// head : 키를 삽입할 트리
// xkey : 삽입될 키
void treeInsert(node* head, int xkey)
{
	node* p, * t;
	p = head;
	t = p -> r;

	while (t != NULL)	// 삽입할 위치 찾기. 부모노드 p 찾기
	{
		p = t;
		if (xkey == t->key)
			return;
		else if (xkey < t->key)
			t = t->l;
		else
			t = t->r;
	}

	// 삽입할 노드 생성
	t = new node;
	t->key = xkey;
	t->l = NULL;
	t->r = NULL;
	
	// 부모 노드의 키값과 비교후 작으면 왼쪽, 크면 오른쪽에 삽입
	if (xkey < p->key)
		p->l = t;
	else
		p->r = t;
}

// 이진탐색트리에서 키삭제
// head : 키를 삭제할 트리
// xkey : 삭제될 키
void treeDel(node* head, int xkey)
{
	node* p, * c, * t, * x;
	p = head;
	x = head->r;
	x = treeSearch(x, xkey);		// xkey와 동일한 key를 갖는 노드 x찾기
	

	if (x == NULL)
		return;
	else
		t = x;

	if (t->r == NULL)		// 오른쪽 자식이 없는 경우
		x = t->l;			
	else if (t->r->l == NULL)	// 오른쪽자식의 왼쪽자식이 없는경우
	{
		x = t->r;
		x->l = t->l;
	}
	else                     // 그 외 나머지 경우
	{
		c = x->r;
		while (c->l->l = NULL)
			c = c->l;
		
		x = c->l;
		c->l = x->r;
		x->l = t->l;
		x->r = t->r;
	}

	delete t;

	// 부모노드의 링크조정
	if (xkey < p->key)
		p->l = x;
	else
		p->r = x;


}

void printTree();


int main()
{
	cout << "Commands: " << endl;
	cout << "+ key : Insert(or update) element" << endl;
	cout << "? key : Retrieve element" << endl;
	cout << "- key : Remove element" << endl;
	cout << "Q     : Quit the test program" << endl;
	bool flag = true;

	node* bst = treeInit();

	while (flag)
	{
		string input;
		cout << "Command: ";
		cin >> input;
		char command = input.c_str()[0];
		int key = stoi(input.substr(1, input.length()));
		switch (command)
		{
		case '+':
			cout << "inert : key = " << key << endl;
			
			break;
		case '-':
			cout << "-" << endl;
			break;
		case 'Q':
			cout << "Quit" << endl;
			flag = false;
			break;
		}
	}

	ㅊㅁㄴㅇ
}