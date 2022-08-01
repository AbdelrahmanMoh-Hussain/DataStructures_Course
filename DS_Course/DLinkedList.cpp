#include <iostream>
#include "DLinkedList.h"
using namespace std;

Node::Node(int data) {
	this->data = data;
	next = prev = nullptr;
}

void Node::set(Node* next, Node* prev)
{
	this->next = next;
	this->prev = prev;
}

Node* DLinkedList::deleteLink(Node* cur)
{
	Node* temp = cur->prev;
	temp->next = cur->next;
	cur->next->prev = temp;
	delete cur;
	length--;
	return temp;
}

DLinkedList::DLinkedList()
{
	head = tail = nullptr;
	length = 0;
}

void DLinkedList::printReversed()
{
	for (Node* cur = tail; cur ; cur = cur->prev)
	{
		cout << cur->data << ' ';
	}
	cout << endl;
}

void DLinkedList::print()
{
	for (Node* cur = head; cur; cur = cur->next)
	{
		cout << cur->data << ' ';
	}
	cout << endl;
}

void DLinkedList::append(int value)
{
	Node* newNode = new Node(value);
	if (head == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	length++;
}

void DLinkedList::insertFront(int value)
{
	Node* newNode = new Node(value);
	if (head == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	length++;
}

void DLinkedList::insertSorted(int value)
{
	Node* newNode = new Node(value);
	if (head == nullptr || value <= head->data)
	{
		insertFront(value);
	}
	else if (value > tail->data)
	{
		append(value);
	}
	else
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			if (temp->next->data > value)
			{
				break;
			}
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
		if (temp == tail)
		{
			tail = newNode;
		}
		length++;
	}
}

void DLinkedList::deleteFront()
{
	if (!head)
	{
		return;
	}

	Node* temp = head;
	if (length == 1)
	{
		head = tail = nullptr;
	}
	else
	{
		head = head->next;
	}
	delete temp;
	length--;
}

void DLinkedList::deleteBack()
{
	if (!head)
	{
		return;
	}

	Node* temp = tail;
	if (length == 1)
	{
		head = tail = nullptr;
	}
	else
	{
		tail = tail->prev;
	}
	delete temp;
	length--;

	if (tail)
	{
		tail->next = nullptr;
	}
	else if (!length)
	{
		head = nullptr;
	}
}

void DLinkedList::deleteFirstOcr(int value)
{
	if (!head)
	{
		return;
	}
	if (value == head->data)
	{
		deleteFront();
	}
	Node* temp = head;
	while (temp)
	{
		if (temp->data == value)
		{
			if (temp == tail)
			{
				deleteBack();
				break;
			}
			temp = deleteLink(temp);
			break;
		}
		temp = temp->next;
	}
}

void DLinkedList::deleteValue(int value)
{
	if (!head)
	{
		return;
	}
	if (value == head->data)
	{
		deleteFront();
	}
	Node* temp = head;
	while (temp)
	{
		if (temp->data == value)
		{
			if (temp == tail)
			{
				deleteBack();
				break;
			}
			temp = deleteLink(temp);
		}
		temp = temp->next;
	}
}

void DLinkedList::deleteEvenPos()
{
	Node* temp = head->next;
	while (temp) {
		if (temp == tail)
		{
			deleteBack();
			break;
		}
		temp = deleteLink(temp);
		temp = temp->next->next;
	}
}

void DLinkedList::deleteOddPos()
{
	/*deleteFront();
	Node* temp = head->next;
	while (temp) {
		if (temp == tail)
		{
			deleteBack();
			break;
		}
		temp = deleteLink(temp);
		temp = temp->next->next;
	}*/

	insertFront(-1); //Dummy node
	deleteEvenPos();
	deleteFront();
}

bool DLinkedList::isPalindrome()
{
	Node* forwardNode = head;
	Node* backwardNode = tail;
	int len = ceil(length / 2);
	while (len)
	{
		if (forwardNode->data != backwardNode->data)
		{
			return false;
		}
		forwardNode = forwardNode->next;
		backwardNode = backwardNode->prev;
		len--;
	}
	return true;
}


