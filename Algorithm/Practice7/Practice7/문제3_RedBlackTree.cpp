// 2016112158 �����
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum Color {RED,BLACK};



struct Node
{
	int data;
	bool color;
	Node* left, * right, * parent;

	// ������
	Node(int data)
	{
		this->data = data;
		left = right = parent = NULL;
		this->color = RED;
	}
};

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


class RBTree
{
private :
	Node* root;
protected:
	// ��� x������ ��ȸ��
	void rotateLeft(Node *&root, Node *&x)
	{
		Node* y = x->right;		// pt_right ����
		x->right = y->left;		// // pt_right�� ���� ����Ʈ���� pt�� ������ ����Ʈ���� �ű�

		if (x->right != NULL)
			x->right->parent = x;

		y->parent = x->parent;	// x�� �θ� y�� ����

		if (x->parent == NULL)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;

		y->left = x;	//x�� y�� ���ʿ� ����
		x->parent = y;
	}

	// ��� x������ ��ȸ��. ��ȸ���� �ݴ�
	void rotateRight(Node*& root, Node*& x)
	{
		Node* y = x->left;

		x->left = y->right;

		if (x->left != NULL)
			x->left->parent = x;

		y->parent = x->parent;

		if (x->parent == NULL)
			root = y;

		else if (x == x->parent->left)
			x->parent->left = y;

		else
			x->parent->right = y;

		y->right = x;
		x->parent = y;
	}
	void fixViolation(Node *&root, Node *&pt)
	{
		Node* parent_pt = NULL;			//�θ���
		Node* grand_parent_pt = NULL;	//���θ� ���

		while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
		{
			parent_pt = pt->parent;
			grand_parent_pt = pt->parent->parent;

			// �θ��尡 ���θ����� ���� �ڽ��� ���
			if (parent_pt == grand_parent_pt->left)
			{
				Node* uncle_pt = grand_parent_pt->right;	//���̳�� 

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
			else // �θ��尡 ���θ����� ������ �ڽ��� ��� >> ���� �ڽ��� ��쿡�� right�� left�� �ٲ� ���� ����
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
	}

public:
	RBTree()
	{
		root = NULL;
	}

	void insert(const int& data)
	{
		Node* pt = new Node(data);

		root = BSTInsert(root, pt);

		fixViolation(root, pt);
	}

	void print2DUtil(Node* root, int space)
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

	void print2D(int space)
	{
		print2DUtil(this->root, space);
	}

	void inorder();
	void levelOrdeR();
};









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