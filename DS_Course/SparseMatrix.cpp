#include "SparseMatrix.h"
#include <iostream>
#include <assert.h>
using namespace std;

MatrixNode::MatrixNode(ArrayLinkedList row, int idx) 
{
	this->row = row;
	this->idx = idx;
	next = prev = nullptr;
}

SparseMatrix::SparseMatrix(int length, int rowLength)
{
	this->rowLength = rowLength;
	this->length = length;
	head = tail = nullptr;
}

void SparseMatrix::setValue(int value, int rowIdx, int colIdx)
{
	assert(rowIdx < length);

	if (head)
	{
		MatrixNode* temp = head;
		while (temp)
		{
			if (temp->idx == rowIdx)
			{
				temp->row.setValue(value, colIdx);
				return;
			}
			temp = temp->next;
		}
	}


	ArrayLinkedList rowArray(rowLength);
	rowArray.setValue(value, colIdx);
	MatrixNode* newNode = new MatrixNode(rowArray, rowIdx);
	if (!head)
	{
		head = tail = newNode;
	}
	else if (rowIdx <= head->idx)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else if (rowIdx >= tail->idx) {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	else if (rowIdx > head->idx && rowIdx < tail->idx)
	{
		MatrixNode* temp = head;
		while (temp->next != nullptr)
		{
			if (temp->next->idx > rowIdx)
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
}

int SparseMatrix::getValue(int rowIdx, int colIdx)
{
	MatrixNode* temp = head;
	while (temp)
	{
		if (temp->idx == rowIdx)
		{
			return temp->row.getValue(colIdx);
		}
		temp = temp->next;
	}
	return -1;
}

void SparseMatrix::printNonZero()
{
	MatrixNode* temp = head;
	while (temp)
	{
		temp->row.printNonZero();
		temp = temp->next;
	}
}

void SparseMatrix::print()
{
	MatrixNode* temp = head;
	for (int i = 0; i < length; i++)
	{
		if (temp && temp->idx == i)
		{
			temp->row.print();
			temp = temp->next;
			continue;
		}
		
		for (int j = 0; j < rowLength; j++)
		{
			cout << 0 << ' ';
		}
		cout << endl;
	}
}

void SparseMatrix::add(SparseMatrix other)
{
	MatrixNode* tempOther = other.head;
	while (tempOther)
	{
		MatrixNode* temp = head;
		bool foundIdx = false;
		while (temp)
		{
			if (temp->idx == tempOther->idx)
			{
				temp->row.add(tempOther->row);
				foundIdx = true;
				break;
			}
			temp = temp->next;
		}
		if (!foundIdx)
		{
			Node* tempRow = tempOther->row.head;
			while (tempRow)
			{
				this->setValue(tempRow->data, tempOther->idx, tempRow->idx);
				tempRow = tempRow->next;
			}
		}
		tempOther = tempOther->next;
	}
}
