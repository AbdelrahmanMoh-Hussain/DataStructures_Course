#include "ArrayStack.h"
#include <string>
#include <assert.h>
using namespace std;

void ArrayStack::expand()
{
	size *= 2;
	int* newArr = new int[size];
	for (int i = 0; i < elements; i++)
	{
		newArr[i] = arr[i];
	}
	arr = newArr;
	delete arr;
}

ArrayStack::ArrayStack(int size)
{
	this->size = size;
	arr = new int[size];
	elements = 0;
}

void ArrayStack::push(int value)
{
	if (isFull())
	{
		expand();
	}
	arr[elements++] = value;
}

void ArrayStack::pop()
{
	assert(!isEmpty());
	elements--;
}

int ArrayStack::peek()
{
	assert(!isEmpty());
	return arr[elements - 1];
}

bool ArrayStack::isFull()
{
	return elements == size;
}

bool ArrayStack::isEmpty()
{
	return elements == 0;
}

void ArrayStack::display()
{
	while (!isEmpty())
	{
		cout << peek() << ' ';
		pop();
	}
}

void ArrayStack::display2()
{
	for (int i = 0; i < elements; i++)
	{
		cout << arr[i] << ' ';
	}
}

void ArrayStack::clear()
{
	while (!isEmpty())
	{
		pop();
	}
}

string ArrayStack::reverseSubword(string line)
{
	clear();

	string res;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] != ' ')
		{
			push(line[i]);
		}
		else
		{
			while (!isEmpty())
			{
				res += peek();
				pop();
			}
			res += ' ';
		}
	}
	while (!isEmpty())
	{
		res += peek();
		pop();
	}
	res += ' ';
	return res;
}

int ArrayStack::reverseNum(int num)
{
	clear();

	string line = to_string(num);
	while (line.length() > size)
	{
		expand();
	}
	string res = reverseSubword(line);
	return stoi(res);

	/*while (num)
	{
		push(num % 10);
		num /= 10;
	}
	int tens = 1;
	while (!isEmpty())
	{
		num += (peek() * tens);
		tens *= 10;
		pop();
	}*/
}

bool ArrayStack::isValid(string str)
{
	clear();

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ')')
		{
			if (arr[elements - 1] != '(')
			{
				return false;
			}
			pop();
		}
		else if (str[i] == '}')
		{
			if (arr[elements - 1] != '{')
			{
				return false;
			}
			pop();
		}
		else if (str[i] == ']')
		{
			if (arr[elements - 1] != '[')
			{
				return false;
			}
			pop();
		}
		else
		{
			push(str[i]);
		}
	}

	return isEmpty();
}

void ArrayStack::removeDupl(string str)
{
	clear();

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == peek())
		{
			pop();
		}
		else
		{
			push(str[i]);
		}
	}
	for (int j = 0; j < elements; j++)
	{
		cout << arr[j];
	}
}

void ArrayStack::insertBottom(int value)
{
	cout << elements << endl;
	for (int i = elements; i > 0; i--)
	{
		cout << arr[i] << endl;
		arr[i] = arr[i - 1];
	}
	arr[0] = value;
	elements++;
}
