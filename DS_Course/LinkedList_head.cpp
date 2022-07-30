#include <iostream>
#include "LinkedList_head.h"
using namespace std;

void LinkedList_head::print()
{
	Node* tempHead = head;
	while (tempHead != nullptr)
	{
		cout << tempHead->data << ' ';
		tempHead = tempHead->next;
	}
	cout << '\n';
}

void LinkedList_head::addElement(int data)
{
	Node* newNode = new Node(data);
	newNode->next = head;
	head = newNode;
	
}

Node* LinkedList_head::getTail()
{
	Node* temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	return temp;
}
