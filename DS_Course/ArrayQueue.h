#pragma once
class ArrayQueue
{
public:
	int* arr = 0;
	int size = 0;
	int addedElements = 0;
	int front = 0;
	int rear = 0;

public:
	ArrayQueue() {
		
		arr = new int[size];
	};
	ArrayQueue(int size);
	void enqueue(int value);
	void dequeue();
	int getFront();
	bool isEmpty();
	bool isFull();
};

