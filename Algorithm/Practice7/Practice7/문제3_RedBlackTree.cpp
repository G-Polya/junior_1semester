// 2016112158 �����
#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
using namespace std;

enum Color {RED,BLACK};



struct Node
{
	int data;
	bool color;
	Node* left, * right, * parent;

	// Constructor 
	Node(int data)
	{
		this->data = data;
		left = right = parent = NULL;
		this->color = RED;
	}
};

// Class to represent Red-Black Tree 
class RBTree
{
private:
	Node* root;
protected:
	void rotateLeft(Node*&, Node*&);
	void rotateRight(Node*&, Node*&);
	void fixViolation(Node*&, Node*&);
public:
	// Constructor 
	RBTree() { root = NULL; }
	void insert(const int& n);
	void print2DUtil(Node*, int space);
	void print2D(int space);
};


// �����˻�Ʈ�� ����
Node* BSTInsert(Node* root, Node* pt)
{
	if (root == NULL)
		return pt;

	if (pt->data < root->data)
	{
		root->left = BSTInsert(root->left, pt);
		root->left->parent = root;
	}
	else if (pt->data > root->data)
	{
		root->right = BSTInsert(root->right, pt);
		root->right->parent = root;
	}

	
	return root;
}


void RBTree::print2DUtil(Node* root, int space)
{
	// base case of recursion
	if (root == NULL)
		return;

	// �������� �Ÿ� ����
	space += 5;

	// ������ �ڽĳ�忡 ���ؼ� ���� ����
	print2DUtil(root->right, space);

	cout << endl;
	for (int i = 5; i < space; i++)
		cout << "  ";
	cout << root->data << "\n";

	// ���� �ڽ� ����
	print2DUtil(root->left, space);


}

void RBTree::print2D(int space)
{
	print2DUtil(this->root, space);
}

// ��� pt������ ��ȸ��
void RBTree::rotateLeft(Node*& root, Node*& pt)
{
	Node* y = pt->right;	// y����

	pt->right = y->left;	 // y�� ���� ����Ʈ���� pt�� ������ ����Ʈ���� �ű�

	if (pt->right != NULL)
		pt->right->parent = pt;

	y->parent = pt->parent;	// x�� �θ� y�� ����

	if (pt->parent == NULL)
		root = y;

	else if (pt == pt->parent->left)
		pt->parent->left = y;

	else
		pt->parent->right = y;

	y->left = pt;
	pt->parent = y;
}

// ��� pt������ ��ȸ��. ��ȸ���� �ݴ�
void RBTree::rotateRight(Node*& root, Node*& pt)
{
	Node* pt_left = pt->left;

	pt->left = pt_left->right;

	if (pt->left != NULL)
		pt->left->parent = pt;

	pt_left->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_left;

	else if (pt == pt->parent->left)
		pt->parent->left = pt_left;

	else
		pt->parent->right = pt_left;

	pt_left->right = pt;
	pt->parent = pt_left;
}

// �����Ʈ���� Ư�������� ���� �Լ�
void RBTree::fixViolation(Node*& root, Node*& pt)
{
	Node* parent_pt = NULL;				// �θ� ���
	Node* grand_parent_pt = NULL;		// ���θ� ���

	while ((pt != root) && (pt->color != BLACK) &&
		(pt->parent->color == RED))
	{

		parent_pt = pt->parent;
		grand_parent_pt = pt->parent->parent;

		// �θ��尡 ���θ����� ���� �ڽ��� ���
		if (parent_pt == grand_parent_pt->left)
		{

			Node* uncle_pt = grand_parent_pt->right;	// ���� ���

			// case 1: �����Ϸ��� ��� pt�� ���� uncle_pt�� ������ ���
			if (uncle_pt != NULL && uncle_pt->color == RED)
			{
				grand_parent_pt->color = RED;	// ���θ� red��
				parent_pt->color = BLACK;		// �θ�� ������ red��
				uncle_pt->color = BLACK;
				pt = grand_parent_pt;			// ���θ� ���ο� pt�� �����ؼ� while���� �ݺ�
			}

			else
			{
				// case 2: pt�� ���� uncle_pt�� ����̸� pt�� ������ �ڽ��� ���
				if (pt == parent_pt->right)
				{
					rotateLeft(root, parent_pt);	// ��ȸ�� ��,
					pt = parent_pt;					// pt�� �θ���� �缳��.. �θ���� ���θ���� �缳���ȴ�
					parent_pt = pt->parent;
				}

				// case 3: pt�� ���� uncle_pt�� ����̸� pt�� ���� �ڽ��� ���
				rotateRight(root, grand_parent_pt);		// ���θ� ��� ������ ��ȸ���� �����ϰ�
				swap(parent_pt->color, grand_parent_pt->color);	// pt�θ�� ���θ� ������ ���� �ٲ���
				pt = parent_pt;
			}
		}

		// �θ��尡 ���θ����� ������ �ڽ��� ��� >> ���� �ڽ��� ��쿡�� right�� left�� �ٲ� ���� ����
		else
		{
			Node* uncle_pt = grand_parent_pt->left;

			// case 1
			if ((uncle_pt != NULL) && (uncle_pt->color == RED))
			{
				grand_parent_pt->color = RED;
				parent_pt->color = BLACK;
				uncle_pt->color = BLACK;
				pt = grand_parent_pt;
			}
			else
			{
				// case 2
				if (pt == parent_pt->left)
				{
					rotateRight(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}

				// case 3
				rotateLeft(root, grand_parent_pt);
				swap(parent_pt->color, grand_parent_pt->color);
				pt = parent_pt;
			}
		}
	}

	root->color = BLACK;
}

// ���ο� �����͸� �����Ʈ���� �����ϱ� ���� �Լ�
void RBTree::insert(const int& data)
{
	Node* pt = new Node(data);

	// �Ϲ����� ����Ž��Ʈ���� �����
	root = BSTInsert(root, pt);

	// ���� �� Ʈ���� Ư���� �����ϵ��� ���� 
	fixViolation(root, pt);
}




int main()
{
	cout << "Commands: " << endl;
	cout << "+ key : Insert(or update) element" << endl;
	cout << "? key : Retrieve element" << endl;
	cout << "- key : Remove element" << endl;
	cout << "Q     : Quit the test program" << endl;
	bool flag = true;

	RBTree tree;
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
			tree.insert(key);
			tree.print2D(0);

			break;
		
	
		case 'Q':
			cout << "Quit" << endl;
			flag = false;

		}
	}


}