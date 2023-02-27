#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
class BinaryHeap
{
public:
	int* array;
	int size;
	int capacity = 10000;

public:
	BinaryHeap();
	BinaryHeap(const vector<int>& v);
	void push(int value);
	int top();
	bool isEmpty();
	void removeRoot();
	void pop();
	~BinaryHeap();

	//Easy Homework 1
	void printLessThan(int val, int parIndex = 0);
	bool isHeap(int* p, int n);
	void heapSort(int* p, int n);

private:
	int left(int node);
	int right(int node);
	int parent(int node);
	void heapifyUp(int node);
	void heapifyDown(int parentIndex);
	void createHeap();
};

