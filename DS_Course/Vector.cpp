#include "Vector.h"
#include <iostream>
#include <algorithm>
#include <assert.h>

Vector::Vector(int size) : size(size) {
	if (size < 0)
	{
		this->size = 1;
	}
	arr = new int[size] {};
}

int Vector::get(int idx) {
	assert(idx >= 0 && idx < size);
	return arr[idx];
}

void Vector::set(int idx, int val) {
	assert(idx >= 0 && idx < size);
	arr[idx] = val;
}

void Vector::print() {
	for (int i = 0; i < elements; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

int Vector::find(int val) {
	for (int i = 0; i < elements; i++)
	{
		if (arr[i] == val)
		{
			return i;
		}
	}
	return -1;
}

int Vector::getFront() {
	return arr[0];
}

int Vector::getBack() {
	return arr[size - 1];
}

void Vector::push_back(int val) {
	if (elements == size)
	{
		expand();
	}
	arr[elements] = val;
	elements++;
}

void Vector::push_front(int val) {
	arr[size] = val;
}

void Vector::expand() {
	size *= 2;
	int* a = new int[size];
	for (int i = 0; i < elements; i++)
	{
		a[i] = arr[i];
	}
	std::swap(a, arr);
	delete[] a;
}

void Vector::insert(int idx, int val) {
	assert(idx >= 0 && idx < size);

	if (elements == size)
	{
		expand();
	}

	if (elements == 0)
	{
		push_back(val);
	}
	else
	{
		for (int i = elements; i > idx; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[idx] = val;
		elements++;
	}
}

void Vector::right_rotation()
{
	/*int pos = elements - 1;
	elements--;
	insert(0, arr[pos]);*/

	int val = arr[elements - 1];
	for (int i = elements - 1; i > 0; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = val;
}

void Vector::right_rotation(int steps)
{
	steps %= elements;
	while (steps--)
	{
		right_rotation();
	}


	/*int s = elements - steps;
	for (int i = 0; i < elements - steps; i++)
	{
		push_back(arr[i]);
	}
	for (int i = s; i < elements; i++)
	{
		arr[i - s] = arr[i];
	}
	elements -= s;*/

	/*int* a = new int[size]();
	for (int i = 0; i < elements - steps; i++) 
	{
		a[i] = arr[i];
	}
	for (int i = 0; i + steps  < elements; i++)
	{
		arr[i] = arr[i + steps];
	}
	for (int i = steps; i < elements; i++)
	{
		arr[i] = a[i - steps];
	}*/
	/*for (int i = elements - 1; i - steps >= 0; i--)
	{
		arr[i] = arr[i - steps];
	}*/
}

void Vector::left_rotation()
{
	int val = arr[0];
	for (int i = 0; i < elements - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[elements - 1] = val;
}

int Vector::remove(int idx)
{
	assert(elements != 0);
	assert(idx >= 0 && idx < elements);

	int val = arr[idx];
	for (int i = idx; i < elements; i++)
	{
		arr[i] = arr[i + 1];
	}
	elements--;
	return val;
}

int Vector::find_transposition(int val)
{
	for (int i = 0; i < elements; i++)
	{
		if (arr[i] == val)
		{
			std::swap(arr[i], arr[i - 1]);
			return i;
		}
	}
	return -1;
}

Vector::~Vector() {
	delete[] arr;
	arr = nullptr;
}