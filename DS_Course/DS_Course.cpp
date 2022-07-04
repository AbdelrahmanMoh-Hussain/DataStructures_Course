// DS_Course.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"
#include "LinkedList.h"
using namespace std;


class Node {
public:
	int data;
	Node* next = nullptr;

	Node(int data) : data(data) {}
	void static print(Node* head) {
		if (head == nullptr)
		{
			cout << endl;
			return;
		}
		cout << head->data << ' ';
		head = head->next;
		print(head);
	}
	void static printReversed(Node* head) {
		if (head == nullptr)
		{
			return;
		}
		printReversed(head->next);
		cout << head->data << ' ';
	}
	void static print1(Node* head) {
		for (; head != nullptr; head = head->next)
		{
			cout << head->data << ' ';
		}
		cout << endl;
	}
};

Node* find(int val, Node* head) {
	while (head != nullptr) {
		if (head->data == val)
		{
			return head;
		}
		head = head->next;
	}
	return nullptr;
}

int main()
{
	Node* node1 = new Node(6);
	Node* node2 = new Node(10);
	Node* node3 = new Node(8);
	Node* node4 = new Node(15);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = nullptr;

	Node::print(node1);
	cout << "---------------------" << endl;
	Node::printReversed(node1);
	cout << "\n---------------------" << endl;
	Node::print1(node1);

	
}
