// 2016112158 �����
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
	head = new node();
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
	return t;
}

// ���� Ž�� Ʈ�� Ű����
// head : Ű�� ������ Ʈ��
// xkey : ���Ե� Ű
node* treeInsert(node* root, int xkey)
{
	// root�� �����̸�
	if (root == NULL)
	{
		root = new node();
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

// Ʈ������ �������� Ű���� ã�� �Լ�
node* minValueNode(node* root)
{
	node* current = root;

	while (current && current->l != NULL)
		current = current->l;

	return current;
}

// ����Ž��Ʈ������ Ű����
// head : Ű�� ������ Ʈ��
// xkey : ������ Ű
node* treeDel(node* root, int key)
{
	// base case of recusrion
	if (root == NULL)
		return root;

	// ������� Ű�� root�� Ű���� ������
	// ������� Ű�� ���� ����Ʈ���� ��ġ�Ѵ�
	if (key < root->key)
		root->l = treeDel(root->l, key);

	// ������� Ű�� root�� Ű���� Ŭ��
	// ������� Ű�� ������ ����Ʈ���� ��ġ�Ѵ�
	else if (key > root->key)
		root->r = treeDel(root->r, key);
	else
	{
		// �ڽĳ�尡 ���ų� �ϳ��� �ִ� ���
		if (root->l == NULL)
		{
			node* temp = root->r;
			free(root);
			return temp;
		}
		else if (root->r == NULL)
		{
			node* temp = root->l;
			free(root);
			return temp;
		}

		// �ڽ� ��尡 �ΰ� ��� �ִ� ���
		node* temp = minValueNode(root->r);
		root->key = temp->key;

		root->r = treeDel(root->r, temp->key);
	}

	return root;
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
		char command = input.c_str()[0];	// +, -, ?, Q ����
		int key;							// key��
		if (input.size() > 1)
			key = stoi(input.substr(1, input.length()));
		
		
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
			cout << "Retrieved : key = " << key << endl;
			node* temp = treeSearch(root, key);

			if (temp->l != NULL)
				cout << "left child is " << temp->l->key << endl;
			else
				cout << "left child is none" << endl;

			if (temp->r != NULL)
				cout << "right child is " << temp->r->key << endl;
			else
				cout << "right child is none" << endl;
			break;
		}
		case 'Q':
			cout << "Quit" << endl;
			flag = false;
			
		}
	}

	
}