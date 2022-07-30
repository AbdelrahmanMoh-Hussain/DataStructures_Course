#pragma once
#include<vector>

class Node {
public:
	int data;
	Node* next;

	Node(int data);
	void static print(Node* head);
	void static printReversed(Node* head);
	~Node();
};

class LinkedList
{
private:
	Node* head;
	Node* tail;
	int length;

public:
	LinkedList();
	void print();
	void printwithAddress();
	void append(int);
	Node* getNth(int idx);
	int find(int val);
	int improvedSearch(int val);

	//SLL Easy-Homework1
	void insert_front(int val);
	void delete_front();
	Node* getNth_back(int idx);
	bool is_same1(LinkedList& list);
	bool is_same2(LinkedList& list);
	~LinkedList();

	void delete_back();
	void delete_nth(int idx);
	void delete_value(int val);

	//SLL Easy-Homework2
	void delete_withKey(int key);
	void swap_pairs();
	void reverse();
	void delete_evenPos();
	void insert_sorted(int value);

	//SLL Med-Homework
	void swap_headandTail();
	void leftRotate(int steps);
	void removeDuplicates();
	void removeLastKey(int key);
	void movetoBack(int key);
	int max(Node* head = nullptr, bool is_first_call = true);
};

