#pragma once
#include <iostream>
using namespace std;

class LinkedListStack
{
private:
	class Node {
	public:
		double data;
		Node* next;

		Node(double val) {
			this->data = val;
			this->next = nullptr;
		};
	};

	Node* head;

public:
	LinkedListStack();
	void push(double value);
	void pop();
	bool isEmpty();
	double peek();
	double postfixEvalution(string line);
};

