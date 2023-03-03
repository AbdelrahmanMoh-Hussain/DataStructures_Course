#pragma once
#include<iostream>
#include<algorithm>
using namespace std;
class Node
{
public:
	int data{  };
	int height{};
	Node* left{};
	Node* right{};

public:
	Node(int val) {
		data = val;
		left = right = nullptr;
		height = 0;
	}

	int getChildHeight(Node* node) {
		if (!node)
		{
			return -1;
		}
		return node->height;
	}
	void updateHeight() {
		height = 1 + max(getChildHeight(left), getChildHeight(right));
	}
	int getBalanceFactor() {
		return getChildHeight(left) - getChildHeight(right);
	}

	~Node() {
		delete left;
		delete right;
		left = right = NULL;
	}


};


class AVLTree
{
private:
	Node* root{};

private:
	Node* rightRotation(Node* q) {
		Node* p = q->left;
		q->left = p->right;
		p->right = q;
		q->updateHeight();
		p->updateHeight();
		return p;
	} 
	Node* leftRotation(Node* p) {
		Node* q = p->right;
		p->right = q->left;
		q->left = p;
		p->updateHeight();
		q->updateHeight();
		return q;
	}
	Node* balance(Node* node) {
		int bf = node->getBalanceFactor();
		if (bf == 2)
		{
			if (node->left->getBalanceFactor() == -1) {
				node->left = leftRotation(node->left);
			}
			node = rightRotation(node);
		}
		else if(bf == -2)
		{
			if (node->right->getBalanceFactor() == 1)
			{
				node->right = rightRotation(node->right);
			}
			node = leftRotation(node);
		}
		return node;
	}
	Node* insertNode(int val, Node* node) {
		if (val < node->data)
		{
			if (!node->left)
			{
				node->left = new Node (val);
			}
			else
			{
				node->left = insertNode(val, node->left);
			}
		}
		if (val > node->data)
		{
			if (!node->right)
			{
				node->right = new Node (val);
			}
			else
			{
				node->right = insertNode(val, node->right);
			}
		}
		node->updateHeight();
		return balance(node);
	}

	Node* deleteNode(Node)
public:
	void insert(int val) {
		if (!root)
		{
			root = new Node(val);
		}
		else
		{
			root = insertNode(val, root);
		}
	}
};

