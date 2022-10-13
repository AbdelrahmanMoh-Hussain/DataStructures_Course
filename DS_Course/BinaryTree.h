#pragma once
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
	int data{};
	Node* left{};
	Node* right{};

	Node(int data) : data(data) {
	}
};

class BinaryTree
{
private:
	int data;
	BinaryTree* left;
	BinaryTree* right;

public:
	int getNodeLevel(int value);

public:
	BinaryTree(int value);
	void inOrder();
	void add(vector<Node> , vector<char> path);

	//Easy Homework 1
	int max();
	int getHeight();
	int countNodes();
	int countLeafNodes();
	bool find(int value);
	bool isPerfect(int h = -1); //Coudln't solve it with rec

	//Mid Homework 1
	void clear();
	~BinaryTree();
	void inOrderIterative();
	void traverseLeftBoundry();
	int getDiameter();

	void breadthTraversal();
};

