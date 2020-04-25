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

// 트리의 높이를 구하는 함수
int getHeight(node* tree)
{
	if (tree)
	{
		int lheight = getHeight(tree->l);
		int rheight = getHeight(tree->r);
		if (lheight > rheight)
			return lheight + 1;
		else
			return rheight + 1;
	}
	return -1;
}

void padding(char ch, int n)
{
	for (int i = 0; i < n; i++)
		putchar(ch);
}

#define pow2(n) (1 << (n))
void displayTree(node* root)
{
	node** row1, ** row2, ** rowtemp;
	int rows, row, col;

	if (root == NULL)
		return;

	rows = getHeight(root);
	row1 = new node*[pow2(rows)];
	row2 = new node * [pow2(rows];
	row1[0] = root;

	for (row = 0; row < rows; row++)
	{
		int col2 = 0, cols = pow2(row);
		cout << pow2(rows - (row + 1));


	}
}


int main()
{
	cout << "Commands: " << endl;
	cout << "+ key : Insert(or update) element" << endl;
	cout << "? key : Retrieve element" << endl;
	cout << "- key : Remove element" << endl;
	cout << "Q     : Quit the test program" << endl;
	bool flag = true;

	node* root = NULL;

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
			root = treeInsert(root, key);
			displayTree(root);
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

	
}