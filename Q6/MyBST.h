#pragma once
#include <iostream>
using namespace std;

#include "BST.h"

class MyBST : public BST<int>
{
public:
	int countVals(int x);
protected:
	int countValsunder(Node<int>* node);
};

inline int MyBST::countVals(int x)
{
	Node<int>* node = findNode(root,x);
	cout << node->element << endl;
	return countValsunder(node);
}
inline int MyBST::countValsunder(Node<int>* node)
{
	int sum_left  = 0,
		sum_right = 0;
   
    if(node == nullptr)
	{
		return 0;
	}

	if (node->left == nullptr && node->right == nullptr)
	{
		return 0;
	}

	if (node->left)
	{
		sum_left = node->left->element + countValsunder(node->left);
	}
	if (node->right)
	{
		sum_right = node->right->element + countValsunder(node->right);
	}
	return sum_left + sum_right;
}