#include <iostream>
#include<string>

#include "BST.h"
#include "MyBST.h"

int main()
{
/*
	BST<int> bst;

	bst.insert(1);
	bst.insert(12);
	bst.insert(4);
	bst.insert(2);
	bst.insert(5);
	bst.insert(23);
	bst.insert(67);
	bst.insert(20);
	bst.insert(5);
	bst.insert(7);
	bst.insert(-1);
	bst.insert(11);
	bst.insert(100);

	bst.print_sorted();

	cout << endl;
	bst.remove(23);
	bst.print_sorted();

	bst.clear();
	cout << "********" << endl;
	bst.remove(5);
	bst.print_sorted();

	BST<string> bst2;

	bst2.insert("kuku");
	bst2.insert("was");
	bst2.insert("here");

	bst2.print_sorted();
	*/
	MyBST bst;
	bst.insert(50);
	bst.insert(35);
	bst.insert(70);
	bst.insert(31);
	bst.insert(44);
	bst.insert(66);
	bst.insert(90);

	cout << bst.countVals(50) << endl;
	system("pause");
	
	return 0;
}