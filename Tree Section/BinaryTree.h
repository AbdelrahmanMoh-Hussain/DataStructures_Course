#pragma once
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
	Node* root{};

public:
};

