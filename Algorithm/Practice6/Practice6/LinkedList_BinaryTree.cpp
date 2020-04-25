#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// Ʈ���� ���
typedef struct node
{
	node* l;
	int key;
	node* r;
} node;

// Ʈ�� �ʱ�ȭ
node* treeInit()
{
	node* t, *head;
	head = new node;
	head->l = NULL;
	head->r = NULL;
	head->key = 0;

	return head;
}

// ����Ʈ�� Ž��
// head : ����Ž��Ʈ�� ��� ������
// xkey : Ž��Ű
node* treeSearch(node* head, int xkey)
{
	node* t;
	t = head->r;
	while (t != NULL)
	{
		if (xkey == t->key)	// Ű ã���� ����
			return t;
		if (xkey < t->key)	// ã�����ϴ� Ű�� ����Ű���� ������ ���ʿ��� Ž��
			t = t->l;
		if (xkey > t->key)	// ã�����ϴ� Ű�� ����Ű���� ũ�� �����ʿ��� Ž��
			t = t->r;
	}
	return NULL;
}

// ���� Ž�� Ʈ�� Ű����
// head : Ű�� ������ Ʈ��
// xkey : ���Ե� Ű
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

// ����Ž��Ʈ������ Ű����
// head : Ű�� ������ Ʈ��
// xkey : ������ Ű
void treeDel(node* head, int xkey)
{
	node* p, * c, * t, * x;
	p = head;
	x = head->r;
	x = treeSearch(x, xkey);		// xkey�� ������ key�� ���� ��� xã��
	

	if (x == NULL)
		return;
	else
		t = x;

	if (t->r == NULL)		// ������ �ڽ��� ���� ���
		x = t->l;			
	else if (t->r->l == NULL)	// �������ڽ��� �����ڽ��� ���°��
	{
		x = t->r;
		x->l = t->l;
	}
	else                     // �� �� ������ ���
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

	// �θ����� ��ũ����
	if (xkey < p->key)
		p->l = x;
	else
		p->r = x;


}

// Ʈ���� ���̸� ���ϴ� �Լ�
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