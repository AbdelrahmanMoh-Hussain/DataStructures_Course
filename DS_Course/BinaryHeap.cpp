#include "BinaryHeap.h"

BinaryHeap::BinaryHeap(const vector<int>& v)
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

void BinaryHeap::push(int value)
{
	assert(size + 1 <= capacity);
	array[size++] = value;
	heapifyUp(size - 1);
}

int BinaryHeap::top()
{
	assert(!isEmpty());
	return array[0];
}

bool BinaryHeap::isEmpty()
{
	return size == 0;
}

BinaryHeap::~BinaryHeap()
{
	delete[] array;
	array = nullptr;
}

void BinaryHeap::removeRoot()
{
	int i = 0;
	while (true)
	{
		int leftChild = left(array[i]);
		int rightChild = right(array[i]);

		if (leftChild == -1 && rightChild == -1)
		{
			array[i] == array[size - 1];
			size--;
			return;
		}
		if (array[leftChild] > array[size - 1] && array[rightChild] > array[size - 1])
		{
			array[i] == array[size - 1];
			size--;
			return;
		}

		if (array[leftChild] < array[rightChild])
		{
			array[i] = array[leftChild];
			i = leftChild;
		}
		else
		{
			array[i] = array[rightChild];
			i = rightChild;
		}
	}
}

void BinaryHeap::pop()
{
	assert(!isEmpty());
	array[0] = array[--size];
	heapifyDown(0);
}

void BinaryHeap::printLessThan(int val, int parIndex) 
{
	if (array[parIndex] >= val)
	{
		return;
	}
	cout << array[parIndex] << ' ';

	int leftIndx = left(parIndex);
	int rightIndx = right(parIndex);
	if (leftIndx != -1 && array[leftIndx] < val)
	{
		printLessThan(val, leftIndx);
	}
	if (rightIndx != -1 && array[rightIndx] < val)
	{
		printLessThan(val, rightIndx);
	}
}

bool BinaryHeap::isHeap(int* p, int n)
{
	int size = (n - 2) / 3;
	int* ptr = p;
	for (int i = 0; i < size; i++)
	{
		int* ptrLeft = ptr + left(i);
		int* ptrRight = ptr + right(i);
		 
		if (*p > *ptrLeft || *p > *ptrRight)
		{
			return false;
		}
		p++;
	}
	return true;
}

void BinaryHeap::heapSort(int* p, int n)
{
	if (n <= 1)
	{
		return;
	}

	int* oldArr = array;
	int oldSize = size;

	array = p;
	size = n;

	createHeap();
	while (size--)
	{
		swap(array[0], array[size]);
		heapifyDown(0);
	}

	for (int i = 0; i < n / 2; i++)
	{
		swap(array[i], array[n - i - 1]);
	}

	size = oldSize;
	array = oldArr;

}

int BinaryHeap::left(int node)
{
	int child = 2 * node + 1;
	if (child >= size)
	{
		return -1;
	}
	return child;
}



int BinaryHeap::right(int node)
{
	int child = 2 * node + 2;
	return child >= size ? -1: child;
}

int BinaryHeap::parent(int node)
{
	return node == 0 ? -1: (node - 1)/2;
}

void BinaryHeap::heapifyUp(int node)
{
	/*int parIndex = parent(node);
	while (node != 0 && array[parIndex] < array[node])
	{
		swap(array[node], array[parIndex]);
		node = parIndex;
		parIndex = parent(node);
	}*/

	//Another Soltion
	int parPos = parent(node);
	if (node == 0 || array[parPos] < array[node])
		return;

	swap(array[node], array[parPos]);
	heapifyUp(parPos);
}

void BinaryHeap::heapifyDown(int parentIndex)
{
	int childPos = left(parentIndex);
	int rightChild = right(parentIndex);
	
	if (childPos == -1)
	{
		return;
	}
	if (rightChild != -1 && array[rightChild] < array[childPos])
	{
		childPos = rightChild;
	}

	if (array[parentIndex] > array[childPos])
	{
		swap(array[parentIndex], array[childPos]);
		heapifyDown(childPos);
	}
}

void BinaryHeap::createHeap() {
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapifyDown(i);
	}
}