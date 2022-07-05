#pragma once
class Vector
{
private:
	int size = 0;
	int elements = 0;
	int* arr = nullptr;

	void expand();

public:
	Vector(int size);
	int get(int idx);
	void set(int idx, int val);
	void print();
	int find(int val);
	int getFront();
	int getBack();
	void push_back(int val);
	void push_front(int val);
	void insert(int idx, int val); 

	//Vector Homework (5 Medium Challenges)
	/*--------------------------------*/
	void right_rotation();
	void right_rotation(int);
	void left_rotation();
	int remove(int idx);
	int find_transposition(int val);
	/*-------------------------------*/

	~Vector();
};

