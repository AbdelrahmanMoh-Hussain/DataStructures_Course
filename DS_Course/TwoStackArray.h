#pragma once
class TwoStackArray
{
private:
	int* arr;
	int size;
	int firstStackElements;
	int secondStackElements;

public:
	TwoStackArray(int size);
	void push(int id, int value);
	int pop(int id);
	void display();
};

