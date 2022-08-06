#include <iostream>
#include <assert.h>
#include "ArrayLinkedList.h"
using namespace std;

Node::Node(int data, int idx) {
	this->data = data;
	this->idx = idx;
	next = prev = nullptr;
}

void ArrayLinkedList::link(Node* first, Node* second)
{
	if (first)
	{
		first->next = second;
	}
	if (second)
	{
		second->prev = first;
	}
}

Node* ArrayLinkedList::embedAfter(Node* nodeBefore, int data, int idx)
{
	Node* mid = new Node(data, idx);
	Node* nodeAfter = nodeBefore->next;
	link(nodeBefore, mid);
	if (nodeAfter)
	{
		link(mid, nodeAfter);
	}
	else
	{
		tail = mid;
	}
	return mid;
}

Node* ArrayLinkedList::getIdx(int idx, bool setMissing)
{
	Node* prevIdx = head;
	while (prevIdx->next && prevIdx->next->idx < idx)
	{
		prevIdx = prevIdx->next;
	}
	bool found = (prevIdx->next && prevIdx->next->idx == idx);

	if (found)
	{
		return prevIdx;
	}

	if (!setMissing)
	{
		return nullptr;
	}
	else
	{
		return embedAfter(prevIdx, 0, idx);
	}
}

ArrayLinkedList::ArrayLinkedList()
{
	head = tail = nullptr;
	length = 0;
}

ArrayLinkedList::ArrayLinkedList(int length)
{
	head = tail = nullptr;
	this->length = length;
}

void ArrayLinkedList::setValue(int value, int idx)
{
	assert(idx < length);

	Node* newNode = new Node(value, idx);
	if (!head)
	{
		head = tail = newNode;
	}
	else if (idx < head->idx)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else if (idx > tail->idx)
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	else if (idx >= head->idx && idx <= tail->idx)
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			if (temp->idx == idx)
			{
				temp->data = value;
				return;
			}

			if (temp->next->idx > idx)
			{
				break;
			}
			temp = temp->next;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next->prev = newNode;
		temp->next = newNode;
	}

	getIdx(idx, true)->data = value;
}

int ArrayLinkedList::getValue(int idx)
{
	Node* temp = head;
	while (temp)
	{
		if (temp->idx == idx)
		{
			break;
		}
		temp = temp->next;
	}

	if (temp != nullptr)
	{
		return temp->data;
	}
	else
	{
		return -1;
	}
}

void ArrayLinkedList::print()
{
	Node* temp = head->next;
	for (int i = 0; i < length; ++i)
	{
		if (temp && i == temp->idx)
		{
			cout << temp->data << ' ';
			temp = temp->next;
			continue;
		}
		cout << 0 << ' ';
	}
	cout << endl;
}

void ArrayLinkedList::printNonZero()
{
	for (Node* temp = head->next; temp ; temp = temp->next)
	{
		cout << temp->data << ' ';
	}
	cout << endl;
}

void ArrayLinkedList::add(ArrayLinkedList other)
{
	Node* tempOther = other.head;
	while (tempOther)
	{
		Node* temp = head;
		bool foundIdx = false;
		while (temp)
		{
			if (temp->idx == tempOther->idx)
			{
				temp->data += tempOther->data;
				foundIdx = true;
				break;
			}
			temp = temp->next;
		}
		if (!foundIdx)
		{
			setValue(tempOther->data, tempOther->idx);
		}
		tempOther = tempOther->next;
	}
}
