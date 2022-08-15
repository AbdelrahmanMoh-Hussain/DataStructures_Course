#include "TwoStackArray.h"
#include <iostream>
#include <assert.h>
using namespace std;

TwoStackArray::TwoStackArray(int size)
{
	this->size = size;
	arr = new int[size];
	firstStackElements = 0;
	secondStackElements = size - 1;
}

void TwoStackArray::push(int id, int value)
{
	if (secondStackElements != size - 1 && firstStackElements != 0)
	{
		assert(firstStackElements < secondStackElements);
	}

	if (id == 1)
	{
		arr[firstStackElements++] = value;
	}
	else
	{
		arr[secondStackElements--] = value;
	}
}

int TwoStackArray::pop(int id)
{
	if (id == 1)
	{
		assert(firstStackElements != 0);
		return arr[--firstStackElements];
	}
	else
	{
		assert(secondStackElements != size - 1);
		return arr[++secondStackElements];
	}
}

void TwoStackArray::display()
{
	cout << "First Stack Elements:: " << endl;
	while (firstStackElements > 0)
	{
		cout << pop(1) << ' ';
	}
	cout << endl << "Second Stack Elements" << endl;
	while(secondStackElements < size - 1)
	{
		cout << pop(2) << ' ';
	}
	cout << endl;
}
