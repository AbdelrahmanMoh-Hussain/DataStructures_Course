#pragma once
#include "ArrayLinkedList.h"
class MatrixNode {
public:
	ArrayLinkedList row;
	int idx;
	MatrixNode* next;
	MatrixNode* prev;

	MatrixNode(ArrayLinkedList row, int idx);
};

class SparseMatrix
{
private:
	MatrixNode* head;
	MatrixNode* tail;
	int rowLength;
	int length;

public:
	SparseMatrix(int length, int rowLength);
	void setValue(int value, int rowIdx, int colIdx);
	int getValue(int rowIdx, int colIdx);
	void printNonZero();
	void print();
	void add(SparseMatrix other);
};

