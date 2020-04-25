#include <iostream>
#include <string>
#include <iomanip>
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
node* treeInsert(node* root, int xkey)
{
	if (root == NULL)
	{
		root = new node;
		root->l = root->r = NULL;
		root->key = xkey;
		return root;
	}
	else
	{
		if (root->key > xkey)
			root->l = treeInsert(root->l, xkey);
		else
			root->r = treeInsert(root->r, xkey);
	}

	return root;
}

// 이진탐색트리에서 키삭제
// head : 키를 삭제할 트리
// xkey : 삭제될 키
node* treeDel(node* head, int xkey)
{
	node* p, * c, * t, * x;
	p = head;
	x = head->r;
	x = treeSearch(x, xkey);		// xkey와 동일한 key를 갖는 노드 x찾기
	

	if (x == NULL)
		return NULL;
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

	return t;

}

#define COUNT 5
void print2DUtil(node* root, int space)
{
	// base case of recursion
	if (root == NULL)
		return;

	// 계층간의 거리 증가
	space += COUNT;

	// 오른쪽 자식노드에 대해서 먼저 수행
	print2DUtil(root->r, space);

	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << "  ";
	cout << root->key << "\n";

	// 왼쪽 자식 수행
	print2DUtil(root->l, space);


}




int main()
{
	cout << "Commands: " << endl;
	cout << "+ key : Insert(or update) element" << endl;
	cout << "? key : Retrieve element" << endl;
	cout << "- key : Remove element" << endl;
	cout << "Q     : Quit the test program" << endl;
	bool flag = true;

	node* root = treeInit();

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
			cout << "insert : key = " << key << endl;
			root = treeInsert(root, key);
			print2DUtil(root, 0);
			break;
		case '-':
			root = treeDel(root, key);
			print2DUtil(root,0);
			break;
		case '?':
		{
			node* retreived = treeSearch(root, key);
			cout << "left child is " << retreived->l->key << endl;
			cout << "right child is " << retreived->r->key << endl;
			break; 
		}
		case 'Q':
			cout << "Quit" << endl;
			flag = false;
			break;
		}
	}

	
}