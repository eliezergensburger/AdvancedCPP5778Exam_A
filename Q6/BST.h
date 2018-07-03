#pragma once
#include<iostream>

using namespace std;

template <class T>
class Node {
public:
	T element;
	Node<T>* left;
	Node<T>* right;
};

template <class T>
class BST {
public:
	int length;
	int len;
	BST();
	~BST();
	T findMin();
	T findMax();
	bool find(T x);
	bool isEmpty();
	void print_sorted();
	void insert(T x);
	void remove(T x);
	int height();
	int numbernodes();
	void clear();

protected:
	Node<T> *root;
	Node<T> *insert(Node<T>*t, T x);
	Node<T> *remove(Node<T> *t, T x);
	int height(Node<T> *t);
	int numbernodes(Node<T> *t);
	T findMin(Node<T> *t);
	T findMax(Node<T> *t);
	Node<T>* findNode(Node<T> *t,T x);
	bool find(Node<T> *t, int x);
	void print_sorted(Node<T> *t);
	void clear(Node<T> *t);
};

template <class T>
BST<T>::BST() {
	root = nullptr;
	length = 0;
	len = 0;
}

template <class T>
BST<T>::~BST() {
	clear();
}
template <class T>
bool BST<T>::isEmpty()
{
	return root == nullptr;
}
template <class T>
T BST<T>::findMin() {
	return findMin(root);
}

template <class T>
T BST<T>::findMin(Node<T>* t) {
	if (t->left == nullptr)
		return t->element;
	return findMin(t->left);
}

template <class T>
T BST<T>::findMax() {
	return findMax(root);
}

template <class T>
T BST<T>::findMax(Node<T>* t) {
	if (t->right == nullptr)
		return t->element;
	return findMax(t->right);
}

template <class T>
bool BST<T>::find(T x) {
	return find(root, x);
}

template <class T>
bool BST<T>::find(Node<T>* t, int x) {
	if (t == nullptr)
		return false;
	if (t->element == x)
		return true;
	if (x < t->element)
		return find(t->left, x);
	else
		return find(t->right, x);
}

template <class T>
Node<T>* BST<T>::findNode(Node<T> *t , T x)
{
	if (t == nullptr)
		return nullptr;
	if (t->element == x)
		return t;
	if (x < t->element)
		return findNode(t->left, x);
	else
		return findNode(t->right, x);
}

template <class T>
void BST<T>::print_sorted() {
	print_sorted(root);
}

template <class T>
void BST<T>::print_sorted(Node<T>* t) {
	if (t == nullptr)
		return;
	print_sorted(t->left);
	cout << t->element << endl;
	print_sorted(t->right);
}

template <class T>
int BST<T>::numbernodes() {
	return numbernodes(root);
}

template <class T>
int BST<T>::numbernodes(Node<T>* t) {
	if (t == nullptr)
		return 0;
	numbernodes(t->left);
	length++;
	numbernodes(t->right);
	return length;
}

template <class T>
void BST<T>::insert(T x) {
	root = insert(root, x);
}

template <class T>
Node<T> *BST<T>::insert(Node<T>* t, T x) {
	if (t == nullptr) {
		Node<T> *n = new Node<T>();
		n->element = x;
		n->left = nullptr;
		n->right = nullptr;
		t = n;
		return t;
	}
	if (x < t->element) {
		t->left = insert(t->left, x);
		return t;
	}
	else {
		t->right = insert(t->right, x);
		return t;
	}
}

template <class T>
void BST<T>::remove(T x) {
	root = remove(root, x);

	return;
}

template <class T>
Node<T>* BST<T>::remove(Node<T>* t, T x) {
	if (t == nullptr)
		return t;

	if (x < t->element) {
		t->left = remove(t->left, x);
		return t;
	}
	if (x > t->element) {
		t->right = remove(t->right, x);
		return t;
	}

	if (t->left != nullptr && t->right != nullptr) {
		//int m=findMin(t->right);
		T m = (t->element = findMin(t->right));
		t->right = remove(t->right, m);
		return t;
	}

	if (t->right != nullptr) {
		Node<T> *n = t;
		t = t->right;
		delete n;
		return t;
	}
	else {
		Node<T> *n = t;
		t = t->left;
		delete n;
		return t;
	}

}

template <class T>
int BST<T>::height() {
	return height(root);
}

template <class T>
int BST<T>::height(Node<T> *t) {
	//Node *t=root;
	//BST *B1=t;
	if (t == nullptr)
		return 0;
	if (t->left == nullptr && t->right == nullptr)
		return 0;
	if (height(t->left) > height(t->right))
		return height(t->left) + 1;
	else
		return height(t->right) + 1;
}

template <class T>
void BST<T>::clear() {
	clear(root);
	root = nullptr;
	length = 0;
	len = 0;
}

template <class T>
void BST<T>::clear(Node<T> *current)
{
	if (current)
	{
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

