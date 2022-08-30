#include "LinkedListStack.h"
#include <assert.h>
#include <iostream>
using namespace std;



LinkedListStack::LinkedListStack()
{
	head = nullptr;
}


void LinkedListStack::push(double value)
{
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
}


void LinkedListStack::pop()
{
	assert(!isEmpty());
	Node* temp = head;
	head = head->next;
	delete temp;
}


bool LinkedListStack::isEmpty()
{
	return (head == nullptr);
}


double LinkedListStack::peek()
{
	assert(!isEmpty());
	return head->data;
}


double LinkedListStack::postfixEvalution(string line)
{
	double res = 0;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/' || line[i] == '^')
		{
			double n1 = peek();
			pop();
			double n2 = peek();
			pop();
			if (line[i] == '+')
			{
				push(n2 + n1);
			}
			else if (line[i] == '-')
			{
				push(n2 - n1);
			}
			else if (line[i] == '*')
			{
				push(n2 * n1);
			}
			else if (line[i] == '/')
			{
				push(n2 / n1);
			}
			else if (line[i] == '^')
			{
				push(pow(n2, n1));
			}
		}
		else
		{
			push(line[i] - '0');
		}
	}
	return peek();
}

