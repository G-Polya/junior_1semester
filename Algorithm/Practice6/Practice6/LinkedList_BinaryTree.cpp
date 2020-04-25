#include <iostream>
#include <string>
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
void treeInsert(node* head, int xkey)
{
	node* p, * t;
	p = head;
	t = p -> r;

	while (t != NULL)	// ������ ��ġ ã��. �θ��� p ã��
	{
		p = t;
		if (xkey == t->key)
			return;
		else if (xkey < t->key)
			t = t->l;
		else
			t = t->r;
	}

	// ������ ��� ����
	t = new node;
	t->key = xkey;
	t->l = NULL;
	t->r = NULL;
	
	// �θ� ����� Ű���� ���� ������ ����, ũ�� �����ʿ� ����
	if (xkey < p->key)
		p->l = t;
	else
		p->r = t;
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

	��������
}