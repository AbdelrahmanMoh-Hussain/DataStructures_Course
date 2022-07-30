#include <iostream>
#include <assert.h>
#include <sstream>
#include "LinkedList.h"
using namespace std;

Node::Node(int data) : data(data)
{
	next = nullptr;
}

void Node::print(Node* head)
{
	if (head == nullptr)
	{
		cout << endl;
		return;
	}
	cout << head->data << ' ';
	head = head->next;
	print(head);
}

void Node::printReversed(Node* head)
{
	if (head == nullptr)
	{
		return;
	}
	printReversed(head->next);
	cout << head->data << ' ';
}

Node::~Node() {
	//cout << "Destory value: " << data << " at address: " << this << endl;
}

LinkedList::LinkedList()
{
	head = tail = nullptr;
	length = 0;
}

void LinkedList::print()
{
	Node* temp_head = head;
	while (temp_head != nullptr)
	{
		cout << temp_head->data << ' ';
		temp_head = temp_head->next;
	}
	cout << endl;
}

void LinkedList::printwithAddress()
{
	Node* temp_head = head;
	while (temp_head != nullptr)
	{
		cout << temp_head->data << '||' << temp_head << ' ';
		temp_head = temp_head->next;
	}
	cout << endl;
}

void LinkedList::append(int val)
{
	Node* newNode = new Node(val);
	if (tail == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	length++;
}

Node* LinkedList::getNth(int idx)
{
	Node* temp_head = head;
	while (--idx)
	{
		temp_head = temp_head->next;
	}
	return temp_head;
}

int LinkedList::find(int val)
{
	Node* temp_head = head;
	int cnt = 0;
	while (temp_head != nullptr)
	{
		if (temp_head->data == val)
		{
			return cnt;
		}
		temp_head = temp_head->next;
		cnt++;
	}
	return -1;
}


int LinkedList::improvedSearch(int val)
{
	Node* cur = head;
	Node* prev = nullptr;
	int cnt = 0;
	while (cur != nullptr)
	{
		if (cur->data == val)
		{
			if (prev == nullptr)
			{
				return cnt; // return 0;
			}
			swap(cur->data, prev->data);
			return cnt - 1;
		}
		prev = cur;
		cur = cur->next;
		cnt++;
	}
	return -1;
}

void LinkedList::insert_front(int val)
{
	Node* newNode = new Node(val);
	if (head == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	length++;
}

void LinkedList::delete_front()
{
	assert(length != 0);
	Node* temp_head = head;
	if (length == 1)
	{
		head = tail = nullptr;
	}
	else 
	{
		head = head->next;
	}
	delete temp_head;
	length--;
}

Node* LinkedList::getNth_back(int idx)
{
	int cnt = length - idx;
	Node* temp = head;
	while (cnt--)
	{
		temp = temp->next;
	}
	return temp;
}

bool LinkedList::is_same1(LinkedList& list)
{
	if (length != list.length)
	{
		return false;
	}
	else
	{
		Node* tempList1 = head;
		Node* tempList2 = list.head;
		while (tempList1 != nullptr)
		{
			if (tempList1->data != tempList2->data) {
				return false;
			}
			tempList1 = tempList1->next;
			tempList2 = tempList2->next;
		}
		return true;
	}
}

bool LinkedList::is_same2(LinkedList& list)
{
	/*Node* tempList1 = head;
	Node* tempList2 = list.head;
	while (true)
	{
		if ((tempList1 == nullptr && tempList2 != nullptr) || (tempList1 != nullptr && tempList2 == nullptr))
		{
			return false;
		}
		if (tempList1 == nullptr && tempList2 == nullptr)
		{
			return true;
		}
		if (tempList1->data != tempList2->data) {
			return false;
		}
		tempList1 = tempList1->next;
		tempList2 = tempList2->next;
	}*/
	Node* h1 = head;
	Node* h2 = list.head;

	while (h1 && h2)
	{
		if (h1->data != h2->data)
		{
			return false;
		}
		h1 = h1->next;
		h2 = h2->next;
	}
	return !h1 && !h2;
}

void LinkedList::delete_back()
{
	/*Node* tempTail = tail;
	if (length == 1)
	{
		head = tail = nullptr;
	}
	else
	{
		Node* temp = head;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = nullptr;
		tail = temp;
	}
	delete tempTail;
	length--;*/

	if (length <= 1)
	{
		delete_front();
		return;
	}
	Node* prev = getNth(length - 1);
	Node* temp = tail;
	delete temp;
	length--;
	tail = prev;
	tail->next = nullptr;
}

void LinkedList::delete_nth(int idx)
{
	assert(idx >= 0 && idx <= length);
	/*Node* cur = head;
	if (length == 1)
	{
		head = tail = nullptr;
	}
	else
	{
		Node* prev = nullptr;
		while (idx--)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		if (idx == length - 1)
		{
			tail = prev;
		}
	}
	delete cur;
	length--;*/

	if (length <= 1 || idx == 1)
	{
		delete_front();
	}
	else if (idx == length)
	{
		delete_back();
	}
	else
	{
		Node* temp = getNth(idx - 1);
		Node* deleteTemp = temp->next;
		temp->next = deleteTemp->next;
		delete deleteTemp;
		length--;
	}
}

void LinkedList::delete_value(int val)
{
	Node* temp = head;
	int cnt = 0;
	while (temp != nullptr)
	{
		cnt++;
		if (temp->data == val) {
			temp = temp->next;
			delete_nth(cnt);
			cnt--;
		}
		else
		{
			temp = temp->next;
		}
	}
}

void LinkedList::delete_withKey(int key)
{
	Node* temp = head;
	int cnt = 0;
	while (temp != nullptr)
	{
		cnt++;
		if (temp->data == key) {
			break;
		}
		temp = temp->next;
	}
	delete_nth(cnt);
}

void LinkedList::swap_pairs()
{
	/*Node* firstNode = head;
	Node* secNode = head->next;
	while (secNode)
	{
		swap(firstNode->data, secNode->data);
		firstNode = firstNode->next->next;
		if (!firstNode)
		{
			break;
		}
		secNode = secNode->next->next;
	}*/

	Node* cur = head;
	while (cur)
	{
		if (cur->next)
		{
			swap(cur->data, cur->next->data);
			cur = cur->next;
		}
		cur = cur->next;
	}
}

void LinkedList::reverse()
{
	Node* temp = head;
	Node* newTail = head;
	while (head != tail)
	{
		head = head->next;
		temp->next = tail->next;
		tail->next = temp;
		temp = head;
	}
	tail = newTail;
}

void LinkedList::delete_evenPos()
{
	int cnt = 2;
	while (cnt <= length)
	{
		delete_nth(cnt);
		cnt++;
	}
}

void LinkedList::insert_sorted(int value)
{
	if (length == 0 || value <= head->data)
	{
		insert_front(value);
	}
	else if (tail->data <= value)
	{
		append(value);
	}
	else
	{
		Node* newNode = new Node(value);
		Node* temp = head;
		while (temp->next != nullptr && value > temp->next->data)
		{
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		length++;
	}
}

void LinkedList::swap_headandTail()
{
	if (length <= 1)
	{
		return;
	}
	if (length == 2)
	{
		tail->next = head;
		head->next = nullptr;
		head = tail;
		tail = tail->next;
	}
	else
	{
		Node* temp = getNth(length - 1);
		tail->next = head->next;
		temp->next = head;
		head->next = nullptr;
		head = tail;
		tail = temp->next;
	}
}

void LinkedList::leftRotate(int steps)
{
	/*if (length <= 1)
	{
		return;
	}

	Node* temp = head;
	for (int k = steps % length; k > 0; k--)
	{
		head = head->next;
		tail->next = temp;
		temp->next = nullptr;
		tail = temp;
		temp = head;
	}*/

	if (length <= 0 || (steps % length) == 0)
	{
		return;
	}
	Node* temp = getNth(steps % length);
	tail->next = head;
	head = temp->next;
	temp->next = nullptr;
	tail = temp;

}

void LinkedList::removeDuplicates()
{
	Node* temp1 = head;
	while (temp1)
	{
		int cnt = 1;
		Node* temp2 = head;
		while (temp2)
		{
			if (temp1 != temp2)
			{
				cnt++;
				if (temp1->data == temp2->data)
				{
					temp2 = temp2->next;
					delete_nth(cnt);
					cnt--;
				}
				else
				{
					temp2 = temp2->next;
				}
			}
			else
			{
				temp2 = temp2->next;
			}
		}
		temp1 = temp1->next;
	}

	/*LinkedList list;
	Node* temp = head;
	while (temp)
	{
		cout << 1 << endl;
		for (Node* i = list.head; i ;i = i->next)
		{
			if (temp->data == i->data)
			{
				cout << 2 << endl;
				temp = temp->next;
				continue;
			}
		}
		cout << 3 << endl;
		list.append(temp->data);
		temp = temp->next;
	}
	cout << 4 << endl;
	head = list.head;
	tail = list.tail;
	length = list.length;
	cout << head->data << ' ' << head->next->data << ' ' << tail->data << ' ' << length << endl;*/
}

void LinkedList::removeLastKey(int key)
{
	int pos = -1;
	int cnt = 1;
	Node* temp = head;
	while (temp)
	{
		if (temp->data == key) {
			pos = cnt;
		}
		cnt++;
		temp = temp->next;
	}
	if (pos != -1)
	{
		delete_nth(pos);
	}
}

void LinkedList::movetoBack(int key)
{
	/*int cnt = 1;
	int len = length;
	Node* temp = head;
	while (len)
	{
		if (temp->data == key) {
			append(temp->data);
			temp = temp->next;
			delete_nth(cnt);
			cnt--;
		}
		else
		{
			temp = temp->next;
		}
		cnt++;
		len--;
	}*/

	if (length <= 1)
	{
		return;
	}
	int len = length;
	for (Node* cur = head, *prv = nullptr; len--;)
	{
		if (cur->data == key)
		{
			Node* next = cur->next;
			tail->next = cur;
			if (prv)
			{
				prv->next = next;
			}
			else
			{
				head = next;
			}
			tail = cur;
			tail->next = nullptr;
			cur = next;
		}
		else
		{
			prv = cur;
			cur = cur->next;
		}
	}
}

int LinkedList::max(Node* head , bool is_first_call) {		// O(n) time - O(n) memory
		// It is tricky to have function name same as standard
		// use std for standard and this-> for the class for clarity
	if (is_first_call)
		return this->max(this->head, false);

	if (head == nullptr)
		return INT_MIN;		// initial min value
	return std::max(head->data, this->max(head->next, false));
}

LinkedList::~LinkedList()
{
	while (head != nullptr)
	{
		Node* temp_head = head;
		head = head->next;
		delete temp_head;
	}
	length = 0;
}




