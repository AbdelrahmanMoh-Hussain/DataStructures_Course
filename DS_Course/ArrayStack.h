#pragma once
#include<iostream>
using namespace std;


class ArrayStack
{
private:
	int* arr;
	int size;
	int elements;

private:
	void expand();

public:
	ArrayStack(int size);
	void push(int value);
	void pop();
	int peek();
	bool isFull();
	bool isEmpty();
	void display();
	void display2();
	void clear();

	//Easy-Mid Homework
	string reverseSubword(string line);
	int reverseNum(int num);
	bool isValid(string str);
	void removeDupl(string str);

	//Mid-Hard Homework
	void insertBottom(int value);
};

