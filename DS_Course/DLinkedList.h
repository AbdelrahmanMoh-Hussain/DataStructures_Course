#pragma once
class Node {
public:
	int data;
	Node* next;
	Node* prev;

	Node(int data);
	void set(Node* next, Node* prev);
};

class DLinkedList
{
private:
	Node* head;
	Node* tail;
	int length;

private: //Utilities
	Node* deleteLink(Node* cur);

public:
	DLinkedList();
	void printReversed();
	void print();
	void append(int value);
	void insertFront(int value);
	void insertSorted(int value);
	void deleteFront();
	void deleteBack();
	void deleteFirstOcr(int value);

	//DLL Easy to Med-Homework1
	void deleteValue(int value);
	void deleteEvenPos();
	void deleteOddPos();
	bool isPalindrome();
};

