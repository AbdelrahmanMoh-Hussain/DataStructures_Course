#pragma once
#include <vector>
#include <deque>
#include <iostream>
using namespace std;
class BST
{
public:
	int data;
	BST* left{};
	BST* right{};
	BST* parent{};

public:
	BST(int value);
	void insert(int value);
	void get_inorder(vector<int>& values);
	void traversalInorder();

	//Easy Homework 1
	bool search(int value);
	bool isBST(int, int);
	bool isBST2();
	int kth_smallest(int& k);

	pair<bool, int> succesor(int target);

	//Mid Homework 2
	void insertParent(int value);
	pair<bool, int> succesorParent(int target);
	void searchSuccesor(deque<int>& q, vector<int>& ans, vector<int>& traversal);
	bool  isDegenerate(vector<int>& preorder);

	void deleteValue(int target);

	//Easy Homework 4
	BST* deleteNodePre(int target, BST* node);
	BST* deleteNode2(int target, BST* node);

private: //Utilities
	BST* getNext(vector<BST*>& ancestors);
	BST* findNode(int value);
	int getMin();
	int getMax();
	BST* minNode();
	bool findChain(vector<BST*>& ancestors, int target);
	BST* deleteNode(int , BST* node);
	void specialDelete(BST* child);
};

