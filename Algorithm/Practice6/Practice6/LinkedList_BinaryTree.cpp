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
node* treeDel(node* head, int xkey)
{
	node* p, * c, * t, * x;
	p = head;
	x = head->r;
	x = treeSearch(x, xkey);		// xkey�� ������ key�� ���� ��� xã��
	

	if (x == NULL)
		return NULL;
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

	return t;

}

#define COUNT 5
void print2DUtil(node* root, int space)
{
	// base case of recursion
	if (root == NULL)
		return;

	// �������� �Ÿ� ����
	space += COUNT;

	// ������ �ڽĳ�忡 ���ؼ� ���� ����
	print2DUtil(root->r, space);

	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << "  ";
	cout << root->key << "\n";

	// ���� �ڽ� ����
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