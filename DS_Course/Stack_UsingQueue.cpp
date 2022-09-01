#include "Stack_UsingQueue.h"
#include <assert.h>
#include <iostream>
using namespace std;

int Stack_UsingQueue::prev(int pos)
{
	if (pos == 0)
	{
		pos = queue.size - 1;
	}
	else
	{
		pos--;
	}
	return pos;
}

Stack_UsingQueue::Stack_UsingQueue(int size)
{
	queue.size = size;
}

void Stack_UsingQueue::push(int value)
{
	queue.enqueue(value);
}

void Stack_UsingQueue::pop()
{
	assert(!isEmpty());
	queue.rear = prev(queue.rear);
	queue.addedElements--;
}

int Stack_UsingQueue::peek()
{
	assert(!isEmpty());
	//cout << queue.arr[queue.rear - 1] << endl;
	return queue.arr[queue.rear - 1];
}

bool Stack_UsingQueue::isFull()
{
	return queue.isFull();
}

bool Stack_UsingQueue::isEmpty()
{
	return queue.isEmpty();
}
