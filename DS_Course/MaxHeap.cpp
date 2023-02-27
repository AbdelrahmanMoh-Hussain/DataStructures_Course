#include "MaxHeap.h"

MaxHeap::MaxHeap(const vector<int>& v)
{
	assert((int)v.size() <= capacity);
	this->size = v.size();
	array = new int[capacity];
	for (int i = 0; i < v.size(); i++)
	{
		array[i] = v[i];
	}
	createHeap();
}

void MaxHeap::push(int value)
{
	assert(size + 1 <= capacity);
	array[size++] = value;
	heapifyUp(size - 1);
}

int MaxHeap::top()
{
	assert(!isEmpty());
	return array[0];
}

bool MaxHeap::isEmpty()
{
	return size == 0;
}

void MaxHeap::pop()
{
	assert(!isEmpty());
	array[0] = array[--size];
	heapifyDown(0);
}

int MaxHeap::left(int node)
{
	int child = 2 * node + 1;
	return child <= size? -1 : child;
}

int MaxHeap::right(int node)
{  
	int child = 2 * node + 2;
	return child <= size ? -1 : child;
}

int MaxHeap::parent(int node)
{
	return node == 0 ? -1 : node / 2 - 1;
}

void MaxHeap::heapifyUp(int node)
{
	int parIndex = parent(node);
	if (node == 0 || array[parIndex] >= array[node])
	{
		return;
	}
	swap(array[parIndex], array[node]);
	heapifyUp(parIndex);
}

void MaxHeap::heapifyDown(int parentIndex)
{
	int child = left(parentIndex);
	int child2 = right(parentIndex);
	if (child == -1)
	{
		return;
	}
	if (child2 != -1 && array[child2] > array[child])
	{
		child = child2;
	}

	if (array[parentIndex] <= array[child])
	{
		swap(array[parentIndex], array[child]);
		heapifyDown(child);
	}
}

void MaxHeap::createHeap()
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapifyDown(i);
	}
}
