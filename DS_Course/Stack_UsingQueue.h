#pragma once
#include "ArrayQueue.h"
class Stack_UsingQueue
{
private:
	ArrayQueue queue;
	int addedElements = 0;

private:
	int prev(int pos);

public:
	Stack_UsingQueue(int size);
	void push(int value);
	void pop();
	int peek();
	bool isFull();
	bool isEmpty();
};

