#pragma once
#include "BinaryHeap.h"
class KthSmallestNum
{
private:
	int k;
	int size = 0;
	BinaryHeap heap;

public:
	KthSmallestNum(int k): k(k){}
	int next(int newItem) {
		if (size < k) 
		{
			heap.push(newItem);
			return heap.array[size - 1];
		}
		else
		{
			if (newItem >= heap.array[k])
			{
				return heap.array[k];
			}
			heap.push(newItem);
			return heap.array[k];
		}
	}
};

