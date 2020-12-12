#pragma once
#include<iostream>
#include<iomanip>
#define COUNT 10 

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int key)
{
	Node* newNode = new Node;
	newNode->data = key;
	newNode->left = newNode->right = nullptr;
	return newNode;
}
Node* insert(Node* root, int key)
{
	if (root == nullptr)
		return newNode(key);

	if (key < root->data)
	{
		root->left = insert(root->left, key);
	}
	else
		root->right = insert(root->right, key);
	return root;
}
Node* search(Node* root, int key)
{
	if (root == nullptr || root->data == key)
		return root;

	if (key > root->data)
		return search(root->right, key);
	else return search(root->left, key);
}
Node* findMinLeft(Node* root)
{
	Node* temp = root;
	while (temp && temp->left)
		temp = temp->left;
	return temp;
}
Node* deleteNode(Node* root, int key)
{
	if (root == nullptr)
		return root;

	// if key is bigger - go on right tree, less - left tree
	if (key > root->data)
		root->right = deleteNode(root->right, key);// reassign root
	else if (key < root->data)
		root->left = deleteNode(root->left, key);// reassign root
	// if there are children
	else
	{
		// node doesn't have children or has one child left or right
		if (root->left == nullptr)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		if (root->right == nullptr)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		// if node has both children
		Node* temp = findMinLeft(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);// deleter most left node
	}
	return root;
}

void printTree(Node* tree)
{
	if (tree == nullptr)
		return;

	printTree(tree->left);
	std::cout << tree->data << " ";
	printTree(tree->right);
}

void printAwesomeTree(Node* root, int space)// source https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
{
	// Base case  
	if (root == nullptr)
		return;

	// Increase distance between levels  
	space += COUNT;

	// Process right child first  
	printAwesomeTree(root->right, space);

	// Print current node after space  
	// count  
	std::cout << std::endl;
	for (int i = COUNT; i < space; i++)
		std::cout << " ";
	std::cout << root->data << "\n";

	// Process left child  
	printAwesomeTree(root->left, space);
}

