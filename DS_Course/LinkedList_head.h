#pragma once
#include "LinkedList.h"

class LinkedList_head
{
private:
	Node* head{};

public:
	void print();
	void addElement(int data);
	Node* getTail();
};

