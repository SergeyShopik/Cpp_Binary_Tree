#include"Btree.h"

int main()
{
	Node* root = nullptr;
	root = insert(root, 10);
	root = insert(root, 6);
	root = insert(root, 90);
	root = insert(root, 0);
	root = insert(root, 65);
	printTree(root);
	std::cout << std::endl;
	printAwesomeTree(root, 0);


	return 0;
}