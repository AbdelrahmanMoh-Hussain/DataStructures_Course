#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
class MaxHeap
{
private:
	int* array;
	int size;
	int capacity = 10000;
public:
	MaxHeap(const vector<int>& v);
	void push(int value);
	int top();
	bool isEmpty();
	void pop();

private:
	int left(int node);
	int right(int node);
	int parent(int node);
	void heapifyUp(int node);
	void heapifyDown(int parentIndex);
	void createHeap();
};

