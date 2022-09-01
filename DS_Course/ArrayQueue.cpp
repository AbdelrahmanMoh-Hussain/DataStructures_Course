#include "ArrayQueue.h"
#include <iostream>
#include<assert.h>
using namespace std;

ArrayQueue::ArrayQueue(int size)
{
	this->size = size;
	arr = new int[size];
}

void ArrayQueue::enqueue(int value)
{
	assert(!isFull());
	arr[rear] = value;
	rear = (rear + 1) % size;
	addedElements++;
}

void ArrayQueue::dequeue()
{
	assert(!isEmpty());
	front = (front + 1) % size;
	addedElements--;
}

int ArrayQueue::getFront()
{
	return arr[front];
}

bool ArrayQueue::isEmpty()
{
	return addedElements == 0;
}

bool ArrayQueue::isFull()
{
	return addedElements == size;
}
