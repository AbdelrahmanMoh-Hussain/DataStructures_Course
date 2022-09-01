#include "Deque.h"
#include <iostream>
#include<assert.h>
using namespace std;

int Deque::prev(int pos)
{
	if (pos == 0)
	{
		pos = size - 1;
	}
	else 
	{
		pos--;
	}
	return pos;
}

Deque::Deque(int size)
{
	this->size = size;
	arr = new int[size];
}

void Deque::enqueueRear(int value)
{
	assert(!isFull());
	arr[rear] = value;
	rear = (rear + 1) % size;
	addedElements++;
}

int Deque::dequeueFront()
{
	assert(!isEmpty());
	int value = arr[front];
	front = (front + 1) % size;
	addedElements--;
	return value;
}

void Deque::enqueueFront(int value)
{
	assert(!isFull());
	front = prev(front);
	arr[front] = value;
	addedElements++;
}

int Deque::dequeueRear()
{
	assert(!isEmpty());
	rear = prev(rear);
	addedElements--;
	return arr[rear];
}

bool Deque::isEmpty()
{
	return addedElements == 0;
}

bool Deque::isFull()
{
	return addedElements == size;
}

void Deque::display()
{
	for (int i = 0, cur = front; i < addedElements; i++, cur = (cur+1)%size)
	{
		cout << arr[cur] << ' ';
	}
	cout << "\n\n";
}
