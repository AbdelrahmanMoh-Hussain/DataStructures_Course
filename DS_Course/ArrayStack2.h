#pragma once
class ArrayStack2
{
private:
	int* arr;
	int size;
	int added_elements;

private:
	void shiftRight(int steps);
	void shiftLeft(int steps);

public:
	ArrayStack2(int size);
	bool push(int value);
	bool pop();
	bool peek();
};

