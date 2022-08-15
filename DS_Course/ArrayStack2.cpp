#include "ArrayStack2.h"
#include <iostream>
using namespace std;

void ArrayStack2::shiftRight(int steps)
{
	for (int i = steps - 1; i >= 0; i--)
	{
		arr[i + 1] = arr[i];
	}
}

void ArrayStack2::shiftLeft(int steps)
{
	for (int i = 0; i < steps; i++)
	{
		arr[i] = arr[i + 1];
	}
}

ArrayStack2::ArrayStack2(int size)
{
	this->size = size;
	arr = new int[size];
	added_elements = 0;
}

bool ArrayStack2::push(int value)
{
	if (added_elements == size)
	{
		return false;
	}

	if (added_elements > 0)
	{
		shiftRight(added_elements);
	}
	arr[0] = value;
	added_elements++;
	return true;
}

bool ArrayStack2::pop()
{
	if (added_elements == 0)
	{
		return false;
	}
	shiftLeft(--added_elements);
	return true;
}

bool ArrayStack2::peek()
{
	if (added_elements == 0)
	{
		return false;
	}
	cout << arr[0] << endl;
	return true;
}
