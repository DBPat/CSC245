

// Dharmesh Patel
// Binary Search Tree Lab 4
// 9/26/2018

#include "bst.h"
#include <iostream>

int main() 
{
	BinarySearchTree<int> T(0);
	T.insert(6);
	T.insert(2);
	T.insert(8);
	T.insert(1);
	T.insert(4);
	T.insert(3);
	
	cout << "The tree printed in Postorder Transversal produces:" << endl;
	T.postOrder();	

	cout << "The height of the tree is " <<T.height() << endl;
	cout<< "There are " << T.numLeaves() << " leaves." <<endl;
	
	T.isBalanced() >0 ? cout << "It's Balanced" << endl : cout << "It's Not Balanced" <<endl;

	T.insert(9);

	
	T.isBalanced() >0 ? cout << "It's Balanced" << endl : cout << "It's Not Balanced" <<endl;

	
}

