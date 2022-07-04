// DS_Course.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	Vector v(10);
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	v.insert(0, 5);
	//cout << "removed item: " << v.remove(1) << endl;
	//cout << "Position is : " << v.find_transposition(2) << endl;
	v.right_rotation(2);

	v.print();
}
