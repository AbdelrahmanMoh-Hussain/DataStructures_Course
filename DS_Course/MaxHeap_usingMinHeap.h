#pragma once
#include "BinaryHeap.h"
#include <vector>
using namespace std;

class MaxHeap_usingMinHeap
{
private:
	BinaryHeap minHeap;

	vector<int> multi_neg1(const vector<int>& v) {
		vector<int> res = v;
		for (int i = 0; i < v.size(); i++)
		{
			res[i] *= -1;
		}
		return res;
	}
public:
	MaxHeap_usingMinHeap() {}
	MaxHeap_usingMinHeap(const vector<int>& v) : minHeap(multi_neg1(v)){}
	int top() {
		return -minHeap.top();
	}
	void push(int value) {
		minHeap.push(-value);
	}
	void pop() {
		minHeap.pop();
	}
	bool isEmpty() {
		return minHeap.isEmpty();
	}
};

