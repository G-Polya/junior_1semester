// 2016112158 김희수
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


// 이진검색트리 삽입
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

	// 계층간의 거리 증가
	space += 5;

	// 오른쪽 자식노드에 대해서 먼저 수행
	print2DUtil(root->right, space);

	cout << endl;
	for (int i = 5; i < space; i++)
		cout << "  ";
	cout << root->data << "\n";

	// 왼쪽 자식 수행
	print2DUtil(root->left, space);


}

void RBTree::print2D(int space)
{
	print2DUtil(this->root, space);
}

// 노드 pt쪽으로 좌회전
void RBTree::rotateLeft(Node*& root, Node*& pt)
{
	Node* y = pt->right;	// y설정

	pt->right = y->left;	 // y의 왼쪽 서브트리를 pt의 오른쪽 서브트리로 옮김

	if (pt->right != NULL)
		pt->right->parent = pt;

	y->parent = pt->parent;	// x의 부모를 y로 연결

	if (pt->parent == NULL)
		root = y;

	else if (pt == pt->parent->left)
		pt->parent->left = y;

	else
		pt->parent->right = y;

	y->left = pt;
	pt->parent = y;
}

// 노드 pt쪽으로 우회전. 좌회전의 반대
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

// 레드블랙트리의 특성유지를 위한 함수
void RBTree::fixViolation(Node*& root, Node*& pt)
{
	Node* parent_pt = NULL;				// 부모 노드
	Node* grand_parent_pt = NULL;		// 조부모 노드

	while ((pt != root) && (pt->color != BLACK) &&
		(pt->parent->color == RED))
	{

		parent_pt = pt->parent;
		grand_parent_pt = pt->parent->parent;

		// 부모노드가 조부모노드의 왼쪽 자식인 경우
		if (parent_pt == grand_parent_pt->left)
		{

			Node* uncle_pt = grand_parent_pt->right;	// 삼촌 노드

			// case 1: 삽입하려는 노드 pt의 삼촌 uncle_pt가 적색인 경우
			if (uncle_pt != NULL && uncle_pt->color == RED)
			{
				grand_parent_pt->color = RED;	// 조부모를 red로
				parent_pt->color = BLACK;		// 부모와 삼촌은 red로
				uncle_pt->color = BLACK;
				pt = grand_parent_pt;			// 조부모를 새로운 pt로 설정해서 while루프 반복
			}

			else
			{
				// case 2: pt의 삼촌 uncle_pt가 흑색이며 pt가 오른쪽 자식인 경우
				if (pt == parent_pt->right)
				{
					rotateLeft(root, parent_pt);	// 좌회전 후,
					pt = parent_pt;					// pt를 부모노드로 재설정.. 부모노드는 조부모노드로 재설정된다
					parent_pt = pt->parent;
				}

				// case 3: pt의 삼촌 uncle_pt가 흑색이며 pt가 왼쪽 자식인 경우
				rotateRight(root, grand_parent_pt);		// 조부모 노드 쪽으로 우회전을 수행하고
				swap(parent_pt->color, grand_parent_pt->color);	// pt부모와 조부모 노드들의 색을 바꿔줌
				pt = parent_pt;
			}
		}

		// 부모노드가 조부모노드이 오른쪽 자식인 경우 >> 왼쪽 자식인 경우에서 right와 left를 바꾼 경우와 같다
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

// 새로운 데이터를 레드블랙트리에 삽입하기 위한 함수
void RBTree::insert(const int& data)
{
	Node* pt = new Node(data);

	// 일반적인 이진탐색트리를 만들고
	root = BSTInsert(root, pt);

	// 레드 블랙 트리의 특성을 유지하도록 만듦 
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
		char command = input.c_str()[0];	// +, -, ?, Q 선택
		int key;							// key값
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