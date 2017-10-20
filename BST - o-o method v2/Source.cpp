#include <iostream>

#include "BinarySearchTree.h"


int main()
{
	BinarySearchTree<int, int> bst;
	int x;

	bst.insert(10, 10);
	bst.insert(20, 20);
	bst.insert(5, 5);
	bst.insert(6, 6);
	bst.insert(8, 8);
	bst.insert(1, 1);
	bst.insert(3, 3);
	bst.insert(30, 30);
	bst.insert(14, 14);
	bst.insert(2, 2);
	
	bst.print_tree_inorder();

	bst.delete_tree();

	

	
	

	std::cin >> x;
	return 0;
}