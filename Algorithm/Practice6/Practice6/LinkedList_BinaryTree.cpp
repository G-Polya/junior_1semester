// 2016112158 김희수
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
	head = new node();
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
	return t;
}

// 이진 탐색 트리 키삽입
// head : 키를 삽입할 트리
// xkey : 삽입될 키
node* treeInsert(node* root, int xkey)
{
	// root가 시작이면
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

// 트리에서 가장작은 키값을 찾는 함수
node* minValueNode(node* root)
{
	node* current = root;

	while (current && current->l != NULL)
		current = current->l;

	return current;
}

// 이진탐색트리에서 키삭제
// head : 키를 삭제할 트리
// xkey : 삭제될 키
node* treeDel(node* root, int key)
{
	// base case of recusrion
	if (root == NULL)
		return root;

	// 지우려는 키가 root의 키보다 작을때
	// 지우려는 키는 왼쪽 서브트리에 위치한다
	if (key < root->key)
		root->l = treeDel(root->l, key);

	// 지우려는 키가 root의 키보다 클때
	// 지우려는 키는 오른쪽 서브트리에 위치한다
	else if (key > root->key)
		root->r = treeDel(root->r, key);
	else
	{
		// 자식노드가 없거나 하나만 있는 경우
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

		// 자식 노드가 두개 모두 있는 경우
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
		char command = input.c_str()[0];	// +, -, ?, Q 선택
		int key;							// key값
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