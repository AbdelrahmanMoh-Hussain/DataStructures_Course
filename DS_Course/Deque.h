#pragma once
class Deque
{
private:
	int* arr = 0;
	int size = 0;
	int addedElements = 0;
	int front = 0;
	int rear = 0;

private:
	int prev(int pos);

public:
	Deque(int size);
	void enqueueRear(int value);
	int dequeueFront();
	void enqueueFront(int value);
	int dequeueRear();
	bool isEmpty();
	bool isFull();
	void display();
};

